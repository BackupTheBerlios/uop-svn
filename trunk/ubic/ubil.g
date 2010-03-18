///####################################################################
///####################### Inicio da gramatica ########################
///####################################################################

///#################
///## File Struct ##
///#################

grammar ubil;

options
{
	k         = 8; // TODO: corrigir as regras para eliminar esta opcao
	backtrack = true;
	memoize   = true;
	language  = C;
}

@lexer::preinclude
{
	#define ANTLR3_HUGE
}
@parser::preinclude
{
	#define	ANTLR3_HUGE
}

@lexer::header
{
	#define	ANTLR3_INLINE_INPUT_ASCII
	extern "C++" {
		#include <string>
	}
}

@lexer::members
{
	static ANTLR3_BOOLEAN enumIsKeyword = ANTLR3_TRUE;
}

@header {
	extern "C++" {
	#include <fstream>
	#include "AssemblyDefinition.hpp"
	#include "LibuvmDefs.hpp"
	#include "SymbolTable.hpp"
	#include "Tools.hpp"
	#include "UbicDefs.hpp"
	CAssemblyDefinition* get_asm_def();
	}
	#include <stdlib.h>
}

@members {
	CAssemblyDefinition asmDef;
	CEntityDefinition *entityDef = NULL;
	CMethodDefinition *methodDef = NULL;
	#define GETTEXT(token) std::string((const char*)(token->getText(token))->chars)

	CAssemblyDefinition* get_asm_def() {
		return &asmDef;
	}
}

@after {
}

// starting point for parsing a ubil file
////----------
	compilation_unit [SParamOptions options]
////----------
	:	(import_declaration)*
		(entity_definition)+
		EOF
		{
//         if (errorCount > 0) {
//            return;
//         }
		}
   ;

////----------
	import_declaration
////----------
	:	'import' id1=IDENTIFIER {asmDef.addImport(GETTEXT($id1));} ('.' id2=IDENTIFIER {asmDef.addImport(GETTEXT($id2));} )* ';'
	;

////----------
	entity_definition
////----------
@init{
}
	:  'entity' IDENTIFIER
		{ entityDef = asmDef.addEntity(GETTEXT($IDENTIFIER)); }
		(entity_options)?
		(supported_contexts)?
		(property_definition)*
		(method_definition|service_definition)+
		'end'
	;

////----------
	entity_options
////----------
	:	'[' opt1=IDENTIFIER {entityDef->setOption(GETTEXT($opt1));}
			( ',' opt2=IDENTIFIER {entityDef->setOption(GETTEXT($opt2));} )*
		']'
	;

////----------
	supported_contexts
////----------
	:	'when'       { methodDef = entityDef->addMethod(PrivateVisibility, "__when"); }
		'(' expr ')' { methodDef->addInstruction(RET_OPCODE); }
	;

///----------
   property_definition
///----------
	:	('prop'|'property') type IDENTIFIER ';'
		{
			entityDef->addProperty(PublicVisibility, $type.iret, (const char*)$IDENTIFIER.text->chars);
		}
//		(
//			'=' expr
//			{
//				methodDef->addInstruction(STVAR_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER)));
//			}
//		)?
	;


///----------
   type returns [LiteralType iret, std::string sret] :
///----------
		'int'      { $iret = IntegerType;  $sret = "int";      }
	|	'real'     { $iret = RealType;     $sret = "real";     }
	|	'string'   { $iret = StringType;   $sret = "string";   }
	|	'bool'     { $iret = BooleanType;  $sret = "bool";     }
	|	'element'  { $iret = ElementType;  $sret = "element";  }
	|	'userdata' { $iret = UserdataType; $sret = "userdata"; }
	|	'table'    { $iret = TableType;    $sret = "table";    }
	|	'tuple'    { $iret = TupleType;    $sret = "tuple";    }
	;

///----------
   method_definition
///----------
   :  'method' ('public'|'private')? IDENTIFIER
      {
         // TODO: tratar escopo (public ou private)
         methodDef = entityDef->addMethod(PublicVisibility, (const char*)$IDENTIFIER.text->chars);
      }
      '(' (parameters_definition)? ')'
      (returns_definition)?
      (var_definition)*
      code_block[-1, -1]
      'end'
      {
         if (std::string((const char*)$IDENTIFIER.text->chars) == "constructor" && entityDef->getName() == "start") {
            methodDef->addInstruction(EXIT_OPCODE);
         } else {
            if (methodDef->getLastInstruction()->_opcode != RET_OPCODE || methodDef->hasNextInstructionLabel()) {
            	methodDef->addInstruction(RET_OPCODE);
            }
         }
         methodDef->resolveLabels();
      }
   ;

///----------
   service_definition
///----------
	:	'service' IDENTIFIER
		{
			methodDef = entityDef->addMethod(PublicVisibility, (const char*)$IDENTIFIER.text->chars);
		}
		'(' (parameters_definition)? ')'
		(returns_definition)?
		(var_definition)*
		code_block[-1, -1]
		'end'
		{
			if (methodDef->getLastInstruction()->_opcode != RET_OPCODE || methodDef->hasNextInstructionLabel()) {
				methodDef->addInstruction(RET_OPCODE);
			}
			methodDef->resolveLabels();
		}
	;

///----------
   parameters_definition
///----------
   :  type1=type id1=IDENTIFIER
      {
         methodDef->addParameter($type1.iret, (const char*) $id1.text->chars);
      }
      ( ',' type2=type id2=IDENTIFIER
         {
            methodDef->addParameter($type2.iret, (const char*) $id2.text->chars);
         }
      )*
   ;

///----------
   returns_definition
///----------
   :  '['
      type1=type
      {
         methodDef->addResult($type1.iret);
      }
      ( ',' type2=type
         {
            methodDef->addResult($type2.iret);
         }
      )*
      ']'
   ;

///--------------
   var_definition
///--------------
   :  ('var'|'variable') type IDENTIFIER
      {
         methodDef->addLocalVar($type.iret, (const char*)$IDENTIFIER.text->chars);
      }
      (
         '=' expr
         {
            methodDef->addInstruction(STVAR_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER)));
         }
      )?
      ';'
   ;

///----------
   code_block [int continue_label, int break_label]
///----------
   :  (statement[continue_label, break_label])*
   ;

///----------
   statement [int continue_label, int break_label]
///----------
	:	(loop_control[continue_label, break_label] ';') | (simple_statement ';') | block_statement[continue_label, break_label]
	;

////----------------
	loop_control [int continue_label, int break_label]
////----------------
	:	'break'    { methodDef->addInstruction(JMP_OPCODE, break_label); }
	|	'continue' { methodDef->addInstruction(JMP_OPCODE, continue_label); }
	;

////---------
	simple_statement
////---------
	:	assignment_statement|return_statement|method_invocation|context_interation
	;

////---------
	block_statement [int continue_label, int break_label]
////---------
	:	if_statement[continue_label, break_label] | iteration_statement[continue_label, break_label]
	;

///----------
   assignment_statement
///----------
   :  var_assignment_statement | context_assignment_statement | table_assignment_statement | event_assignment_statement | expr
   ;

///----------
   var_assignment_statement
///----------
@declarations
{
   std::vector<std::string> idList;
}
   :  Id1=IDENTIFIER { idList.push_back(GETTEXT($Id1)); }
      (
         ',' Id2=IDENTIFIER { idList.push_back(GETTEXT($Id2)); }
      )*
      '=' expr
      {
         for(std::vector<std::string>::iterator id = idList.begin(); id != idList.end(); id++) {
            methodDef->addStoreInstruction(*id, false);
         }
      }
   ;

///----------
   context_assignment_statement
///----------
   :  context '.' IDENTIFIER '=' expr
      { methodDef->addInstruction(STCONTEXTI_OPCODE, entityDef->getSymbolIndex($context.value + "." + GETTEXT($IDENTIFIER), StringType)); }
   ;

//--------------------------------------
   table_assignment_statement :
//--------------------------------------
	IDENTIFIER { methodDef->addLoadInstruction(GETTEXT($IDENTIFIER), false); }
	'[' expr ']' '=' expr
	{ methodDef->addInstruction(STTAB_OPCODE); }
	;

// //--------------------------------------
//    table_assignment_statement :
// //--------------------------------------
// 		IDENTIFIER '[' expr { methodDef->addInstruction(LDTAB_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); } ',' expr ']' // '=' expr
// { methodDef->addInstruction(STTAB_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); }
// 	|	IDENTIFIER '[' expr ']' '=' expr
// { methodDef->addInstruction(STTAB_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); }
// 	;

// TODO: Seria interessante colocar as derivacoes bem na esquerda (coluna 1) ???

///----------
   event_assignment_statement
///----------
	:	context_join_event
	|	element_event_assignment_statement
	;

///----------
   element_event_assignment_statement
///----------
	:	element=IDENTIFIER '.' event=IDENTIFIER '+=' method=IDENTIFIER
		{
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($event), StringType));
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($method), StringType));
			methodDef->addInstruction(BELEMENTEV_OPCODE, methodDef->findLocalVarDefinition(GETTEXT($element))->_index);
		}
	;

///----------
   context_join_event
///----------
	:	context '.' data=IDENTIFIER '.' event=IDENTIFIER '+=' method=IDENTIFIER
		{
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($event), StringType));
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($method), StringType));
			methodDef->addInstruction(BCONTEXTIEV_OPCODE, entityDef->getSymbolIndex($context.value + "." + GETTEXT($data), StringType));
		}
	;

///----------
   context_interation
///----------
   :  context_invocation
   |  data_context_interation
   |  data_context_event
   |  service_context_interation
   ;

///----------
   context_invocation
///----------
@declarations
{
   std::string serviceName;
}
   :  '{' expr '}' '.' 'mjoin' '(' argument ')'  { methodDef->addInstruction(MJOIN_OPCODE);  }
   |  '{' expr '}' '.' 'mleave' '(' argument ')' { methodDef->addInstruction(MLEAVE_OPCODE); }
   ;

///----------
   data_context_interation
///----------
   : '{' expr '}' '.' IDENTIFIER
      '(' (arg1=argument_list '=>' arg2=argument_list)? ')'
      {
         if (GETTEXT($IDENTIFIER) == "cpublish") {
            methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($arg1.args), IntegerType));
            methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($arg2.args), IntegerType));
            methodDef->addInstruction(CPUBLISH_OPCODE);
         }
      }
   ;

///----------
   data_context_event
///----------
	:	'{' expr '}' '.' event=IDENTIFIER '+=' method=IDENTIFIER
		{
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($event), StringType));
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($method), StringType));
			methodDef->addInstruction(BCONTEXTEV_OPCODE); // ou passar evento como um argumento do opcode ???
		}
	;


///----------
   service_context_interation
///----------
@declarations
{
   std::string serviceName;
}
	:	'{' expr '}' '.' action=IDENTIFIER
		'(' (args=argument_list)? ')'
		{
			if (GETTEXT($action) == "spublish") {
				methodDef->addInstruction(SPUBLISH_OPCODE);
			} else if (GETTEXT($action) == "sremove") {
				methodDef->addInstruction(SREM_OPCODE);
			} else if (GETTEXT($action) == "srun") {
				methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($args.args - 1), IntegerType));
				methodDef->addInstruction(SRUN_OPCODE);
			} else {
				std::cerr << "Acao nao definida !!!" << std::endl;
			}
		}
	;



//----------
   rcontext
///----------
	:	'{' expr '}' '.' IDENTIFIER ( '(' (argument_list)? ')' )?
	{
		// Metodos referentes aos conteudos
		if (GETTEXT($IDENTIFIER) == "cget") {
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
			methodDef->addInstruction(CGET_OPCODE);
		} else if (GETTEXT($IDENTIFIER) == "cfind") {
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
			methodDef->addInstruction(CFIND_OPCODE);
		} else if (GETTEXT($IDENTIFIER) == "cfindnb") {
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
			methodDef->addInstruction(CFINDNB_OPCODE);
		} else if (GETTEXT($IDENTIFIER) == "cgetnb") {
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
			methodDef->addInstruction(CGETNB_OPCODE);
		} else if (GETTEXT($IDENTIFIER) == "clist") {
			methodDef->addInstruction(CLIST_OPCODE);
		// Metodos referentes aos elementos
		} else if (GETTEXT($IDENTIFIER) == "mlist") {
			methodDef->addInstruction(MLIST_OPCODE);
		// Metodos referentes aos servicos
		} else if (GETTEXT($IDENTIFIER) == "slist") {
			methodDef->addInstruction(SLIST_OPCODE);
		} else if(GETTEXT($IDENTIFIER) == "srun") {
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args - 1), IntegerType));
			methodDef->addInstruction(SRUN_OPCODE);
		} else if (GETTEXT($IDENTIFIER) == "spublish") {
			methodDef->addInstruction(SPUBLISH_OPCODE);
		} else if (GETTEXT($IDENTIFIER) == "sremove") {
			methodDef->addInstruction(SREM_OPCODE);
		} else {
			std::cerr << "Undefined context method: " << GETTEXT($IDENTIFIER) << std::endl;
		}
	}
	;


//--------------------------------------
   rtable :
//--------------------------------------
		IDENTIFIER '.' 'size' '(' ')'
		{ methodDef->addLoadInstruction(GETTEXT($IDENTIFIER), false); methodDef->addInstruction(TABSIZE_OPCODE); }
	|	IDENTIFIER { methodDef->addLoadInstruction(GETTEXT($IDENTIFIER), false); }
		'[' expr ']'
		{ methodDef->addInstruction(LDTAB_OPCODE); }
	;

//--------------------------------------
   rtuple :
//--------------------------------------
		IDENTIFIER '.' 'keys'   '[' expr ']' { methodDef->addInstruction(LDTUPLEK_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); }
	|	IDENTIFIER '.' 'results' '[' expr ']' { methodDef->addInstruction(LDTUPLER_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); }
	;

///----------
   return_statement
///----------
@declarations
{
   uint number = 0;
}
   :  'return'
      (
         expr
         {
            methodDef->addInstruction(STRESULT_OPCODE, number++);
         }
         ( ',' expr
            {
               methodDef->addInstruction(STRESULT_OPCODE, number++);
            }
         )*
      )?
      {
          methodDef->addInstruction(RET_OPCODE);
      }
   ;

///----------
   if_statement [int continue_label, int break_label]
///----------
@declarations
{
	int elseLabel;
	int nextCommandLabel;
}
   : 'if' '(' expr ')'
      {
         elseLabel        = methodDef->getNewLabel();
         nextCommandLabel = methodDef->getNewLabel();
      }
      { methodDef->addInstruction(IFNOT_OPCODE, elseLabel); }
      code_block[continue_label, break_label]
      { methodDef->addInstruction(JMP_OPCODE, nextCommandLabel); }
      { methodDef->setNextInstructionLabel(elseLabel); }
      ('else' code_block[continue_label, break_label])? 'end'
      { methodDef->setNextInstructionLabel(nextCommandLabel); }
   ;

///----------
   iteration_statement [int continue_label, int break_label]
///----------
	:	for_statement
	|	while_statement
	|	repeat_statement
	|	foreach_statement
  // o do..while nao funciona pq o while eh identificado como uma nova sentenca while dentro do do..while...
  // talvez agora que tenho ";" no final dos comandos funcione...
   ;

///----------
   for_statement
///----------
@declarations
{
	int testLabel;
	int stepLabel;
	int nextCommandLabel;
	int blockLabel;
}
   :  { testLabel = methodDef->getNewLabel(); stepLabel = methodDef->getNewLabel(); nextCommandLabel = methodDef->getNewLabel(); blockLabel = methodDef->getNewLabel(); }
      'for'
      '('
         assignment_statement ';'
         { methodDef->setNextInstructionLabel(testLabel); }
         expr ';'
         { methodDef->addInstruction(IFNOT_OPCODE, nextCommandLabel);
          methodDef->addInstruction(JMP_OPCODE, blockLabel);
          methodDef->setNextInstructionLabel(stepLabel); }
         assignment_statement
       { methodDef->addInstruction(JMP_OPCODE, testLabel); }
      ')'
      { methodDef->setNextInstructionLabel(blockLabel); }
      code_block[stepLabel, nextCommandLabel]
      { methodDef->addInstruction(JMP_OPCODE, stepLabel); }
      'end'
      { methodDef->setNextInstructionLabel(nextCommandLabel); }
   ;

///----------
   while_statement
///----------
@declarations
{
	int testLabel;
	int nextCommandLabel;
}
   :  {
         testLabel        = methodDef->getNewLabel();
	 nextCommandLabel = methodDef->getNewLabel();
      }
      {  methodDef->setNextInstructionLabel(testLabel); }
      'while' '(' expr ')'
      { methodDef->addInstruction(IFNOT_OPCODE, nextCommandLabel); }
      code_block[testLabel, nextCommandLabel]
      'end'
      { methodDef->addInstruction(JMP_OPCODE, testLabel); }
      { methodDef->setNextInstructionLabel(nextCommandLabel); }
   ;

///----------
   repeat_statement
///----------
@declarations
{
	int startLabel;
	int nextCommandLabel;
}
	:	'repeat'
		{ startLabel = methodDef->getNewLabel(); nextCommandLabel = methodDef->getNewLabel(); }
		{ methodDef->setNextInstructionLabel(startLabel); }
		code_block[startLabel, nextCommandLabel]
		'until' '(' expr ')'
		{ methodDef->addInstruction(IFNOT_OPCODE, startLabel); }
		{ methodDef->setNextInstructionLabel(nextCommandLabel); }
   ;

///----------
   foreach_statement
///----------
   :  'foreach' '(' IDENTIFIER 'in' rcontext ')'
      code_block[-1, -1]
      'end'
   ;

///----------
   method_invocation
///----------
   :  local_method_invocation
   |  element_method_invocation
   ;

///----------
   local_method_invocation
///----------
   :  methodId=IDENTIFIER
      '('
         (argument_list
         )?
      ')'
      {
            methodDef->addInstruction(LDSELF_OPCODE);
            methodDef->addInstruction(MCALL_OPCODE, entityDef->getSymbolIndex(GETTEXT($methodId), StringType));
      }
   ;

///----------
   element_method_invocation
///----------
   :  elementId=IDENTIFIER '.' methodId=IDENTIFIER '(' (argument_list)? ')'
      {
         // O if abaixo deveria testar se elementId realmente eh um elemento, ou se nao eh uma lib...
         if (GETTEXT($methodId) == "new") {
            methodDef->addInstruction(NEWELEM_OPCODE, entityDef->getSymbolIndex(GETTEXT($elementId), StringType));
         } else if (asmDef.isLibrary(GETTEXT($elementId))) {
            if (GETTEXT($methodId) == "writeln" || GETTEXT($methodId) == "write" || GETTEXT($methodId) == "mvwriteln" || GETTEXT($methodId) == "mvwrite" || GETTEXT($methodId) == "mvwwrite" || GETTEXT($methodId) == "mvwwriteln" || GETTEXT($methodId) == "wwriteln" || GETTEXT($methodId) == "wwrite") { // To forcando essa condicao para write e writelnln... com as bibliotecas ok, o mapeamento ira informar que writeln tem numero de argumentos variaveis...
               methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
            }
            methodDef->addInstruction(LCALL_OPCODE, entityDef->getSymbolIndex(GETTEXT($elementId) + "." + GETTEXT($methodId), StringType));
         } else if (GETTEXT($elementId) == "io") {
            if (GETTEXT($methodId) == "writeln" || GETTEXT($methodId) == "write") {
               methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
            }
            methodDef->addInstruction(LCALL_OPCODE, entityDef->getSymbolIndex(GETTEXT($elementId) + "." + GETTEXT($methodId), StringType));
         } else {
            methodDef->addLoadInstruction(GETTEXT($elementId), false);
            methodDef->addInstruction(MCALL_OPCODE, entityDef->getSymbolIndex(GETTEXT($methodId), StringType));
         }
      }
   ;

///----------
   argument_list returns [uint args]
///----------
   :  argument {$args++;} (',' argument {$args++;} )*
   ;

///----------
   argument
///----------
   :  expr
   |  literal
   |  'nil'          { methodDef->addInstruction(LDNIL_OPCODE); }
   ;

///----------
   literal
///----------
   :  IDENTIFIER     { methodDef->addLoadInstruction(GETTEXT($IDENTIFIER), false);  }
   |  INTEGER_LITERAL { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($INTEGER_LITERAL), IntegerType)); }
   |  REAL_LITERAL    { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($REAL_LITERAL),    RealType));    }
   |  STRING_LITERAL  { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($STRING_LITERAL),  StringType));  }
   |  BOOLEAN_LITERAL { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($BOOLEAN_LITERAL),  BooleanType));  }
   ;

///----------
   context_property
///----------
   :  context '.' IDENTIFIER
      { methodDef->addInstruction(LDCONTEXTI_OPCODE, entityDef->getSymbolIndex($context.value + "." + GETTEXT($IDENTIFIER), StringType)); }
   ;

///----------
   context returns [int teste, std::string value] // teste nao eh necessario... mas qdo so tem um parametro, antlr gera codigo para inicializar value como "NULL"
///----------
   :  'identity' { $value = "identity"; }
   |  'location' { $value = "location"; }
   |  'activity' { $value = "activity"; }
   |  'time'     { $value = "time";     }
   ;

///----------
   element_property
///----------
   : IDENTIFIER '.' IDENTIFIER
   ;





// ----------------------------- Expressoes ----------------------------------

////-------------------------
	expr
////-------------------------
  : expr_e
    (
	  'or' expr_e
      {methodDef->addInstruction(OR_OPCODE);}
	)*
  ;

expr_e
  : expr_bit_ou
    (
      'and' expr_bit_ou
      {methodDef->addInstruction(AND_OPCODE);}
    )*
  ;

expr_bit_ou
  : expr_bit_xou
    (
      '|' expr_bit_xou
    )*
  ;

expr_bit_xou
  : expr_bit_e
    (
      '~' expr_bit_e
    )*
  ;

expr_bit_e
  : expr_igual
    (
      '&' expr_igual
    )*
  ;

expr_igual
@init { OpcodeType opcode; }
  : expr_relacional
    (
      ( '==' {opcode=EQ_OPCODE;} | '<>' {opcode=NE_OPCODE;} )
      expr_relacional
      {methodDef->addInstruction(opcode);}
    )*
  ;

expr_relacional
@init { OpcodeType opcode; }
  : expr_ad
    (
      ( '>' {opcode=GT_OPCODE;} | '>=' {opcode=GE_OPCODE;} | '<' {opcode=LT_OPCODE;} | '<=' {opcode=LE_OPCODE;} )
      expr_ad
      {methodDef->addInstruction(opcode);}
    )*
  ;

expr_ad
@init { OpcodeType opcode; }
  : expr_multip
    (
      ( '+' {opcode = ADD_OPCODE;} | '-' {opcode = SUB_OPCODE;} )
      expr_multip
      {methodDef->addInstruction(opcode);}
    )*
  ;

expr_multip
@init { OpcodeType opcode; }
  : expr_unario
    (
      ( '/' {opcode=DIV_OPCODE;} | '*' {opcode=MUL_OPCODE;} | '%'{opcode=MOD_OPCODE;} )
      expr_unario
      {methodDef->addInstruction(opcode);}
    )*
  ;

//   ++ -- (posfixo)
//   ++ -- (prefixo)
//   + - (unaria)
//   ! ~ (nao logico e complemento)
//   mul div modulo
//   adicao sub
//   < <=
//   > >=
//   == !=
//   &&
//   ||
//   =
//   += -=
//   *= /= %=


expr_unario
  : ('+' | '-' | 'not')? expr_incdec_prefixo
  ;

expr_incdec_prefixo
	: ('++'|'--')? expr_incdec_posfixo
  ;

expr_incdec_posfixo
	: expr_elemento
	(
		'++'	{
					methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex("1", IntegerType));
					methodDef->addInstruction(ADD_OPCODE);
					methodDef->addStoreInstruction($expr_elemento.id, false);
				}
	|	'--'
	)?
  ;

expr_elemento returns [int x, std::string id]
  : method_invocation
  | IDENTIFIER     { methodDef->addLoadInstruction(GETTEXT($IDENTIFIER), false); $id = GETTEXT($IDENTIFIER); }
  | literal
  | context_property
  | element_property
  | rcontext
  | rtable
  | rtuple
  | '(' expr ')'
  ;


//$$$$$$$$$$$$$$$$$$$$$$


// LEXER

//HEX_LITERAL : '0' ('x'|'X') HexDigit+ IntegerTypeSuffix? ;

// TODO: desse jeito, o ubic nao interpreta "2 -5", mas sim "2 - 5"
INTEGER_LITERAL : ('-')? ('0'..'9')+ ;

//OctalLiteral : '0' ('0'..'7')+ IntegerTypeSuffix? ;

//fragment
//HexDigit : ('0'..'9'|'a'..'f'|'A'..'F') ;

//fragment
//IntegerTypeSuffix : ('l'|'L') ;

REAL_LITERAL
	:  ('-')? ('0'..'9')+ '.' ('0'..'9')+
   |  ('-')? '.' ('0'..'9')+
   ;

//fragment
//Exponent : ('e'|'E') ('+'|'-')? ('0'..'9')+ ;

//fragment
//FloatTypeSuffix : ('f'|'F'|'d'|'D') ;

CHARACTER_LITERAL
    :   '\'' ( ESCAPE_SEQUENCE | ~('\''|'\\') ) '\''
    ;


STRING_LITERAL
@after{
	// TODO: improve this
	std::string id = (const char*)GETTEXT()->chars;
	id = id.substr(1, id.length()-2);
	pANTLR3_STRING antlr_id = GETTEXT();
	antlr_id->set(antlr_id, id.c_str());
	SETTEXT(antlr_id);
}
	:  '"' ( ESCAPE_SEQUENCE | ~('\\'|'"') )* '"'
    ;

//STRING_LITERAL returns [const char* ret]
//    :  '"' ( ESCAPE_SEQUENCE | ~('\\'|'"') )* '"'
//    ;

BOOLEAN_LITERAL
   : 'true' | 'false'
   ;

fragment
ESCAPE_SEQUENCE
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
//    |   UnicodeEscape
//    |   OctalEscape
    ;

//fragment
//OctalEscape
//    :   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
//    |   '\\' ('0'..'7') ('0'..'7')
//    |   '\\' ('0'..'7')
//    ;

//fragment
//UnicodeEscape
//    :   '\\' 'u' HexDigit HexDigit HexDigit HexDigit
//    ;

//ENUM:	'enum' {if ( !enumIsKeyword ) $type=IDENTIFIER;}
//	;

IDENTIFIER
   :  ('_'|LETTER) (LETTER|DIGIT|'_')*
   ;


fragment
LETTER: 'a'..'z' ;

fragment
DIGIT : '0'..'9' ;

WS  :  (' '|'\r'|'\t'|'\u000C'|'\n') {$channel=HIDDEN;}
    ;

COMMENT
    :   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
    ;

LINE_COMMENT
    : '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    ;

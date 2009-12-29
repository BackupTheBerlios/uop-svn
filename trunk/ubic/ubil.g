///####################################################################
///####################### Inicio da gramatica ########################
///####################################################################

// DICAS COPIADOS DOS EXEMPLOS...
// printf("'\%s' is a type", $IDENTIFIER.text->chars);

//      {
//         printf("Metodo [\%s] ", $IDENTIFIER.text->chars);
//      }


//type_id
//    :   {isTypeName(ctx, LT(1)->getText(LT(1))->chars) }?   // Note how we reference using C directly
//    IDENTIFIER
// ...

//COMMENT
//    :   '/' '*' (options {greedy=false;} : . )* '*' '/'
//        {printf("found comment \%s\n",GETTEXT()->chars);}
//    ;


//poly
//@declarations
//{
//            pANTLR3_STRING c2;
//            pANTLR3_STRING e2;
//            int ci, ei;
//}
//    :   ^('+' poly poly)
//    |   ^(MULT INT ID)      -> INT
//    |   ^(MULT c=INT ^('^' ID e=INT))
//        {
//            // To get ourselves a new string, we just get a copy of the
//            // text of one of the tokens. When we override the text, it only changes this local copy and not the
//            // actual print stream. We need the strings anyway because we need to use their values. We could use
//            // $c.int, but then we would not have the advantage of the string to use, and anyway, our string has
//            // a method to convert to int anyway, which is what the \$int reference uses :-)
//            //
//            // Note that if there is any danger that the text has been changed with SETTEXT in the lexer, or
//            // was rewritten with new text by the parser, then we cannot use this trick as the text we get back
//            // will be a pointer to the pANTLR3_STRING that was used to set the text, rather than a new one created
//            // from the text stream.
//            //
//            // This allows you to either keep getting copies of the text in the input stream, or just get one copy
//            // and manipulate it with a local reference after that. Make sure you understand this if you are going to use
//            // the .text references... which you don't have to of course. If you are using C++ and want the
//            // standard template libraries or some other implementation , then write yourself a constructor that takes a
//            // token/tree/whatever and constructs the string itself like input->subString does.
//            //
//            c2 = $c.text;
//            e2 = $e.text;
//            ci = c2->toInt32(c2);
//            ei = e2->toInt32(e2);
//            c2->set8(c2, "");
//            c2->addi(c2, ci*ei);
//            e2->set8(e2, "");
//            e2->addi(e2, ei-1);
//        }


//COMMENT
//    :   '/' '*' (options {greedy=false;} : . )* '*' '/'
//        {printf("found comment \%s\n",GETTEXT()->chars);}
//    ;



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

// While you can implement your own character streams and so on, they
// normally call things like LA() via function pointers. In general you will
// be using one of the pre-supplied input streams and you can instruct the
// generated code to access the input pointers directly.
//
// For  8 bit inputs            : #define ANTLR3_INLINE_INPUT_ASCII
// For 16 bit UTF16/UCS2 inputs : #define ANTLR3_INLINE_INPUT_UTF16
//
// If your compiled recognizer might be given inputs from either of the sources
// or you have written your own character input stream, then do not define
// either of these.
//
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
//   CSymbolTable* symbolTable;
   #define GETTEXT(token) std::string((const char*)(token->getText(token))->chars)

//   symbolTable = new CSymbolTable();
//	char* getTest() { return "oi!!!"; }
	CAssemblyDefinition* get_asm_def() {
		return &asmDef;
    }
}

@after {
//   symbolTable = new CSymbolTable();
//	char* getTest2() { return "oi!!!"; }
}

// starting point for parsing a ubil file
///----------
   compilation_unit [SParamOptions options]
///----------
   :  (import_declaration)*
      (entity_definition)+
      EOF
      {
//         if (errorCount > 0) {
//            return;
//         }

      }
   ;

///----------
   import_declaration
///----------
   :  'import' id1=IDENTIFIER {asmDef.addImport(GETTEXT($id1));} ('.' id2=IDENTIFIER {asmDef.addImport(GETTEXT($id2));} )* ';'
   ;

///----------
   entity_definition
///----------
@init{
}
	:  'entity' IDENTIFIER
		{ entityDef = asmDef.addEntity(GETTEXT($IDENTIFIER)); }
		(entity_options)?
		(valid_context)?
		{
//			entityDef = asmDef.addEntity((const char*)$IDENTIFIER.text->chars);
//			entityDef->getSymbolIndex(GETTEXT($IDENTIFIER), StringType);
		 }
		(property_definition)*
		(method_definition|service_definition)+
		'end'
	;

///----------
   entity_options
///----------
	:	'[' opt1=IDENTIFIER {entityDef->setOption(GETTEXT($opt1));}
			( ',' opt2=IDENTIFIER {entityDef->setOption(GETTEXT($opt2));} )*
		']'
	;

///----------
   valid_context
///----------
	:	'when' { methodDef = entityDef->addMethod(PrivateVisibility, "__when"); } '(' expr ')' { methodDef->addInstruction(RET_OPCODE); }
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
      code_block
      'end'
      {
         if (std::string((const char*)$IDENTIFIER.text->chars) == "constructor" && entityDef->getName() == "start") {
            methodDef->addInstruction(STOP_OPCODE);
         } else {
            methodDef->addInstruction(RET_OPCODE);
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
		code_block
		'end'
		{
			methodDef->addInstruction(RET_OPCODE);
			methodDef->resolveLabels();
		}
   ;

///----------
   parameters_definition
///----------
   :  type1=type id1=IDENTIFIER
      {
         methodDef->addParameter($type1.iret, (const char*) $id1.text->chars);
//         methodDef->addParameter((const char*)$type1.text->chars, (const char*) $id1.text->chars);
      }
      ( ',' type2=type id2=IDENTIFIER
         {
            methodDef->addParameter($type2.iret, (const char*) $id2.text->chars);
//            methodDef->addParameter((const char*)$type2.text->chars, (const char*) $id2.text->chars);
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
   code_block
///----------
   :  (statement)*
   ;

///----------
   statement
///----------
	:	(simple_statement ';') | block_statement
	;

////---------
	simple_statement
////---------
	:	assignment_statement|return_statement|method_invocation|context_interation
	;

////---------
	block_statement
////---------
	:	if_statement|iteration_statement
	;

///----------
   assignment_statement
///----------
   :  var_assignment_statement | context_assignment_statement | table_assignment_statement | event_assignment_statement
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
		IDENTIFIER '[' expr { methodDef->addInstruction(LDTAB_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); } ',' expr ']' '=' expr
		{ methodDef->addInstruction(STTAB_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); }
	|	IDENTIFIER '[' expr ']' '=' expr
		{ methodDef->addInstruction(STTAB_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); }
	;

///----------
   event_assignment_statement
///----------
	:	context_bind_event
	|	element_event_assignment_statement
	;

///----------
   element_event_assignment_statement
///----------
	:	element=IDENTIFIER '.' event=IDENTIFIER '+=' method=IDENTIFIER
		{
//			methodDef->addLoadInstruction(GETTEXT($element), false);
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($event), StringType));
			methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($method), StringType));
			methodDef->addInstruction(BELEMENTEV_OPCODE, methodDef->findLocalVarDefinition(GETTEXT($element))->_index);
		}
	;

///----------
   context_bind_event
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
//   |  service_invocation
   ;

///----------
   context_invocation
///----------
@declarations
{
   std::string serviceName;
}
   :  '{' expr '}' '.' 'bind' '(' argument ')'  { methodDef->addInstruction(JOINC_OPCODE);  }
   |  '{' expr '}' '.' 'leave' '(' argument ')' { methodDef->addInstruction(LEAVEC_OPCODE); }
   |  { methodDef->pushInstructions(); } '{' expr '}' '.' { methodDef->addInstructions(); } IDENTIFIER
      '(' (args=argument_list)? ')'
      {
         methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($args.args), IntegerType));
         serviceName = GETTEXT($IDENTIFIER);
         methodDef->addPushedInstructions();
         methodDef->addInstruction(RUNS_OPCODE, entityDef->getSymbolIndex(serviceName, StringType));
      }
   ;

///----------
   data_context_interation
///----------
   : '{' expr '}' '.' 'data' '.' IDENTIFIER
      '(' (arg1=argument_list '=>' arg2=argument_list)? ')'
      {
         if (GETTEXT($IDENTIFIER) == "publish") {
            methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($arg1.args), IntegerType));
            methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($arg2.args), IntegerType));
            methodDef->addInstruction(PUBLISHD_OPCODE);
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



/////----------
//   service_context_interation
/////----------
//@declarations
//{
//   std::string serviceName;
//}
//	:	'{' expr '}' '.' 'service' '+=' IDENTIFIER { serviceName = GETTEXT($IDENTIFIER); }
//		'('
//			( type1=type ( ',' type2=type )* )?
////         ( type1=type { /*serviceName += ":" + $type1.sret;*/ } ( ',' type2=type { /*serviceName += ":" + $type2.sret;*/ } )* )?
//		')'
//		{ methodDef->addInstruction(PUBLISHS_OPCODE, entityDef->getSymbolIndex(serviceName, StringType)); }
//	|	'{' expr '}' '.' 'service' '-=' IDENTIFIER { serviceName = GETTEXT($IDENTIFIER); }
//		'('
//			( type1=type ( ',' type2=type )* )?
////         ( type1=type { /*serviceName += ":" + $type1.sret;*/ } ( ',' type2=type { /*serviceName += ":" + $type2.sret;*/ } )* )?
//		')'
//		{ methodDef->addInstruction(REMOVES_OPCODE, entityDef->getSymbolIndex(serviceName, StringType)); }
//	;

///----------
   service_context_interation
///----------
@declarations
{
   std::string serviceName;
}
	:	'{' expr '}' '.' 'service' '.' action=IDENTIFIER
		'(' service=IDENTIFIER { serviceName = GETTEXT($service); }
			( '(' type1=type ( ',' type2=type )* ')' )?
		')'
		{
			if (GETTEXT($action) == "publish") {
				methodDef->addInstruction(PUBLISHS_OPCODE, entityDef->getSymbolIndex(serviceName, StringType));
			} else if (GETTEXT($action) == "rem") {
				methodDef->addInstruction(REMOVES_OPCODE, entityDef->getSymbolIndex(serviceName, StringType));
			} else {
				std::cerr << "Acao nao definida para servicos !!!" << std::endl;
			}
		}
	;

///----------
   rcontext
///----------
   : '{' expr '}' '.' 'data' '.' IDENTIFIER ( '(' (argument_list)? ')' )?
      {
         if (GETTEXT($IDENTIFIER) == "get") {
            methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
            methodDef->addInstruction(GETD_OPCODE);
         } else if (GETTEXT($IDENTIFIER) == "find") {
            methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
            methodDef->addInstruction(FINDD_OPCODE);
         } else if (GETTEXT($IDENTIFIER) == "findnb") {
            methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
            methodDef->addInstruction(FINDDNB_OPCODE);
         } else if (GETTEXT($IDENTIFIER) == "getnb") {
            methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
            methodDef->addInstruction(GETDNB_OPCODE);
         } else if (GETTEXT($IDENTIFIER) == "list") {
            methodDef->addInstruction(LISTD_OPCODE);
         }
      }
	|	'{' expr '}' '.' 'element' '.' IDENTIFIER ( '(' (argument_list)? ')' )?
		{
			if (GETTEXT($IDENTIFIER) == "list") {
				methodDef->addInstruction(ELEMENTLIST_OPCODE);
			}
		}
	|	'{' expr '}' '.' 'service' '.' IDENTIFIER ( '(' (argument_list)? ')' )?
		{
			if (GETTEXT($IDENTIFIER) == "list") {
				methodDef->addInstruction(SERVICELIST_OPCODE);
			}
		}
	|  service_invocation
	;

///----------
   service_invocation
///----------
@declarations
{
   std::string serviceName;
}
   :  { methodDef->pushInstructions(); } '{' expr '}' '.' { methodDef->addInstructions(); } IDENTIFIER
      ( '(' args=argument_list ')' )?
      {
         methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($args.args), IntegerType));
         serviceName = GETTEXT($IDENTIFIER);
         methodDef->addPushedInstructions();
         methodDef->addInstruction(RUNS_OPCODE, entityDef->getSymbolIndex(serviceName, StringType));
      }
   ;

//--------------------------------------
   rtable :
//--------------------------------------
		IDENTIFIER '.' 'size' '(' ')'
		{ methodDef->addInstruction(TABSIZE_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); }
//	|	IDENTIFIER '[' expr { methodDef->addLoadInstruction(GETTEXT($IDENTIFIER)); } ',' expr ']' { methodDef->addLoadInstruction(GETTEXT($IDENTIFIER)); }
	|	IDENTIFIER '[' expr ']' { methodDef->addLoadInstruction(GETTEXT($IDENTIFIER), true); }
	;

//--------------------------------------
   rtuple :
//--------------------------------------
		IDENTIFIER '.' 'keys'   '[' expr ']' { methodDef->addInstruction(LDTUPLEK_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); }
	|	IDENTIFIER '.' 'values' '[' expr ']' { methodDef->addInstruction(LDTUPLEV_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); }
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
   ;

///----------
   if_statement
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
      code_block
      { methodDef->addInstruction(JMP_OPCODE, nextCommandLabel); }
      { methodDef->setNextInstructionLabel(elseLabel); }
      ('else' code_block)? 'end'
      { methodDef->setNextInstructionLabel(nextCommandLabel); }
   ;

///----------
   iteration_statement
///----------
   :  for_statement|while_statement|repeat_statement|foreach_statement
  // o do..while nao funciona pq o while eh identificado como uma nova sentenca while dentro do do..while...
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
      code_block
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
      code_block
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
}
   :  'repeat'
      { startLabel = methodDef->getNewLabel(); }
      { methodDef->setNextInstructionLabel(startLabel); }
      code_block
      'until' '(' expr ')'
      { methodDef->addInstruction(IFNOT_OPCODE, startLabel); }
   ;

///----------
   foreach_statement
///----------
   :  'foreach' '(' IDENTIFIER 'in' rcontext ')'
      code_block
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
//            {
//               if (GETTEXT($methodId) == "writeln") {
//                  methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
//               }
//            }
         )?
      ')'
      {
//         if (GETTEXT($methodId) == "writeln") {
//            methodDef->addInstruction(LCALL_OPCODE, entityDef->getSymbolIndex(GETTEXT($methodId), StringType));
//         } else {
            methodDef->addInstruction(LDSELF_OPCODE);
            methodDef->addInstruction(MCALL_OPCODE, entityDef->getSymbolIndex(GETTEXT($methodId), StringType));
//         }
      }
   ;

///----------
   element_method_invocation
///----------
   :  elementId=IDENTIFIER '.' methodId=IDENTIFIER '(' (argument_list)? ')'
      {
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
//   |  context_property // TODO: acho que esse nao seria o nome mais adequado...
   ;

///----------
   literal
///----------
   :  IDENTIFIER     { methodDef->addLoadInstruction(GETTEXT($IDENTIFIER), false);  }
//   :  IDENTIFIER     { methodDef->addInstruction(LDVAR_OPCODE  , methodDef->getVarIndex(GETTEXT($IDENTIFIER)));  }
   |  INTEGER_LITERAL { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($INTEGER_LITERAL), IntegerType)); }
   |  REAL_LITERAL    { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($REAL_LITERAL),    RealType));    }
//   |  STRING_LITERAL  { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex($STRING_LITERAL,  StringType));  }
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
   |  'activity' { $value = "avtivity"; }
   |  'time'     { $value = "time";     }
   ;

///----------
   element_property
///----------
   : IDENTIFIER '.' IDENTIFIER
   ;



//$$$$$$$$$$$$$$$$$$$$$


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

expr_unario
  : expr_elemento
  ;

op_unario
  : (
        '-'
      | '+'
      | 'not' // n:T_KW_NOT
      | '!' //b:T_BIT_NOT
    )?
  ;

expr_elemento
  : method_invocation
  | IDENTIFIER     { methodDef->addLoadInstruction(GETTEXT($IDENTIFIER), false);  }
//  | IDENTIFIER { methodDef->addInstruction(LDVAR_OPCODE, methodDef->getVarIndex(GETTEXT($IDENTIFIER))); }
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

INTEGER_LITERAL : ('0'..'9')+ ;

//OctalLiteral : '0' ('0'..'7')+ IntegerTypeSuffix? ;

//fragment
//HexDigit : ('0'..'9'|'a'..'f'|'A'..'F') ;

//fragment
//IntegerTypeSuffix : ('l'|'L') ;

REAL_LITERAL
   :  ('0'..'9')+ '.' ('0'..'9')+
   |  '.' ('0'..'9')+
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
   :  LETTER (LETTER|DIGIT|'_')*
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

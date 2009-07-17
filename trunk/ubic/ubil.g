///####################################################################
///####################### Inicio da gramatica ########################
///####################################################################

// DICAS COPIADOS DOS EXEMPLOS...
// printf("'\%s' is a type", $IDENTIFIER.text->chars);

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
//    k		= 2; 
    backtrack	= true; 
    memoize	= true;
    language	= C;
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
//    extern "C++" {
//	#include <string>
//    }
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

}

@after {
//   symbolTable = new CSymbolTable();
//	char* getTest2() { return "oi!!!"; }
}

// starting point for parsing a ubil file
///----------
   compilation_unit [SParamOptions options]
///----------
   :  //{ symbolTable = new CSymbolTable(); /*nao tem um init do antlr ???*/ }
      (entity_definition)+
      EOF
      {
         if (options.asmFilename != "") {
            std::ofstream out(options.asmFilename.c_str(), std::ios_base::out);
            out << asmDef.toTextAssembly();
         }
         asmDef.saveBytecode(options.uvmFilename);
      }
   ;

///----------
   entity_definition
///----------
@init{
}
   :  'entity' Identifier
      {
//          entityDef = asmDef.addEntity((const char*)$Identifier.text->chars);
          entityDef = asmDef.addEntity(GETTEXT($Identifier));
      }
      (property_definition|method_definition)*
      'end'
   ;

///----------
   property_definition
///----------
   :  'def' type Identifier
      {
         entityDef->addProperty(PublicVisibility, $type.ret, (const char*)$Identifier.text->chars);
      }
   ;

///----------
   type returns [LiteralType ret]
///----------
   :  'int'    { $ret = IntegerType; }
   |  'real'   { $ret = RealType;    }
   |  'string' { $ret = StringType;  }
   |  'bool'   { $ret = BooleanType; }
//   |  'element'
   ;

///----------
   method_definition
///----------
   :  'def' Identifier
      {
         methodDef = entityDef->addMethod(PublicVisibility, (const char*)$Identifier.text->chars);
      }
      '(' (parameters_definition)? ')'
      (var_definition)*
      code_block
      'end'
      {
         if (std::string((const char*)$Identifier.text->chars) == "start") {
            methodDef->addInstruction(STOP_OPCODE);
         } else {
            methodDef->addInstruction(RET_OPCODE);
         }
         methodDef->resolveLabels();
      }
   ;

///----------
   parameters_definition
///----------
   :  type1=type id1=Identifier
      {
         methodDef->addParameter($type1.ret, (const char*) $id1.text->chars);
//         methodDef->addParameter((const char*)$type1.text->chars, (const char*) $id1.text->chars);
      }
      ( ',' type2=type id2=Identifier
         {
            methodDef->addParameter($type2.ret, (const char*) $id2.text->chars);
//            methodDef->addParameter((const char*)$type2.text->chars, (const char*) $id2.text->chars);
         }
      )*
   ;

///--------------
   var_definition
///--------------
   :  'def' type Identifier
      {
         methodDef->addLocalVar($type.ret, (const char*)$Identifier.text->chars);
      }
   ;

///----------
   code_block
///----------
   :  (statement)*
   ;

///----------
   statement
///----------
   : if_statement|iteration_statement|assignment_statement|method_invocation
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
   :  for_statement|while_statement|/*do_while_statement|*/repeat_statement
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
      code_block 'end'
      { methodDef->addInstruction(JMP_OPCODE, testLabel); }
      { methodDef->setNextInstructionLabel(nextCommandLabel); }
   ;

///----------
   do_while_statement
///----------
@declarations
{
	int startLabel;
}
   :  'do'
      { startLabel = methodDef->getNewLabel(); }
      { methodDef->setNextInstructionLabel(startLabel); }
      code_block
      'while' '(' expr ')'
      { methodDef->addInstruction(IF_OPCODE, startLabel); }
   ;

///----------
   repeat_statement
///----------
   :  'repeat' // ...
   ;

///----------
   assignment_statement
///----------
   :  Identifier '=' expr
      { methodDef->addInstruction(STVAR_OPCODE, methodDef->getVarIndex(GETTEXT($Identifier))); }
   ;

///----------
   method_invocation
///----------
   :  Identifier
//      {
//         printf("Metodo [\%s] ", $Identifier.text->chars);
//      }
      '('
         (argument_list
            {
               if (GETTEXT($Identifier) == "writeln") {
                  methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(itoa($argument_list.args), IntegerType));
               }
            }
         )?
      ')'
//      { printf("\n"); }
      {
         if (GETTEXT($Identifier) == "writeln") {
            methodDef->addInstruction(LCALL_OPCODE, entityDef->getSymbolIndex(GETTEXT($Identifier), StringType));
         } else {
            methodDef->addInstruction(MCALL_OPCODE, entityDef->getSymbolIndex(GETTEXT($Identifier), StringType));
         }
      }
   ;

///----------
   argument_list returns [uint args]
///----------
   :
//{uint $args = 0;}
      argument {$args++;} (',' argument {$args++;} )*
//   :  arg1=argument {printf("argumento [\%s] ", $arg1.text->chars);} (',' arg2=argument {printf("argumento [\%s] ", $arg2.text->chars);})*
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
   :  Identifier     { methodDef->addInstruction(LDVAR_OPCODE  , methodDef->getVarIndex(GETTEXT($Identifier)));  }
   |  IntegerLiteral { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($IntegerLiteral), IntegerType)); }
   |  RealLiteral    { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($RealLiteral),    RealType));    }
//   |  StringLiteral  { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex($StringLiteral,  StringType));  }
   |  StringLiteral  { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(removeQuotes(GETTEXT($StringLiteral)),  StringType));  }
   |  BooleanLiteral { methodDef->addInstruction(LDCONST_OPCODE, entityDef->getSymbolIndex(GETTEXT($BooleanLiteral),  BooleanType));  }
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
  | Identifier { methodDef->addInstruction(LDVAR_OPCODE, methodDef->getVarIndex(GETTEXT($Identifier))); }
  | literal
  | '(' expr ')' 
  ;


//$$$$$$$$$$$$$$$$$$$$$$


// LEXER

//HexLiteral : '0' ('x'|'X') HexDigit+ IntegerTypeSuffix? ;

IntegerLiteral : ('0'..'9')+ ;

//OctalLiteral : '0' ('0'..'7')+ IntegerTypeSuffix? ;

//fragment
//HexDigit : ('0'..'9'|'a'..'f'|'A'..'F') ;

//fragment
//IntegerTypeSuffix : ('l'|'L') ;

RealLiteral
   :  ('0'..'9')+ '.' ('0'..'9')+
   |  '.' ('0'..'9')+
   ;

//fragment
//Exponent : ('e'|'E') ('+'|'-')? ('0'..'9')+ ;

//fragment
//FloatTypeSuffix : ('f'|'F'|'d'|'D') ;

CharacterLiteral
    :   '\'' ( EscapeSequence | ~('\''|'\\') ) '\''
    ;

StringLiteral returns [const char* ret] // ou pANTLR3_STRING ???
//@after{
////	setText(getText().substring(1, getText().length()-1));
//}
    :  '"' ( EscapeSequence | ~('\\'|'"') )* '"'
//	  {
//	  	// Strip the surrounding quotes
//	  	std::string txt = (const char*) (GETTEXT()->chars);
//	  	$ret = txt.substr(1, txt.length() -1).c_str();
//	  }

//	  {
//	  	// Strip the surrounding quotes
//	  	String txt = getText();
//	  	setText(txt.substring(1, txt.length() -1));
//	  }
    ;

BooleanLiteral
   : 'true' | 'false'
   ;

fragment
EscapeSequence
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

//ENUM:	'enum' {if ( !enumIsKeyword ) $type=Identifier;}
//	;
	
Identifier 
   :  Letter (Letter|Digit)*
   ;


fragment
Letter: 'a'..'z' ;

fragment
Digit : '0'..'9' ;

WS  :  (' '|'\r'|'\t'|'\u000C'|'\n') {$channel=HIDDEN;}
    ;

COMMENT
    :   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
    ;

LINE_COMMENT
    : '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    ;


























/*
modifier
    :   'public'
    |   'private'
    ;

primitiveType
    :   'boolean'
    |	'char'
    |	'byte'
    |	'short'
    |	'int'
    |	'long'
    |	'float'
    |	'double'
    ;

literal	
	:   integerLiteral
    |   FloatingPointLiteral
    |   CharacterLiteral
    |   StringLiteral
    |   booleanLiteral
    |   'null'
	;

integerLiteral
    :   HexLiteral
    |   OctalLiteral
    |   DecimalLiteral
    ;


booleanLiteral
    :   'true'
    |   'false'
    ;

// STATEMENTS / BLOCKS

block
	:	'{' blockStatement* '}'
	;
	
blockStatement
	:	localVariableDeclaration
    |   classOrInterfaceDeclaration
    |   statement
	;
	
localVariableDeclaration
	:	type variableDeclarators ';'
	;
	
statement
	: block
    | 'assert' expression (':' expression)? ';'
    | 'if' parExpression statement (options {k=1; backtrack=false;}:'else' statement)?
    | 'for' '(' forControl ')' statement
    | 'while' parExpression statement
    | 'do' statement 'while' parExpression ';'
    | 'switch' parExpression '{' switchBlockStatementGroups '}'
    | 'synchronized' parExpression block
    | 'return' expression? ';'
    | 'throw' expression ';'
    | 'break' Identifier? ';'
    | 'continue' Identifier? ';'
    | ';'
    | statementExpression ';'
    | Identifier ':' statement
	;
	
switchBlockStatementGroups
	:	(switchBlockStatementGroup)*
	;
	
switchBlockStatementGroup
	:	switchLabel blockStatement*
	;
	
switchLabel
	:	'case' constantExpression ':'
	|   'case' enumConstantName ':'
	|   'default' ':'
	;
	
forControl
options {k=3;} // be efficient for common case: for (ID ID : ID) ...
	:	forVarControl
	|   forInit? ';' expression? ';' forUpdate?
	;

forInit
	:	variableModifier* type variableDeclarators
    |   expressionList
	;
	
forVarControl
	:	variableModifier* type Identifier ':' expression
	;

forUpdate
	:	expressionList
	;

// EXPRESSIONS

parExpression
	:	'(' expression ')'
	;
	
expressionList
    :   expression (',' expression)*
    ;

statementExpression
	:	expression
	;
	
constantExpression
	:	expression
	;
	
expression
	:	conditionalExpression (assignmentOperator expression)?
	;
	
assignmentOperator
	:	'='
    |   '+='
    |   '-='
    |   '*='
    |   '/='
    |   '&='
    |   '|='
    |   '^='
    |   '%='
    |   '<' '<' '='
    |   '>' '>' '='
    |   '>' '>' '>' '='
	;

conditionalExpression
    :   conditionalOrExpression ( '?' expression ':' expression )?
	;

conditionalOrExpression
    :   conditionalAndExpression ( '||' conditionalAndExpression )*
	;

conditionalAndExpression
    :   inclusiveOrExpression ( '&&' inclusiveOrExpression )*
	;

inclusiveOrExpression
    :   exclusiveOrExpression ( '|' exclusiveOrExpression )*
	;

exclusiveOrExpression
    :   andExpression ( '^' andExpression )*
	;

andExpression
    :   equalityExpression ( '&' equalityExpression )*
	;

equalityExpression
    :   instanceOfExpression ( ('==' | '!=') instanceOfExpression )*
	;

instanceOfExpression
    :   relationalExpression ('instanceof' type)?
	;

relationalExpression
    :   shiftExpression ( relationalOp shiftExpression )*
	;
	
relationalOp
	:	('<' '=' | '>' '=' | '<' | '>')
	;

shiftExpression
    :   additiveExpression ( shiftOp additiveExpression )*
	;

        // TODO: need a sem pred to check column on these >>>
shiftOp
	:	('<' '<' | '>' '>' '>' | '>' '>')
	;


additiveExpression
    :   multiplicativeExpression ( ('+' | '-') multiplicativeExpression )*
	;

multiplicativeExpression
    :   unaryExpression ( ( '*' | '/' | '%' ) unaryExpression )*
	;
	
unaryExpression
    :   '+' unaryExpression
    |	'-' unaryExpression
    |   '++' unaryExpression
    |   '--' unaryExpression
    |   unaryExpressionNotPlusMinus
    ;

unaryExpressionNotPlusMinus
    :   '~' unaryExpression
    | 	'!' unaryExpression
    |   castExpression
    |   primary selector* ('++'|'--')?
    ;

castExpression
    :  '(' primitiveType ')' unaryExpression
    |  '(' (type | expression) ')' unaryExpressionNotPlusMinus
    ;

primary
    :	parExpression
    |   nonWildcardTypeArguments
        (explicitGenericInvocationSuffix | 'this' arguments)
    |   'this' ('.' Identifier)* (identifierSuffix)?
    |   'super' superSuffix
    |   literal
    |   'new' creator
    |   Identifier ('.' Identifier)* (identifierSuffix)?
    |   primitiveType ('[' ']')* '.' 'class'
    |   'void' '.' 'class'
	;

identifierSuffix
	:	('[' ']')+ '.' 'class'
	|	('[' expression ']')+ // can also be matched by selector, but do here
    |   arguments
    |   '.' 'class'
    |   '.' explicitGenericInvocation
    |   '.' 'this'
    |   '.' 'super' arguments
    |   '.' 'new' (nonWildcardTypeArguments)? innerCreator
	;
	
creator
	:	nonWildcardTypeArguments? createdName
        (arrayCreatorRest | classCreatorRest)
	;

createdName
	:	Identifier typeArguments?
        ('.' Identifier typeArguments?)*
    |	primitiveType
	;
	
innerCreator
	:	Identifier classCreatorRest
	;

arrayCreatorRest
	:	'['
        (   ']' ('[' ']')* arrayInitializer
        |   expression ']' ('[' expression ']')* ('[' ']')*
        )
	;

classCreatorRest
	:	arguments classBody?
	;
	
explicitGenericInvocation
	:	nonWildcardTypeArguments explicitGenericInvocationSuffix
	;
	
nonWildcardTypeArguments
	:	'<' typeList '>'
	;
	
explicitGenericInvocationSuffix
	:	'super' superSuffix
	|   Identifier arguments
	;
	
selector
	:	'.' Identifier (arguments)?
	|   '.' 'this'
	|   '.' 'super' superSuffix
	|   '.' 'new' (nonWildcardTypeArguments)? innerCreator
	|   '[' expression ']'
	;
	
superSuffix
	:	arguments
	|   '.' Identifier (arguments)?
    ;

arguments
	:	'(' expressionList? ')'
	;

// LEXER

HexLiteral : '0' ('x'|'X') HexDigit+ IntegerTypeSuffix? ;

DecimalLiteral : ('0' | '1'..'9' '0'..'9'*) IntegerTypeSuffix? ;

OctalLiteral : '0' ('0'..'7')+ IntegerTypeSuffix? ;

fragment
HexDigit : ('0'..'9'|'a'..'f'|'A'..'F') ;

fragment
IntegerTypeSuffix : ('l'|'L') ;

FloatingPointLiteral
    :   ('0'..'9')+ '.' ('0'..'9')* Exponent? FloatTypeSuffix?
    |   '.' ('0'..'9')+ Exponent? FloatTypeSuffix?
    |   ('0'..'9')+ (	  Exponent FloatTypeSuffix?
						| FloatTypeSuffix
					)
	;

fragment
Exponent : ('e'|'E') ('+'|'-')? ('0'..'9')+ ;

fragment
FloatTypeSuffix : ('f'|'F'|'d'|'D') ;

CharacterLiteral
    :   '\'' ( EscapeSequence | ~('\''|'\\') ) '\''
    ;

StringLiteral
    :  '"' ( EscapeSequence | ~('\\'|'"') )* '"'
    ;

fragment
EscapeSequence
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    |   UnicodeEscape
    |   OctalEscape
    ;

fragment
OctalEscape
    :   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7')
    ;

fragment
UnicodeEscape
    :   '\\' 'u' HexDigit HexDigit HexDigit HexDigit
    ;

ENUM:	'enum' {if ( !enumIsKeyword ) $type=Identifier;}
	;
	
Identifier 
    :   Letter (Letter|JavaIDDigit)*
    ;

fragment
Letter
    :  '\u0024' |
       '\u0041'..'\u005a' |
       '\u005f' |
       '\u0061'..'\u007a' |
       '\u00c0'..'\u00d6' |
       '\u00d8'..'\u00f6' |
       '\u00f8'..'\u00ff' |
       '\u0100'..'\u1fff' |
       '\u3040'..'\u318f' |
       '\u3300'..'\u337f' |
       '\u3400'..'\u3d2d' |
       '\u4e00'..'\u9fff' |
       '\uf900'..'\ufaff'
    ;

fragment
JavaIDDigit
    :  '\u0030'..'\u0039' |
       '\u0660'..'\u0669' |
       '\u06f0'..'\u06f9' |
       '\u0966'..'\u096f' |
       '\u09e6'..'\u09ef' |
       '\u0a66'..'\u0a6f' |
       '\u0ae6'..'\u0aef' |
       '\u0b66'..'\u0b6f' |
       '\u0be7'..'\u0bef' |
       '\u0c66'..'\u0c6f' |
       '\u0ce6'..'\u0cef' |
       '\u0d66'..'\u0d6f' |
       '\u0e50'..'\u0e59' |
       '\u0ed0'..'\u0ed9' |
       '\u1040'..'\u1049'
   ;

WS  :  (' '|'\r'|'\t'|'\u000C'|'\n') {$channel=HIDDEN;}
    ;

LINE_COMMENT
    : '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    ;
*/


/*
///////////////////// COPIADO DO GPTC ///////////////////////

/////////////////// PARSER DO GPTC ////////////////////

{  
   public:
      COptions options;
      CAsmProgram  *asmPrg;
      CSubroutine *subroutine;
      CTemporarySymbol tempVar;
      CTemporarySymbol tempLabel;
      SymbolTable symbolTable;
      void initParser( string filename )
      {
         options.filename = filename;
         asmPrg = new CAsmProgram( &options, &symbolTable );
         tempVar.setBaseName( "__temp_" );
         tempVar.setNextValue( 1 );
         tempLabel.setBaseName( "__label_" );
      }
      void finishParser( )
      {
         delete asmPrg;
         asmPrg = NULL;
      }
      void declareProgramVar(const string& scope, const string& lexeme, int line, int type)
      {
         symbolTable.declareVar( scope, lexeme, line, type );
         asmPrg->emitVarDefinition( lexeme, type );
      }
      void declareSubroutineVar(const string& scope, const string& lexeme, int line, int type)
      {
         symbolTable.declareVar( scope, lexeme, line, type );
         subroutine->emitVarDefinition( lexeme, type );
      }
      void declareParameter(const string& lexeme, int line, int type)
      {
         symbolTable.declareVar( subroutine->getName(), lexeme, line, type );
         subroutine->emitParDefinition( lexeme, type );
      }
      int getSymbolType( const string& lexeme )
      {
         return symbolTable.getSymbol(subroutine->getName(), lexeme, true).getType().getPrimitiveType();
      }
}


//####################################################################
//####################### Início da gramática ########################
//####################################################################

//##############
//## Programa ##
//##############

//--------
  programa [string filename] returns [string ret]
//-------- 
  : { initParser( filename ); asmPrg->init( ); } (declaracao_algoritmo)? (importacao)*
    (declaracao_constantes | bloco_declaracao_estrutura | declaracao_variaveis[false])* corpo EOF
    {
       asmPrg->finish( );
       ret = asmPrg->getAsm( );
       finishParser( );
    }
  ;

declaracao_algoritmo
  : "algoritmo" T_IDENTIFICADOR T_SEMICOL
  ;

importacao
  : "use" T_STRING_LIT T_SEMICOL
  ;

corpo 
  :  (declaracao_subrotina)* { subroutine = asmPrg->initSubroutine( "main" ); }
     bloco_codigo { asmPrg->finishSubroutine( subroutine ); }
     (declaracao_subrotina)*
  ;


//#############################
//## Declaração de variáveis ##
//#############################

//--------------------
  declaracao_variaveis [bool isLocal]
//--------------------
  : bloco_declaracao_variaveis[isLocal]
  | "variável" declaracao_variavel[isLocal]
  ;

bloco_declaracao_variaveis [bool isLocal]
  : "variáveis" (declaracao_variavel[isLocal])+ "fim-variáveis"
  ;

declaracao_variavel [bool isLocal]
{
  int tk_type;
}
  : tk_id:T_IDENTIFICADOR 
    (T_COMMA T_IDENTIFICADOR)* 
    T_COLON tk_type=tipo
    (lista_inicializacao)? T_SEMICOL
    { // TODO: nao esta correto porque so gera uma variavel...
       if (isLocal) {
          declareSubroutineVar( SymbolTable::GlobalScope, tk_id->getText( ), 0, tk_type );
       } else {
          declareProgramVar( SymbolTable::GlobalScope, tk_id->getText( ), 0, tk_type );
       }
    }
  ;

tipo returns [int ret]
  : ret=tipo_primitivo 
  | ret=tipo_matriz 
  | T_IDENTIFICADOR {ret=T_KW_ESTRUTURA;}
  ;

lista_inicializacao
{
  string result;
}
  : T_ATTR (result=expr | inicializacao_composta)
  ;

inicializacao_composta
  : T_ABREC inicializacao_indice (T_COLON inicializacao_indice)* T_FECHAC
  ;

inicializacao_indice
{
  string result;
}
  : result=expr
  ;

inicializacao_membro
{
  string result;
}
  : T_IDENTIFICADOR T_ATTR (result=expr | inicializacao_composta)
  ;

tipo_primitivo returns [int ret]
  : "inteiro"   {ret=T_KW_INTEIRO;}
  | "real"      {ret=T_KW_REAL;}
  | "caractere" {ret=T_KW_CARACTERE;}
  | "literal"   {ret=T_KW_LITERAL;}
  | "lógico"    {ret=T_KW_LOGICO;}
  | "coringa"   {ret=T_KW_CORINGA;}
  ;

tipo_matriz returns [int ret]
{
  int type;
}
  : "matriz" (T_ABREC (T_INT_LIT)? T_FECHAC)+ "do" "tipo" (type=tipo_primitivo | T_IDENTIFICADOR)
    {ret=T_KW_MATRIZ;}
  ;


declaracao_constantes
  : bloco_declaracao_constantes
  | "constante" declaracao_constante
  ;

bloco_declaracao_constantes
  : "constantes" (declaracao_constante)+ "fim-constantes"
  ;

declaracao_constante
{
  int type;
}
  : T_IDENTIFICADOR T_COLON type=tipo lista_inicializacao T_SEMICOL
  ;


bloco_declaracao_estrutura
  : "estrutura" T_IDENTIFICADOR (declaracao_variavel[false])+ "fim-estrutura"
  ;


declaracao_subrotina
  : declaracao_funcao
  | declaracao_procedimento
  ;

declaracao_funcao
{
   int tk_type;
}
  : "função" tk_id:T_IDENTIFICADOR
    { subroutine = asmPrg->initSubroutine( tk_id->getText( ) ); }
    T_ABREP (lista_parametros)? T_FECHAP T_COLON tk_type=tipo
    {
       declareSubroutineVar( SymbolTable::GlobalScope, "__result", 0, tk_type );
    }
    (declaracao_constantes | declaracao_variaveis[true])*
    bloco_codigo
    { asmPrg->finishSubroutine( subroutine ); }
  ;

declaracao_procedimento
  : "procedimento" tk_id:T_IDENTIFICADOR
    { subroutine = asmPrg->initSubroutine( tk_id->getText( ) ); }
    T_ABREP (lista_parametros)? T_FECHAP
    (declaracao_constantes | declaracao_variaveis[true])*
    bloco_codigo
    { asmPrg->finishSubroutine( subroutine ); }
  ;

lista_parametros
  : parametro (T_COMMA parametro)*
  ;

parametro
{
  int type;
}
  : (("constante")? ("ref"))? tk_id:T_IDENTIFICADOR T_COLON type=tipo
  {
    declareParameter( tk_id->getText( ), 0, type );
  }
  ;

bloco_codigo
  : "início" lista_enunciados "fim"
  ;

lista_enunciados
  : (enunciado)*
  ;

enunciado
  :
  ( (lvalue T_ATTR)=> en_atribuicao
    | en_retorne
    | en_se
    | en_enquanto
    | en_repita
    | en_para
    | en_caso
    | en_asm_code
    | chamada_procedimento
    | "sair" T_SEMICOL
    | T_SEMICOL
  )
  ;

en_atribuicao
{
   string tklvalue;
   string tkexpret;
}
  : tklvalue=lvalue T_ATTR tkexpret=expr T_SEMICOL
    { subroutine->emitMnWithPrefix( "set", tklvalue, tkexpret ); }
  ;

en_retorne
{
  string result;
}
  : "retorne"
    (result=expr {subroutine->emitMnWithPrefix( "set", "__result", result ); } )?
    { subroutine->emitMn( "ret" ); }
    T_SEMICOL
  ;

lvalue returns [string tk_id]
{
  string ret;
}
  : T_IDENTIFICADOR {tk_id=lastToken->getText( );}
    (T_ABREC ret=expr T_FECHAC)*
  | T_IDENTIFICADOR T_DOT T_IDENTIFICADOR
  ;

en_se
{
  string expRet;
  string elseLabel;
  string nextLabel;
}
  : "se" expRet=expr "então" { elseLabel = tempLabel.getNew( ); subroutine->emitMn( "ifnot", expRet, elseLabel ); }
    lista_enunciados
    { nextLabel = tempLabel.getNew( ); subroutine->emitMn( "jmp", nextLabel ); subroutine->emitLabel( elseLabel ); }
    ("senão" lista_enunciados)? "fim-se"
    { subroutine->emitLabel( nextLabel ); }
  ;

en_enquanto
{
  string testLabel;
  string expRet;
  string nextCommandLabel;
}
  : "enquanto"
    {
       testLabel = tempLabel.getNew( );
       nextCommandLabel = tempLabel.getNew( );
       subroutine->emitLabel( testLabel );
    }
    expRet=expr "faça"
    {
       subroutine->emitMn( "ifnot", expRet, nextCommandLabel );
    }
    lista_enunciados
    "fim-enquanto"
    {
       subroutine->emitMn( "jmp", testLabel );
       subroutine->emitLabel( nextCommandLabel );
    }
  ;

en_para
{
  string lvalueRet;
  string exp1;
  string exp2;
  string testLabel;
  string nextCommandLabel;
  string testVar;
  int    step=1;
}
  : "para" lvalueRet=lvalue "de" exp1=expr "até" exp2=expr (step=passo)? "faça"
    {
       subroutine->emitMnWithPrefix( "set", lvalueRet, exp1 );
       testLabel = tempLabel.getNew( );
       nextCommandLabel = tempLabel.getNew( );
       testVar   = tempVar.getNew( );
       declareSubroutineVar( SymbolTable::GlobalScope, testVar, 0, T_KW_INTEIRO );
       subroutine->emitLabel( testLabel );
       if (step >= 0) {
          subroutine->emitMnWithPrefix( "le", testVar, lvalueRet, exp2 );
       } else {
          subroutine->emitMnWithPrefix( "ge", testVar, lvalueRet, exp2 );
       }
       subroutine->emitMn( "ifnot", testVar, nextCommandLabel );
    }
    lista_enunciados
    "fim-para"
    {
       subroutine->emitMnWithPrefix( step > 0 ? "inc" : "dec", lvalueRet, itoa( abs( step ) ) );
       subroutine->emitMn( "jmp", testLabel );
       subroutine->emitLabel( nextCommandLabel );
    }
  ;

passo returns [int ret]
{
  string signal;
}
  : "passo" (T_MAIS|T_MENOS{signal="-";})? T_INT_LIT { ret=atoi((signal+lastToken->getText( )).c_str( )); }
  ;

en_repita
{
  string labelBegin = tempLabel.getNew( );
  string exp;
}
  : "repita"
    { subroutine->emitLabel( labelBegin ); }
    lista_enunciados
    "até" exp=expr
    { subroutine->emitMn( "ifnot", exp, labelBegin ); }
  ;

en_caso 
{
  string expret;
  string varTest;
  string nextCommandLabel;
  string nextTestLabel;
}
  : "caso" expret=expr "seja" 
    {
       varTest = tempVar.getNew( );
       declareSubroutineVar( SymbolTable::GlobalScope, varTest, 0, T_KW_INTEIRO );
       subroutine->emitMnWithPrefix( "set", varTest, expret );
       nextCommandLabel = tempLabel.getNew( );
    }
    (
       nextTestLabel=teste_caso[varTest]
       {subroutine->emitMn( "jmp", nextCommandLabel ); subroutine->emitLabel( nextTestLabel );}
    )+ ("senão" lista_enunciados "fim-senão")? "fim-caso" 
    {
       subroutine->emitLabel( nextCommandLabel );
    }
  ; 
  
teste_caso [string varTest] returns [string nextTestLabel]
{
  string lit;
}
  : lit=literal "faça" 
    {
       declareSubroutineVar( SymbolTable::GlobalScope, tempVar.getNew(), 0, getSymbolType( varTest ) );
       subroutine->emitMnWithPrefix( "eq", tempVar.getLast(), varTest, lit );
       nextTestLabel = tempLabel.getNew( );
       subroutine->emitMn( "ifnot", tempVar.getLast( ), nextTestLabel );
    }
    lista_enunciados
    "fim-faça"
  ;

en_asm_code
  : "asm"
    T_ASM_CODE { subroutine->emitAsmCode( lastToken->getText( ) ); }
    "fim-asm"
  ;

chamada_procedimento
{
   CArguments args;
}
  : tk_id:T_IDENTIFICADOR T_ABREP
    ( {args.init( subroutine, tk_id->getText( ) ); } lista_argumentos[args] { args.emitMnsInSubroutineCall( ); })? T_FECHAP
    { subroutine->emitMn( "pcall", tk_id->getText( ) ); }
  ; 

chamada_funcao returns [string ret]
{
   CArguments args;
}
  : tk_id:T_IDENTIFICADOR T_ABREP
    { subroutine->emitMn( "push_0" ); }
    ( 
      { args.init( subroutine, tk_id->getText( ) ); }
      lista_argumentos[args]
      { args.emitMnsInSubroutineCall( ); }
    )? T_FECHAP
    {
      subroutine->emitMn( "pcall", tk_id->getText( ) );
      ret = tempVar.getNew( );
      declareSubroutineVar( SymbolTable::GlobalScope, ret, 0, T_KW_INTEIRO );
      subroutine->emitMn( "pop", ret );
    }
  ; 

lista_argumentos [CArguments &args]
{
  string ret;
}
  : ret=expr { args.push_back( ret ); }
    (
      T_COMMA ret=expr
      { args.push_back( ret ); }
    )*
  ;

literal returns [string ret]
  : ( 
        T_STRING_LIT {symbolTable.addConstant( SymbolTable::GlobalScope, lastToken->getText( ), 0, T_KW_LITERAL );}
      | T_INT_LIT  {symbolTable.addConstant( SymbolTable::GlobalScope, lastToken->getText( ), 0, T_KW_INTEIRO );}
      | T_REAL_LIT  {symbolTable.addConstant( SymbolTable::GlobalScope, lastToken->getText( ), 0, T_KW_REAL );}
      | T_CARAC_LIT  {symbolTable.addConstant( SymbolTable::GlobalScope, lastToken->getText( ), 0, T_KW_CARACTERE );}
      | "verdadeiro"  {symbolTable.addConstant( SymbolTable::GlobalScope, lastToken->getText( ), 0, T_KW_LOGICO );} // ???
      | "falso"  {symbolTable.addConstant( SymbolTable::GlobalScope, lastToken->getText( ), 0, T_KW_LOGICO );}      // ???
    ) {ret=lastToken->getText( );}
  ;

// ----------------------------- Expressoes ---------------------------------- 

expr returns [string ret]
{
  string op2;
}
  : ret=expr_e 
    (
      T_KW_OU op2=expr_e 
      {
         subroutine->emitMn( "or", tempVar.getNew( ), ret, op2 );
         ret=tempVar.getLast( );
         declareSubroutineVar( SymbolTable::GlobalScope, ret, 0, getSymbolType( op2 ) );
      }
    )*
  ;
  
expr_e  returns [string ret]
options {
  defaultErrorHandler=false; //noviable should be caught on expr
}
{
  string op2;
}
  : ret=expr_bit_ou
    (
      T_KW_E op2=expr_bit_ou
      {
         subroutine->emitMn( "and", tempVar.getNew( ), ret, op2 );
         ret=tempVar.getLast( );
         declareSubroutineVar( SymbolTable::GlobalScope, ret, 0, getSymbolType( op2 ) );
      }
    )*
  ;

expr_bit_ou returns [string ret]
options {
  defaultErrorHandler=false; //noviable should be caught on expr
}
{
  string op2;
}
  : ret=expr_bit_xou
    (
      T_BIT_OU op2=expr_bit_xou
      {
         subroutine->emitMn( "bor", tempVar.getNew( ), ret, op2 );
         ret=tempVar.getLast( );
         declareSubroutineVar( SymbolTable::GlobalScope, ret, 0, getSymbolType( op2 ) );
      }
    )*
  ;

expr_bit_xou  returns [string ret]
options {
  defaultErrorHandler=false; //noviable should be caught on expr
}
{
  string op2;
}
  : ret=expr_bit_e 
    (
      T_BIT_XOU op2=expr_bit_e
      {
         subroutine->emitMn( "bxor", tempVar.getNew( ), ret, op2 );
         ret=tempVar.getLast( );
         declareSubroutineVar( SymbolTable::GlobalScope, ret, 0, getSymbolType( op2 ) );
      }
    )*
  ;

expr_bit_e returns [string ret]
options {
  defaultErrorHandler=false; //noviable should be caught on expr
}
{
  string op2;
}
  : ret=expr_igual
    (
      T_BIT_E op2=expr_igual
      {
         subroutine->emitMn( "band", tempVar.getNew( ), ret, op2 );
         ret=tempVar.getLast( );
         declareSubroutineVar( SymbolTable::GlobalScope, ret, 0, getSymbolType( op2 ) );
      }
    )*
  ;
  
expr_igual returns [string ret]
options {
  defaultErrorHandler=false; //noviable should be caught on expr
}
{
  string op2;
  string mn;
}
  : ret=expr_relacional
    (
      ( T_IGUAL {mn="eq";} | T_DIFERENTE {mn="ne";} )
      op2=expr_relacional
      {
         declareSubroutineVar( SymbolTable::GlobalScope, tempVar.getNew( ), 0, getSymbolType( op2 ) );
         subroutine->emitMnWithPrefix( mn, tempVar.getLast( ), ret, op2 );
         ret=tempVar.getLast( );
      }
    )*
  ;
        
expr_relacional returns [string ret]
options {
  defaultErrorHandler=false; //noviable should be caught on expr
}
{
  string op2;
  string mn;
}
  : ret=expr_ad 
    (
      ( T_MAIOR {mn="gt";} | T_MAIOR_EQ {mn="ge";} | T_MENOR {mn="lt";} | T_MENOR_EQ {mn="le";} )
      op2=expr_ad
      {
         declareSubroutineVar( SymbolTable::GlobalScope, tempVar.getNew( ), 0, getSymbolType( op2 ) );
         subroutine->emitMnWithPrefix( mn, tempVar.getLast( ), ret, op2 );
         ret=tempVar.getLast( );
      }
    )*
  ;

expr_ad returns [string ret]
options {
  defaultErrorHandler=false; //noviable should be caught on expr
}
{
   string op2;
   string mn;
}
  : ret=expr_multip 
    (
      ( T_MAIS {mn="sum";} | T_MENOS {mn="sub";} )
      op2=expr_multip
      {
         declareSubroutineVar( SymbolTable::GlobalScope, tempVar.getNew( ), 0, getSymbolType( op2 ) );
         subroutine->emitMnWithPrefix( mn, tempVar.getLast( ), ret, op2 );
         ret=tempVar.getLast( );
      }
    )*
  ;

expr_multip returns [string ret]
options {
  defaultErrorHandler=false; //noviable should be caught on expr
}
{
  string op2;
  string mn;
}
  : ret=expr_unario
    (
      ( T_DIV {mn="div";} | T_MULTIP {mn="mul";} | T_MOD {mn="mod";} )
      op2=expr_unario
      {
         declareSubroutineVar( SymbolTable::GlobalScope, tempVar.getNew( ), 0, getSymbolType( op2 ) );
         subroutine->emitMnWithPrefix( mn, tempVar.getLast( ), ret, op2 );
         ret=tempVar.getLast( );
      } 
    )*
  ;

expr_unario returns [string ret]
options {
  defaultErrorHandler=false; //noviable should be caught on expr
}
  : ret=expr_elemento
  ;

op_unario
  : (
        e:T_MENOS
      | a:T_MAIS
      | n:T_KW_NOT
      | b:T_BIT_NOT
    )?
  ; 

expr_elemento returns [string ret]
  : (T_IDENTIFICADOR T_ABREP)=> ret=chamada_funcao
  | ret=lvalue
  | ret=literal
  | t:T_ABREP ret=expr T_FECHAP 
  ;

/////////////// LEXER DO GPTC /////////////////////////////

// -----------------Constant literals **********************

T_INT_LIT
options {
  paraphrase = "número inteiro";
}
  : ('0' ('c'|'C') )=> T_OCTAL_LIT
  | ('0' ('x'|'X') )=> T_HEX_LIT
  | ('0' ('b'|'B') )=> T_BIN_LIT
  | T_INTEGER_LIT 
    (
      '.' (T_DIGIT)+
      {$setType(T_REAL_LIT);}
    )?
  ;

protected
T_INTEGER_LIT
  : (T_DIGIT)+
  ;

T_CARAC_LIT
options {
  paraphrase = "caractere";
}
  : '\'' ( ~( '\'' | '\\' ) | ESC )? '\''
  ;

T_STRING_LIT
options {
  paraphrase = "literal";
}
  : '"' ( ~( '"' | '\\' | '\n' | '\r') | ESC)* '"'
  ;


protected
ESC
  //: '\\' ('n'| 't' | 'r' | '\\' | '\'' | '"')
  : '\\' . //permite "\a" (possibilida ser avaliado posteriormente como "a")
  ;

T_WS_ : (' '
  | '\t'
  | '\n' { newline(); }
  | '\r')
    { $setType(antlr::Token::SKIP); }
  ;

SL_COMMENT
  : "//" (~('\n'))* ('\n')?
    { 
      newline();
      $setType(antlr::Token::SKIP);
    }
  ;

ML_COMMENT
{int line = getLine();}
  : "{*" 
    ( 
      options { generateAmbigWarnings=false; } :  
        '\n'                     {newline();}
      | ('\r' '\n')=> '\r' '\n'  {newline();}
      | '\r'                     {newline();}
      |~('*'|'\n'|'\r')
      | ('*' ~'/' )=> '*' 
    )* 
    "*}"
    {$setType(antlr::Token::SKIP);}
  ;

T_ASM_CODE
{int line = getLine();}
  : '{'!
    ( 
      options { generateAmbigWarnings=false; } :  
        '\n'                     {newline();}
      | ('\r' '\n')=> '\r' '\n'  {newline();}
      | '\r'                     {newline();}
      |~('}')
    )* 
    '}'!
  ;

exception
catch[antlr::RecognitionException] {  
  stringstream s;
  s << "AVISO: comentário iniciado na linha " << line << " não termina com \"*}\".";
  GPTDisplay::self()->add(s.str(), getLine());

  _ttype = antlr::Token::SKIP;
}

protected
T_ID_AUX
  : (T_LETTER | '_') (T_LETTER_OR_DIGIT)*
  ;

protected
T_LETTER_OR_DIGIT
  : T_LETTER | T_DIGIT | '_'
  ;

T_IDENTIFICADOR
options {
  testLiterals = true;
}
  { int m=-1,len; hasLatim=false;}
  
  : T_ID_AUX
      {
        len=$getText.length();
        if(LA(1)=='-') {
          m=mark();          
        }
      }
      
    ('-' (T_LETTER_OR_DIGIT)*)?
  {
    
    if(m != -1) {
      if(testLiteralsTable(_ttype) == T_IDENTIFICADOR) {
        rewind(m);
        std::string s = $getText;
        $setText(s.substr(0,len));
      }
    }

    if(hasLatim && (testLiteralsTable(_ttype) == T_IDENTIFICADOR)) {
      stringstream s;
      s << "Identificador \"" << $getText << "\" não pode ter caracteres especiais.";
      GPTDisplay::self()->add(s.str(), getLine());
    }
  }
  ;


protected
T_DIGIT
  : '0'..'9'
  ;

protected
T_LETTER
  : 'a'..'z'|'A'..'Z' | {hasLatim=true;}'\u00C0' .. '\u00FF' 
  ;


protected
T_INVALID
  : . 
    {
      //caractere de espaco alem da tabela ascii ( [160] == [-96] == ' ' == [32] == 160-128)
      if($getText.c_str()[0] == (int)0xffffffa0) {
        $setType(antlr::Token::SKIP);
      } else {
        stringstream s;
        if(($getText != "\"") && ($getText != "'")) {
          s << "Caractere inválido: \"" << $getText << "\"";
        } else {
          s << "Faltando fechar aspas";
        }
        GPTDisplay::self()->add(s.str(), getLine());
      }
    }
  ;

*/

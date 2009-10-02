///####################################################################
///####################### Inicio da gramatica ########################
///####################################################################

///#################
///## File Struct ##
///#################

grammar ubibind;

options
{
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
}

@lexer::members
{
	static ANTLR3_BOOLEAN enumIsKeyword = ANTLR3_TRUE;
}

@header {
	extern "C++" {
		#include <fstream>
//		#include "Tools.hpp"
		#include "UbibindDefs.hpp"
		#include "BindSources.hpp"
	}
	#include <stdlib.h>
}

@members {
	CBindSources bindSource;
	#define GETTEXT(token) std::string((const char*)(token->getText(token))->chars)
}

@after {
}

// starting point for parsing a ubibind file
///----------
   compilation_unit [SParamOptions options] :
///----------
	module_declaration
	raw_definition
	(linker_libs_definition)?
	{ bindSource.writeHeaders(); }
	(typemap)*
	(interface_definition)*
	EOF
	{
		bindSource.writeFooters();
		std::ofstream out(options.outputFilename.c_str(), std::ios_base::out);
		out << bindSource.getCppText();
		std::ofstream out2("Makefile", std::ios_base::out);
		out2 << bindSource.getMakefileText();
	}
	;

///----------
   module_declaration :
///----------
	'%module' IDENTIFIER { bindSource.setModuleName(GETTEXT($IDENTIFIER)); }
	;

///----------
   raw_definition :
///----------
	RAW_DEFINITION { bindSource.setDefinitions(GETTEXT($RAW_DEFINITION)); }
	;

///----------
   linker_libs_definition
///----------
	:	'%linkerlibs' '=' (IDENTIFIER {bindSource.addLinkerLib(GETTEXT($IDENTIFIER));})+ ';'
	;

///----------
   typemap
///----------
@declarations {
	std::string typeFrom;
	std::string typeTo;
	int typemapType;
}
	:	'%typemap' ('in'{typemapType=1;}|'out'{typemapType=2;})
		type1From=IDENTIFIER {typeFrom=GETTEXT($type1From);} (type2From=IDENTIFIER {typeFrom += " " + GETTEXT($type2From);})* ('*' {typeFrom += "*"; })*
		'='
		type1To=IDENTIFIER {typeTo=GETTEXT($type1To);} (type2To=IDENTIFIER {typeTo += " " + GETTEXT($type2To);})* ('*' {typeTo += "*"; })* ';'
		{if (typemapType == 1) bindSource.addTypeMapIn(typeFrom, typeTo); else bindSource.addTypeMapOut(typeFrom, typeTo);}
	;

///----------
   interface_definition :
///----------
	function_definition
	;

///----------
   function_definition
///----------
@declarations
{
	std::vector<std::string> parameters;
}
	:	type IDENTIFIER '(' (parameters_list[parameters])? ')' ';'
		{ bindSource.addFunction($type.sret, GETTEXT($IDENTIFIER), parameters); }
	;

///----------
   parameters_list [std::vector<std::string> &parameters]
///----------
	:	param1=param_definition {parameters.push_back($param1.ret);} ( ',' param2=param_definition {parameters.push_back($param2.ret);} )*
	;

///----------
   param_definition returns [int bogus, std::string ret]
///----------
	:	id1=IDENTIFIER {$ret += GETTEXT($id1);} (id2=IDENTIFIER {$ret += " " + GETTEXT($id2);} | '*' {$ret += '*';} )*
	;

/////----------
//   parameters_definition [std::vector<std::pair<std::string,std::string> > &parameters]
/////----------
////@declarations
////{
////	std::string id;
////}
//	:	type1=type id1=IDENTIFIER { parameters.push_back(std::pair<std::string, std::string>(GETTEXT($id1), $type1.sret)); }
//		( ',' type2=type id2=IDENTIFIER { parameters.push_back(std::pair<std::string, std::string>(GETTEXT($id2), $type2.sret)); } )*
//	;

///----------
   type returns [LiteralType iret, std::string sret] :
///----------
	id1=IDENTIFIER { $sret = GETTEXT($id1); } (id2=IDENTIFIER { $sret += " " + GETTEXT($id2); } )* ('*' { $sret += '*'; } )*
	;

/////----------
//   type returns [LiteralType iret, std::string sret] :
/////----------
//// TODO: nao poderia reconhecer sempre como IDENTIFIER ('*')*
//		'int'          { $iret = IntegerType;        $sret = "int";     }
//	|	'int' '*'      { $iret = IntegerPointerType; $sret = "int*";    }
//	|	'char'         { $iret = CharType;           $sret = "char";    }
//	|	'char' '*'     { $iret = CharPointerType;    $sret = "char*";   }
//	|	'double'       { $iret = DoubleType;         $sret = "double";  }
//	|	'double' '*'   { $iret = DoublePointerType;  $sret = "double*"; }
//	|	'float'        { $iret = FloatType;          $sret = "float";   }
//	|	'float' '*'    { $iret = FloatPointerType;   $sret = "float*";  }
//	|	IDENTIFIER     { $iret = UserType;           $sret = GETTEXT($IDENTIFIER);       }
//	|	IDENTIFIER '*' { $iret = UserPointerType;    $sret = GETTEXT($IDENTIFIER) + '*'; }
//	;



/////----------
//   type returns [LiteralType iret, std::string sret] :
/////----------
//	('const')?
//		'int'          { $sret = "int";     }
//	|	'int' '*'      { $sret = "int*";    }
//	|	'char'         { $sret = "char";    }
//	|	'char' '*'     { $sret = "char*";   }
//	|	'double'       { $sret = "double";  }
//	|	'double' '*'   { $sret = "double*"; }
//	|	'float'        { $sret = "float";   }
//	|	'float' '*'    { $sret = "float*";  }
//	|	IDENTIFIER     { $sret = GETTEXT($IDENTIFIER);       }
//	|	IDENTIFIER '*' { $sret = GETTEXT($IDENTIFIER) + '*'; }
//	;



/////----------
//   var_assignment_statement
/////----------
//@declarations
//{
//   std::vector<std::string> idList;
//}
//   :  Id1=IDENTIFIER { idList.push_back(GETTEXT($Id1)); }
//      (
//         ',' Id2=IDENTIFIER { idList.push_back(GETTEXT($Id2)); }
//      )*
//      '=' expr
//      {
//         for(std::vector<std::string>::iterator id = idList.begin(); id != idList.end(); id++) {
//            methodDef->addInstruction(STVAR_OPCODE, methodDef->getVarIndex((*id)));
//         }
//      }
//   ;

/////----------
//   argument_list returns [uint args]
/////----------
//   :  argument {$args++;} (',' argument {$args++;} )*
//   ;


/////----------------------
//   parameters_declaration[std::vector<std::pair<std::string, std::pair<std::string,std::string> > > &parameters]
/////----------------------
//{
//   std::pair<std::string,std::string> typeValue;
//}
//   : T_ABREP
//     (
//        typeValue=type tk_id:T_ID
//        {parameters.push_back(std::pair<std::string, std::pair<std::string,std::string> >(tk_id->getText(), typeValue));} 
//        (
//           T_COMMA typeValue=type tk_id2:T_ID
//           {parameters.push_back(std::pair<std::string, std::pair<std::string,std::string> >(tk_id2->getText(), typeValue));} 
//        )*
//     )?
//     T_FECHAP
//   ;


/////----------
//   argument
/////----------
//   :  expr
//   |  literal
//   |  'nil'          { methodDef->addInstruction(LDNIL_OPCODE); }
//   ;

/////----------
//   context returns [int teste, std::string value] // teste nao eh necessario... mas qdo so tem um parametro, antlr gera codigo para inicializar value como "NULL"
/////----------
//   :  'identity' { $value = "identity"; }
//   |  'location' { $value = "location"; }
//   |  'activity' { $value = "avtivity"; }
//   |  'time'     { $value = "time";     }
//   ;


//$$$$$$$$$$$$$$$$$$$$$$


// LEXER

INTEGER_LITERAL : ('0'..'9')+ ;

REAL_LITERAL
   :  ('0'..'9')+ '.' ('0'..'9')+
   |  '.' ('0'..'9')+
   ;

CHARACTER_LITERAL
    :   '\'' ( ESCAPE_SEQUENCE | ~('\''|'\\') ) '\''
    ;

STRING_LITERAL returns [const char* ret] // ou pANTLR3_STRING ???
//@after{
////	setText(getText().substring(1, getText().length()-1));
//}
    :  '"' ( ESCAPE_SEQUENCE | ~('\\'|'"') )* '"'
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

BOOLEAN_LITERAL
   : 'true' | 'false'
   ;

fragment
ESCAPE_SEQUENCE
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    ;

IDENTIFIER
   :  LETTER (LETTER|DIGIT|'_')*
   ;

RAW_DEFINITION
    :   '%{' ( options {greedy=false;} : . )* '%}'
    ;

fragment
LETTER: 'a'..'z' | 'A'..'Z';

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


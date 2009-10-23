#include <iostream>

#include "BindSources.hpp"

#include "Tools.hpp"


CBindSources::CBindSources()
{
   _mapToCppType["string"] = "const char*";
   _mapToCppType["real"  ] = "double";
   _mapToCppType["int"   ] = "int";
   _mapToCppType["char"  ] = "int";
   _mapToCppType["bool"  ] = "boolean";



   _mapPop["void*"       ] = "dataStack.pop().getInteger()";
   _mapPop["const void*" ] = "dataStack.pop().getInteger()";
   _mapPop["char"        ] = "dataStack.pop().getInteger()";
   _mapPop["char*"       ] = "dataStack.pop().getString().c_str()";
   _mapPop["const char"  ] = "dataStack.pop().getInteger()";
   _mapPop["const char*" ] = "dataStack.pop().getInteger()";
   _mapPop["short"       ] = "dataStack.pop().getInteger()";
   _mapPop["short*"      ] = "dataStack.pop().getInteger()";
   _mapPop["const short" ] = "dataStack.pop().getInteger()";
   _mapPop["const short*"] = "dataStack.pop().getInteger()";
   _mapPop["int"         ] = "dataStack.pop().getInteger()";
   _mapPop["int*"        ] = "dataStack.pop().getInteger()";
   _mapPop["const int"   ] = "dataStack.pop().getInteger()";
   _mapPop["const int*"  ] = "dataStack.pop().getInteger()";
   _mapPop["bool"              ] = "dataStack.pop().getInteger()";
   _mapPop["bool*"             ] = "dataStack.pop().getInteger()";
   _mapPop["const bool"        ] = "dataStack.pop().getInteger()";
   _mapPop["const bool*"       ] = "dataStack.pop().getInteger()";
   _mapPop["long"        ] = "dataStack.pop().getInteger()";
   _mapPop["long*"       ] = "dataStack.pop().getInteger()";
   _mapPop["const long"  ] = "dataStack.pop().getInteger()";
   _mapPop["const long*" ] = "dataStack.pop().getInteger()";
   _mapPop["float"       ] = "dataStack.pop().getReal()";
   _mapPop["float*"      ] = "dataStack.pop().getInteger()";
   _mapPop["const float" ] = "dataStack.pop().getReal()";
   _mapPop["const float*"] = "dataStack.pop().getInteger()";
   _mapPop["double"      ] = "dataStack.pop().getReal()";
   _mapPop["double*"     ] = "dataStack.pop().getInteger()";
   _mapPop["const double" ] = "dataStack.pop().getReal()";
   _mapPop["const double*"] = "dataStack.pop().getInteger()";
   _mapPop["long double" ] = "dataStack.pop().getReal()";
   _mapPop["long double*"] = "dataStack.pop().getInteger()";
   _mapPop["const long double" ] = "dataStack.pop().getReal()";
   _mapPop["const long double*"] = "dataStack.pop().getInteger()";

   addTypeMapIn("char",        "char");
   addTypeMapIn("char*",       "char*");
   addTypeMapIn("short",       "short");
   addTypeMapIn("short*",      "short*");
   addTypeMapIn("int",         "int");
   addTypeMapIn("int*",        "int*");
   addTypeMapIn("bool",        "bool");
   addTypeMapIn("bool*",       "bool*");
   addTypeMapIn("long",        "long");
   addTypeMapIn("long*",       "long*");
   addTypeMapIn("float",       "float");
   addTypeMapIn("float*",      "float*");
   addTypeMapIn("double",      "double");
   addTypeMapIn("double*",     "double*");
   addTypeMapIn("long double", "long double");
}


void CBindSources::writeHeaders()
{
//   hppSource.writeln( "#ifndef GPTBIND_" + _filename + "_HPP" );
//   hppSource.writeln( "#define GPTBIND_" + _filename + "_HPP" );
//   hppSource.writeln();
//
//   for(std::list<std::string>::iterator header = _headerList.begin(); header != _headerList.end(); header++) {
//      std::string sheader = (*header).substr(1, (*header).length()-2);
//      hppSource.writeln( "#include <" + sheader + ">" );
//   }
//   hppSource.writeln();
//
//   hppSource.writeln( "#include \"CDataStack.hpp\"" );
//   hppSource.writeln();
//
//   hppSource.writeln( "extern \"C\" {" );
//   hppSource.incTab();

//    cppSource.writeln( "#include \"" + _moduleName + ".hpp\"" );
//    cppSource.writeln();
	cppSource.writeln("#include \"DataStack.hpp\"");
	cppSource.writeln();
	
	cppSource.writeln(_definitions);
	cppSource.writeln();

	makefileSource.writeln("LIBUVM=../../libuvm/");
	makefileSource.writeln("UBIVM=../../ubivm");
	makefileSource.writeln("LIBCOMMON=../../libcommon/");
	makefileSource.writeln("INCLUDE_DIR=-I$(LIBUVM) -I$(UBIVM) -I$(LIBCOMMON) -I../ -I/usr/local/include/boost-1_39/");
	makefileSource.writeln("CC=g++");
	makefileSource.writeln("CCFLAGS=-g -Wall -pedantic");
	makefileSource.write("LIBS=");

	for(std::list<std::string>::iterator lib = _linkerLibList.begin(); lib != _linkerLibList.end(); lib++) {
		makefileSource.write("-l" + (*lib) + " ");
    }
	makefileSource.writeln();
	makefileSource.writeln();

	makefileSource.writeln("OBJECTS = uvm_os_" + _moduleName + ".o");
	makefileSource.writeln();

	makefileSource.writeln("LIBNAME = libuvm_os_" + _moduleName);
	makefileSource.writeln();

	makefileSource.writeln("all: $(OBJECTS)");
makefileSource.writeln("\tg++ -shared -o $(LIBNAME).so $(OBJECTS) $(LIBS)");
	makefileSource.writeln();

	makefileSource.writeln("%.cpp:");
	makefileSource.writeln("\t../ubibind " + _moduleName + ".bind");
	makefileSource.writeln();
	
	makefileSource.writeln("%.o: %.cpp");
	makefileSource.writeln("\t$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@");
	makefileSource.writeln();

	makefileSource.writeln("clean:");
	makefileSource.writeln("\trm -f *.o $(LIBNAME).so $(OBJECTS) core uvm_os_" + _moduleName + ".cpp");
}


// void CBindSources::addSubroutineBind(
//       const std::string &name,
//       const std::pair<std::string, std::string> &returnType,
//       std::vector<std::pair<std::string, std::pair<std::string, std::string> > > parameters,
//       const std::string &functionBind,
//       std::vector<std::string> arguments )
// {
//   hppSource.writeln( "void gsl_" + name + "( CDataStack &dataStack );" );

/*   cppSource.writeln();
   cppSource.writeln( "void gsl_" + name + "( CDataStack &dataStack )" );
   cppSource.writeln( "{" );
   cppSource.incTab();

   for(std::vector<std::pair<std::string, std::pair<std::string,std::string> > >::iterator param = parameters.begin(); param != parameters.end(); param++) {
      cppSource.writeln (sourceToPopParameter (param->first, param->second));
   }

   if (!returnType.first.empty()) {
      cppSource.writeln(getMapGptToCppType(returnType) + " result;");
      cppSource.writeln();
      cppSource.write( "result=" );
   }

   cppSource.write(functionBind + "(");

   for(std::vector<std::string>::iterator arg = arguments.begin(); arg != arguments.end(); arg++) {
      if (arg != arguments.begin()) {
         cppSource.write(", ");
      }
      if ((*arg)[0] != '"') {
         cppSource.write("c" + *arg);
      } else {
         cppSource.write(*arg);
      }
   }
   cppSource.writeln(");");
   if (!returnType.first.empty()) {
      cppSource.writeln();
      cppSource.writeln(sourceToPushResult("result", returnType));
   }
   cppSource.decTab();
   cppSource.writeln( "}" );*/
// }


std::string CBindSources::codeToPopParameter(const std::string &name, const std::string &ctype)
{
   std::string result;


   result += ctype + " " + name + "= (" + ctype + ") ";

   if (_mapPop.find(ctype) != _mapPop.end()) {
	   result += _mapPop[ctype];
   } else {
	   std::cout << "Error: Undefined ctype " << ctype << std::endl;
	   result += "ERROR_UNDEFINED_CTYPE_" + ctype;
   }

   result += ";";

   return result;
}

// std::string CBindSources::codeToPopParameter(const std::string &name, const std::string &ctype)
// {
//    std::string result;
// 
// 
//    result += ctype + " " + name + "=";
// 
//    if (_mapPop.find(ctype) != _mapPop.end()) {
// 	   result += _mapPop[ctype];
//    } else {
// 	   result += _mapPop["int*"];
//    }
// 
//    result += ";";
// 
//    return result;
// }

// std::string CBindSources::codeToPopParameter(const std::string &name, const std::string &ctype)
// {
//    std::string result;
// 
//    std::map<std::string, std::string> mapPop;
//    mapPop["string"] = "dataStack.pop().getString().c_str()";
//    mapPop["real"  ] = "dataStack.pop().getReal()";
//    mapPop["int"   ] = "dataStack.pop().getInteger()";
//    mapPop["char"  ] = "dataStack.pop().getInteger()";
//    mapPop["bool"  ] = "dataStack.pop().getBool()";
// 
//    result = getMapGptToCppType(ctype) + " " + name + "=";
// 
// //    if (type.first == "pointer") {
// //       result += "(" + type.second + "*)" + mapPop["int"];
// //    } else {
// //       result += mapPop[type.first];
// //    }
//    result += mapPop[type];
//    result += ";";
// 
//    return result;
// }


std::string CBindSources::codeToPushResult(const std::string &name, const std::string &type)
{
   std::string result;

/*   std::map<std::string, std::string> mapPush;
   mapPush["string"] = "dataStack.pushString(" + name + ")";
   mapPush["real"  ] = "dataStack.pushReal(" + name + ")";
   mapPush["int"   ] = "dataStack.pushInt(" + name + ")";
   mapPush["char"  ] = "dataStack.pushInt(" + name + ")";
   mapPush["bool"  ] = "dataStack.pushBool(" + name + ")";
   mapPush["pointer"] = "dataStack.pushInt((int)" + name + ")";

	// TODO: na ubivm nao eh sempre dataStack.push ???

   result = mapPush[type] + ";";*/
   result = "dataStack.push(" + name + ")";

   return result;
}


void CBindSources::writeFooters()
{
//    for(std::list<std::string>::iterator lib = _linkerLibList.begin(); lib != _linkerLibList.end(); lib++) {
//       std::string slib = (*lib).substr(1, (*lib).length()-2);
//       makefileSource.write("-l" + slib + " ");
//    }
}


void CBindSources::addLinkerLib(const std::string &lib)
{
   _linkerLibList.push_back(lib);
}


void CBindSources::addHeader(const std::string &header)
{
   _headerList.push_back(header);
}


std::string CBindSources::getMapGptToCppType(const std::string &type)
{
//    if (type.first == "pointer") {
//       return type.second + "*";
//    } else {
//       return _mapToCppType[type.first];
//    }
      return _mapToCppType[type];
}

void CBindSources::setModuleName(std::string moduleName)
{
	_moduleName = moduleName;
}

void CBindSources::setDefinitions(std::string definitions)
{
	_definitions = definitions.substr(2, definitions.length()-4);
}

void CBindSources::addFunction(std::string returnType, std::string functionName, std::vector<std::string> parameters)
{
	std::vector<std::string> paramType;
	std::vector<std::string> paramName;
	int paramNumber;
//   hppSource.writeln( "void gsl_" + name + "( CDataStack &dataStack );" );

	// Verify if are named parameters. If not, define a name.
	paramNumber = 1;
	for(std::vector<std::string>::iterator param = parameters.begin(); param != parameters.end(); param++) {
		if (*param == "void") {
			continue;
		}
		std::string name;
		std::string type;
		if (_mapPop.find(*param) != _mapPop.end()) {
			// Parameter name not informed...
			type = *param;
			name = std::string("p") + std::string(itoa(paramNumber++));
		} else {
			// Parameter name informed...
			type = (*param).substr(0, (*param).find_last_of(' '));
			name = (*param).substr((*param).find_last_of(' ')+1);
		}
		paramType.push_back(type);
		paramName.push_back(name);
	}

	cppSource.writeln( "extern \"C\" void uvm_os_wrap_lib" + _moduleName + "_" + functionName + "(CDataStack& dataStack)" );
	cppSource.writeln( "{" );
	cppSource.incTab();

	for(paramNumber=paramType.size()-1; paramNumber>=0; paramNumber--) {
		cppSource.writeln(codeToPopParameter(paramName[paramNumber], paramType[paramNumber]));
	}

   if (returnType != "void") {
      cppSource.write(returnType + " result=" + functionName + "(");
   } else {
		cppSource.write(functionName + "(");
   }

/*   for(std::vector<std::string>::iterator arg = arguments.begin(); arg != arguments.end(); arg++) {
      if (arg != arguments.begin()) {
         cppSource.write(", ");
      }
      if ((*arg)[0] != '"') {
         cppSource.write("c" + *arg);
      } else {
         cppSource.write(*arg);
      }
   }*/

	for(paramNumber=0; paramNumber < paramName.size(); paramNumber++) {
		if (paramNumber != 0) {
			cppSource.write( ", " );
		}
		cppSource.write( paramName[paramNumber] );
	}

	cppSource.writeln(");");
   if (returnType != "void") {
      cppSource.writeln();
	  if (_mapPush.find(returnType) == _mapPush.end()) {
		  std::cout << "Error: Undefined type " << returnType << " in mapPush" << std::endl;
		  _mapPush[returnType] = "UNDEFINED_TYPE_" + returnType;
	  }
      cppSource.writeln("dataStack.push( (" + _mapPush[returnType] + ") result);");
//       cppSource.writeln(codeToPushResult("result", returnType));
   }
   cppSource.decTab();
   cppSource.writeln( "}" );
   cppSource.writeln( );
}

void CBindSources::addTypeMapIn(std::string mapFrom, std::string mapTo)
{
	// TODO: nesse mapeamento eu nao deveria especificar uma equivalente entre C e UbiL ???
	std::cout << "mapPush[" << mapFrom << "]=" << mapTo << std::endl;
   _mapPush[mapFrom] = mapTo;
   _mapPush["const " + mapFrom]       = "const " + mapTo;
//    _mapPush["const " + mapFrom + "*"] = "const " + mapTo + "*";
//    _mapPush[mapFrom + "*"]            = mapTo + "*";
   // TODO: tem problema em, para um tipo T, assumir tb as variacoes como "const T, const T* e T*" ???
}

void CBindSources::addTypeMapOut(std::string mapFrom, std::string mapTo)
{
	if (_mapPop.find(mapTo) == _mapPop.end()) {
		std::cout << "Undefined map " << mapTo << ". Using default (int)" << std::endl;
		mapTo="int";
	}
   _mapPop[mapFrom] = _mapPop[mapTo];
}

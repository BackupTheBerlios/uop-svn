#include <sstream>
#include <iostream>
#include <dlfcn.h>

#include <boost/foreach.hpp>
#include <boost/tuple/tuple.hpp>
#define foreach BOOST_FOREACH

#include "RunBytecode.hpp"
#include "Log.hpp"
#include "Element.hpp"
#include "GroupProvider.hpp"
#include "UbiVM.hpp"

uint CRunBytecode::_bceCount = 0;

CRunBytecode::CRunBytecode()
	: _dataReady(false), _listdReplyTable(NULL), _returnCode(0)
{
	_options           = CUbiVM::getInstance()->getOptions();
	_asmDef            = CUbiVM::getInstance()->getAsmDef();
	_syslibHandlerList = CUbiVM::getInstance()->getSyslibHandlerList();
	_elementList       = CUbiVM::getInstance()->getElementList();
	_contextList       = CUbiVM::getInstance()->getContextList();
	_contextsInfo      = CUbiVM::getInstance()->getContextsInfo();

	_initOpcodePointer();
	CContextProvider::getInstance()->register_bce(_bceCount, this);
	_vmId = SVmId(getpid(), _bceCount++); // TODO: colocar pid e IP
}


CRunBytecode::~CRunBytecode()
{
}



int CRunBytecode::run()
{
// 	_cp->register_bce(1, this);
   //std::cout << "Code lido: [" << _code.getBinary() << "]" << " size=" << _code.getBinary().size() << std::endl;
//   std::cout << "Code size=" << _code.size() << std::endl;

   // Empilha referencia para entidade start
//    uint startIndex = _symbolTable.getSymbolIndex("start", StringType);
//    _dataStack.push(CLiteral(IntegerType, &startIndex));
//    newOpcode(); // new recebe na datastack ou como argumento a entidade a ser instanciada ???
//    _dataStack.push(_asmDef.getEntity("start")->getMethod("start"));
//    mcallOpcode(); // mas mcall recebe como argumento, e nao na datastack :-/
   // TODO: uma forma seria gerar um bytecode especifico para instanciar e executar o metodo correto... com isso daria para passar o q fosse necessario como argumento para invocar new, mcallopcode, ...


	CElement* element = new CElement(CUbiVM::getInstance()->getAsmDef()->getEntity("start"));

	if (element == NULL) {
		std::cout << "Entidade " << "start" << " nao encontrada !!!" << std::endl;
		return 1;
	}

	CActivationRecord* ar = new CActivationRecord(this, element, "constructor", _ip, _dataStack);

	_controlStack.push(ar);

	_stop = false;

	while (!_stop) {
		step();
	}

	ar->restore_state(_dataStack, _ip);

	delete ar;

	return _returnCode;
}



// int CRunBytecode::run(std::string entity_name, CElement* element)
// {
//    //std::cout << "Code lido: [" << _code.getBinary() << "]" << " size=" << _code.getBinary().size() << std::endl;
// //   std::cout << "Code size=" << _code.size() << std::endl;
//
//    // Empilha referencia para entidade start
// //    uint startIndex = _symbolTable.getSymbolIndex("start", StringType);
// //    _dataStack.push(CLiteral(IntegerType, &startIndex));
// //    newOpcode(); // new recebe na datastack ou como argumento a entidade a ser instanciada ???
// //    _dataStack.push(_asmDef.getEntity("start")->getMethod("start"));
// //    mcallOpcode(); // mas mcall recebe como argumento, e nao na datastack :-/
//    // TODO: uma forma seria gerar um bytecode especifico para instanciar e executar o metodo correto... com isso daria para passar o q fosse necessario como argumento para invocar new, mcallopcode, ...
//
//
//    //_code.setIP(0); // TODO: pegar o endereco de main
//
// 	if (element == NULL) {
// 		element = new CElement(_asmDef->getEntity(entity_name));
// 		_elementList->push_back(element); // uso no runs para encontrar a entidade que executa um servico... nao ta bem certo :-/
// 		_dataStack.push(CLiteral(element));
// 	}
//
//    _ip.element = element;
//
//    if (_ip.element == NULL) {
// 	   std::cout << "Entidade " << entity_name << " nao encontrada !!!" << std::endl;
//    }
//
// //   std::cout << "Entidade start encontrada !!!" << std::endl;
//
//    _ip.method  = _ip.element->getMethod(entity_name);
//
//    if (_ip.method == NULL) {
// 	   std::cout << "Metodo " << entity_name << " nao encontrado !!!" << std::endl;
//    }
//
// //   std::cout << "Metodo start encontrado !!!" << std::endl;
//
// 	// Define variaveis locais
// 	// TODO: isso deve ficar definido no metodo...
// //	_localVarList.clear();
// //	_localVarList.reserve(_ip.method->_localVarList.size());
//
// //	std::cout << "Criando as variaveis locais do metodo..." << std::endl;
//
// 	CActivationRecord* ar = new CActivationRecord();
//
// 	for(std::vector<CLocalVarDefinition*>::iterator var = _ip.method->_localVarList.begin();
// 		var != _ip.method->_localVarList.end(); var++) {
// 		ar->_localVarList.push_back(CLiteral((*var)->_type));
// 	}
//
// 	ar->_ip = _ip;
//
// 	_controlStack.push(ar);
//
// 	// TODO: fazer o mesmo para os parametros... resultados..
//
//
//    _ip.ip      = 0;
//
// 	if (_asmDef->getEntity(entity_name)->isParallel()) {
// 		element->_thread = new boost::thread( boost::bind( &CRunBytecode::run_bytecode, this));
// 	} else {
// 		run_bytecode();
// 	}
//
//    return _returnCode;
// }


void CRunBytecode::run_bytecode()
{
	_stop = false;

	while (!_stop) {
		step();
	}
}


void CRunBytecode::run_bytecode_until(unsigned char return_after_opcode)
{
	_stop = false;

	while (!_stop) {
		if (step() == return_after_opcode) {
			break;
		}
	}
}


void CRunBytecode::_initOpcodePointer()
{
	for (int i = 0; i < OPCODE_COUNT; i++) {
	   // TODO: se for assim pode ser um memset...
		_opcodePointer[i] = NULL; //&CRunBytecode::invalidOpcode;
	}

//   _opcodePointer[OP_NOP        ] = &CRunBytecode::nopOpcode;
//   _opcodePointer[OP_PCALL      ] = &CRunBytecode::pcallOpcode;
	_opcodePointer[LCALL_OPCODE    ] = &CRunBytecode::lcallOpcode;
	_opcodePointer[LDVAR_OPCODE    ] = &CRunBytecode::ldvarOpcode;
	_opcodePointer[STVAR_OPCODE    ] = &CRunBytecode::stvarOpcode;
	_opcodePointer[STRESULT_OPCODE ] = &CRunBytecode::stresultOpcode;
	_opcodePointer[LDCONST_OPCODE  ] = &CRunBytecode::ldconstOpcode;
	_opcodePointer[LDPARAM_OPCODE  ] = &CRunBytecode::ldparamOpcode;
	_opcodePointer[STOP_OPCODE     ] = &CRunBytecode::stopOpcode;
	_opcodePointer[RET_OPCODE      ] = &CRunBytecode::retOpcode;
	_opcodePointer[MCALL_OPCODE    ] = &CRunBytecode::mcallOpcode;
	_opcodePointer[ADD_OPCODE      ] = &CRunBytecode::addOpcode;    // TODO: trocar ADD por SUM
	_opcodePointer[SUB_OPCODE      ] = &CRunBytecode::subOpcode;
	_opcodePointer[MUL_OPCODE      ] = &CRunBytecode::mulOpcode;
	_opcodePointer[DIV_OPCODE      ] = &CRunBytecode::divOpcode;
	_opcodePointer[LT_OPCODE       ] = &CRunBytecode::ltOpcode;
	_opcodePointer[GT_OPCODE       ] = &CRunBytecode::gtOpcode;
	_opcodePointer[LE_OPCODE       ] = &CRunBytecode::leOpcode;
	_opcodePointer[GE_OPCODE       ] = &CRunBytecode::geOpcode;
	_opcodePointer[EQ_OPCODE       ] = &CRunBytecode::eqOpcode;
	_opcodePointer[NE_OPCODE       ] = &CRunBytecode::neOpcode;
	_opcodePointer[AND_OPCODE      ] = &CRunBytecode::andOpcode;
	_opcodePointer[OR_OPCODE       ] = &CRunBytecode::orOpcode;
	_opcodePointer[IFNOT_OPCODE    ] = &CRunBytecode::ifnotOpcode;
	_opcodePointer[JMP_OPCODE      ] = &CRunBytecode::jmpOpcode;
	_opcodePointer[LDSELF_OPCODE   ] = &CRunBytecode::ldselfOpcode;
	_opcodePointer[NEWELEM_OPCODE  ] = &CRunBytecode::newelemOpcode;
	_opcodePointer[JOINC_OPCODE    ] = &CRunBytecode::joincOpcode;
	_opcodePointer[PUBLISHD_OPCODE   ] = &CRunBytecode::publishdOpcode;
	_opcodePointer[GETD_OPCODE  ] = &CRunBytecode::getdOpcode;
	_opcodePointer[FINDD_OPCODE   ] = &CRunBytecode::finddOpcode;
	_opcodePointer[GETDNB_OPCODE  ] = &CRunBytecode::getdnbOpcode;
	_opcodePointer[FINDDNB_OPCODE   ] = &CRunBytecode::finddnbOpcode;
	_opcodePointer[LISTD_OPCODE ] = &CRunBytecode::listdOpcode;
	_opcodePointer[STCONTEXTI_OPCODE] = &CRunBytecode::stcontextiOpcode;
	_opcodePointer[LDCONTEXTI_OPCODE] = &CRunBytecode::ldcontextiOpcode;
	_opcodePointer[PUBLISHS_OPCODE ] = &CRunBytecode::publishsOpcode;
	_opcodePointer[REMOVES_OPCODE  ] = &CRunBytecode::removesOpcode;
	_opcodePointer[RUNS_OPCODE     ] = &CRunBytecode::runsOpcode;
	_opcodePointer[STTAB_OPCODE    ] = &CRunBytecode::sttabOpcode;
	_opcodePointer[LDTAB_OPCODE    ] = &CRunBytecode::ldtabOpcode;
	_opcodePointer[LDTUPLEK_OPCODE ] = &CRunBytecode::ldtuplekOpcode;
	_opcodePointer[LDTUPLEV_OPCODE ] = &CRunBytecode::ldtuplevOpcode;
	_opcodePointer[TABSIZE_OPCODE  ] = &CRunBytecode::tabsizeOpcode;
	_opcodePointer[LDPROP_OPCODE   ] = &CRunBytecode::ldpropOpcode;
	_opcodePointer[STPROP_OPCODE   ] = &CRunBytecode::stpropOpcode;
	_opcodePointer[BELEMENTEV_OPCODE] = &CRunBytecode::belementevOpcode;
	_opcodePointer[BCONTEXTIEV_OPCODE] = &CRunBytecode::bcontextievOpcode;
	_opcodePointer[BCONTEXTEV_OPCODE]   = &CRunBytecode::bcontextevOpcode;
}


unsigned char CRunBytecode::step()
{
	_currentInstruction = _ip.method->getInstruction(_ip.ip);

    unsigned char opcode = _currentInstruction->_opcode;
	_ip.ip++;

   if (opcode >= OPCODE_COUNT) {
      error( "Invalid opcode !!!" );
	  return INVALID_OPCODE;
   }

   if (_opcodePointer[opcode] == NULL) {
	   std::cout << "Opcode " << _currentInstruction->getTextOpcode() << " nao implementado !!!" << std::endl;
	   exit(1);
   }

    (this->*_opcodePointer[(int)opcode])();

	return opcode;
}

void CRunBytecode::trace(const std::string &message)
{
   //std::cout << message << std::endl;
}

void CRunBytecode::error(const std::string &message)
{
   std::cerr << message << std::endl;
   abort();
}

void CRunBytecode::procWriteln()
{
//	std::cout << "Opcode writeln: ";
   int argNumber = _dataStack.pop().getInteger();
   //int argNumber = _ip.element->getSymbolByIndex(_dataStack.pop().getInteger())->getInteger();
   std::string out;

   for (int arg=0; arg < argNumber; arg++) {
	   // por enquanto so strings...
	   out = _dataStack.pop().getText() + out;
	   //std::cout << _ip.element->getSymbolByIndex(_dataStack.pop())->_name;
   }
   std::cout << out << std::endl;
}


void CRunBytecode::procWrite()
{
	int argNumber = _dataStack.pop().getInteger();
	std::string out;

	for (int arg=0; arg < argNumber; arg++) {
		out = _dataStack.pop().getText() + out;
	}
	std::cout << out;
}


void CRunBytecode::procReadln()
{
	std::string text;
	std::cin >> text;

	_dataStack.push(text);
}


void CRunBytecode::procSleep()
{
   int time = _dataStack.pop().getInteger();

   sleep(time);
}


//void CRunBytecode::procImprima()
//{
//   int address = sizeof(int);
//   int argNumber = _dataStack.getInt(address|SET_LOCAL_BIT|SET_NEG_BIT);
//
//   for (int arg=0; arg < argNumber; arg++) {
//      address += sizeof(int);
//      int type = _dataStack.getInt(address|SET_LOCAL_BIT|SET_NEG_BIT);
//      int boolValue;
//      switch (type) {
//         case CSymbol::STRING:
//            address += sizeof(char) + sizeof(int);
//            std::cout << _dataStack.getString(address|SET_LOCAL_BIT|SET_NEG_BIT);
//            break;
//         case CSymbol::INT:
//            address += sizeof(int);
//            std::cout << _dataStack.getInt(address|SET_LOCAL_BIT|SET_NEG_BIT);
//            break;
//         case CSymbol::CHAR:
////            std::cout << (char)_dataStack.popInt();
//            address += sizeof(int);
//            std::cout << "char [" << (int)_dataStack.getInt(address|SET_LOCAL_BIT|SET_NEG_BIT) << "]";
//            break;
//         case CSymbol::BOOL:
//            address += sizeof(int);
//            boolValue = _dataStack.getInt(address|SET_LOCAL_BIT|SET_NEG_BIT);
//            if (boolValue == 0) {
//               std::cout << "false";
//            } else {
//               std::cout << "true";
//            }
//            break;
//         case CSymbol::REAL:
//            address += sizeof(double);
//            std::cout << _dataStack.getReal(address|SET_LOCAL_BIT|SET_NEG_BIT);
//            break;
//         case CSymbol::DATA:
//         case CSymbol::MATRIX:
//         default:
//            std::cout << "Tipo ainda nao suportado !!!" << std::endl;
//            abort();
//      }
//   }
//   std::cout << std::endl;
//   _dataStack.discardBytes(address);
//}
//
//
//void CRunBytecode::procLeia()
//{
//   int type = _dataStack.popInt();
//   int iValue = 0;
//   double dValue = 0.0;
//   switch (type) {
////      case CSymbol::STRING:
////         _dataStack.pushString(std::cin);
////         break;
//      case CSymbol::INT:
//         std::cin >> iValue;
//         _dataStack.pushInt(iValue);
//         break;
////      case CSymbol::CHAR:
////         std::cout << (char)_dataStack.popInt();
////         break;
////      case CSymbol::BOOL:
////         boolValue = _dataStack.popInt();
////         if (boolValue == 0) {
////            std::cout << "false";
////         } else {
////            std::cout << "true";
////         }
////         break;
//      case CSymbol::REAL:
//         std::cin >> dValue;
//         _dataStack.pushReal(dValue);
//         break;
//      case CSymbol::MATRIX:
//      default:
//         std::cout << "Tipo ainda nao suportado !!!" << std::endl;
//         abort();
//   }
//   std::cout << std::endl;
//}

//void CRunBytecode::popRA()
//{
//   _code.setIP(_executionStack.top());
//   _executionStack.pop();
//
////   _dataStack.setSP(_executionStack.top());
////   _executionStack.pop();
//
//   _dataStack.setBS(_executionStack.top());
//   _executionStack.pop();
//}


void CRunBytecode::callSyslib(const std::string &libFunc)
{
	std::string libName = libFunc.substr(0, libFunc.find_first_of("."));
	std::string procName = libFunc.substr(libFunc.find_first_of(".")+1);

// std::cout << "libFunc=" << libFunc << " libName=" << libName << " procName=" << procName << std::endl;


	std::map<std::string, void*>::iterator ithandler;
	void *dlhandler = NULL;
	char *error;

	ithandler = _syslibHandlerList->find(libName);

	if (ithandler == _syslibHandlerList->end()) {
		// TODO: path absoluto ??? nem pensar :-)
// 		std::string libPath = std::string("../../os_libs/") + libName + std::string("/libuvm_os_") + libName + ".so";
// 		dlhandler = dlopen(libPath.c_str(), RTLD_NOW|RTLD_GLOBAL);
// 		dlhandler = dlopen(libPath.c_str(), RTLD_LAZY|RTLD_GLOBAL);
// 		dlhandler = dlopen(libPath.c_str(), RTLD_LAZY|RTLD_LOCAL);

// 		std::string libPath = std::string("../../ubibind/tests/") + std::string("/libuvm_os_") + libName + ".so";
		std::string libPath = std::string("../ubibind/") + libName + std::string("/libuvm_os_") + libName + ".so";
// 		std::string libPath = libName + std::string("/libuvm_os_") + libName + ".so";
		dlhandler = dlopen(libPath.c_str(), RTLD_LAZY|RTLD_GLOBAL);
		if (!dlhandler) {
			fprintf (stderr, "dlopen(%s): %s\n", libPath.c_str(), dlerror());
			exit(1);
		}
		dlerror();    // Clear any existing error
		(*_syslibHandlerList)[libName] = dlhandler;
// 		void (*initFunc)(void);
// 		initFunc = (void (*)(void)) dlsym(dlhandler, ("uvm_os_lib"+libName+"_init").c_str());
// 		if ((error = dlerror()) != NULL) {
// 			fprintf (stderr, "dlsym: %s\n", error);
// 			exit(1);
// 		}
// 		(*initFunc)();
	} else {
		dlhandler = ithandler->second;
	}

   void (*func)(CDataStack&);
   std::string funcToFind = "uvm_os_wrap_lib" + libName + "_" + procName;
   func = (void (*)(CDataStack&)) dlsym(dlhandler, funcToFind.c_str());
   if ((error = dlerror()) != NULL) {
      fprintf (stderr, "dlsym(%s): %s\n", funcToFind.c_str(), error);
      exit(1);
   }
   (*func)(_dataStack);
}


std::string CRunBytecode::getSymbolName(uint index)
{
	return _ip.element->getSymbolByIndex(index)->_name;
}


CSymbol* CRunBytecode::getSymbol(uint index)
{
	return _ip.element->getSymbolByIndex(index);
}


/////////////
// opcodes //
/////////////

void CRunBytecode::invalidOpcode(const std::string &opcode)
{
   error ("Invalid opcode: [" + opcode + "] !!!");
}


void CRunBytecode::lcallOpcode()
{
   trace ("lcall opcode");

   std::string procname = getSymbolName(_currentInstruction->getArg1());


//   if (libname == "io") {
	if (procname == "io.writeln") {
		procWriteln();
	} else if (procname == "io.write") {
		procWrite();
	} else if (procname == "io.readln") {
		procReadln();
	} else if (procname == "datetime.sleep") {
		procSleep();
//      } else if (procname == "leia") {
//         procLeia();
	} else {
		callSyslib(procname);
	}
//       } else {
// 		std::cout << "arg1 = " << _currentInstruction->getArg1() << std::endl;
// 		std::cout << "procname=" << procname << std::endl;
//          error("lcall invocando subrotina desconhecida !!!");
//       }

//   _dataStack.setBS(_executionStack.top());
//   _executionStack.pop();
}


void CRunBytecode::ldconstOpcode()
{
   trace ("ldconst opcode");

   CSymbol* symbol = getSymbol(_currentInstruction->getArg1());

   // TODO: nao ta certo !!!!
   //_dataStack.push(CLiteral(symbol->_type, &symbol->_name));
   _dataStack.push(CLiteral(symbol->_type, symbol->getValue()));
}


void CRunBytecode::ldvarOpcode()
{
	trace ("ldvar opcode");

	CLiteral literal = _controlStack.top()->_localVarList[_currentInstruction->getArg1()];

	_dataStack.push(literal);
}

void CRunBytecode::stvarOpcode()
{
	trace ("stvar opcode");

	_controlStack.top()->_localVarList[_currentInstruction->getArg1()] = _dataStack.pop();
}

void CRunBytecode::stresultOpcode()
{
	trace ("stresult opcode");

	_controlStack.top()->_resultList[_currentInstruction->getArg1()] = _dataStack.pop();
}

void CRunBytecode::ldparamOpcode()
{
	trace ("ldparam opcode");

	CLiteral literal = _controlStack.top()->_paramList[_currentInstruction->getArg1()];

	_dataStack.push(literal);
}

void CRunBytecode::stopOpcode()
{
	trace ("stop opcode");

	_stop = true;
}

void CRunBytecode::retOpcode()
{
	trace ("ret opcode");

	CActivationRecord* ar = _controlStack.top();
	_controlStack.pop();
	ar->restore_state(_dataStack, _ip);

	delete ar;

	if (_controlStack.size() == 0) {
// 		std::cout << "_stop=true!!!" << std::endl;
		_stop = true;
	}
}

void CRunBytecode::mcallOpcode()
{
	trace ("mcall opcode");

	CElement* element = _dataStack.pop().getElement();

	std::string method = getSymbolName(_currentInstruction->getArg1());

	if (method == "wait") {
		if (element->_entity->isParallel() == false) {
			std::cout << "Trying to do wait in a non parallel element !!!" << std::endl;
		}
		element->_thread->join();
		element->_thread = NULL;
	} else {
		CActivationRecord* ar = new CActivationRecord(this, element, method, _ip, _dataStack);
		_controlStack.push(ar);
	}
}


// TODO: nesta versao mcallOpcode criava as threads quando o construtor era chamado... como a ubivm chama o construtor implicitamente, mcall nao invoca mais os construtores, e portanto o codigo relativo a isso foi retirado
// void CRunBytecode::mcallOpcode()
// {
// 	trace ("mcall opcode");
//
// 	CElement* element = _dataStack.pop().getElement();
//
// // 	std::cout << "element desempilhado: " << element << std::endl;
//
// 	std::string method = getSymbolName(_currentInstruction->getArg1());
//
// 	if (method == "wait") {
// 		if (element->_entity->isParallel() == false) {
// 			std::cout << "Trying to do wait in a non parallel element !!!" << std::endl;
// 		}
// 		element->_thread->join();
// 		element->_thread = NULL;
// 	} else {
// 		CRunBytecode* rb = NULL;
// 		bool runInParallel = (element->_entity->isParallel() == true && method == "constructor");
// // 		bool runInParallel = (element->_entity->isParallel() == true && method == element->_entity->getName());
// 		if (runInParallel) {
// 			rb = new CRunBytecode();
// 			// TODO: e qdo isso eh liberado ???
// 		} else {
// 			rb = this;
// 		}
//
// 		CActivationRecord* ar = new CActivationRecord(rb, element, method, rb->_ip, _dataStack); // TODO: rb ou this ?????
// //  		ar->_lastIp = _ip;
//
// // 		rb->_ip.element = element;
// // 		rb->_ip.method  = element->getMethod(method);
//
// // 		if (rb->_ip.method == NULL) {
// // 			std::cout << "Metodo " << method << " nao encontrado !!!" << std::endl;
// // 		}
//
// //  		for(std::vector<CLocalVarDefinition*>::iterator var = rb->_ip.method->_localVarList.begin();
// // 		 		var != rb->_ip.method->_localVarList.end(); var++) {
// // 	 		ar->_localVarList.push_back(CLiteral((*var)->_type));
// // 	 	}
//
// // 		for(std::vector<CParameterDefinition*>::iterator par = rb->_ip.method->_parameterList.begin();
// // 				par != rb->_ip.method->_parameterList.end(); par++) {
// // 			ar->_paramList.insert(ar->_paramList.begin(), _dataStack.pop());
// // 		}
//
// //  		for(std::vector<CResultDefinition*>::iterator ret = rb->_ip.method->_resultList.begin();
// // 		 		ret != rb->_ip.method->_resultList.end(); ret++) {
// // 	 		ar->_resultList.push_back(CLiteral((*ret)->_type));
// // 	 	}
//
// 		rb->_controlStack.push(ar);
//
// // 		rb->_ip.ip = 0;
//
// 		if (runInParallel) {
// 			element->_thread = new boost::thread( boost::bind( &CRunBytecode::run_bytecode, rb));
// 			//rb->_stop = true;
// 		}
//
// // 		ar->restore_state(rb->_dataStack, rb->_ip);
//
// // 		delete ar;
// 	}
// }


bool CRunBytecode::runsCode(std::string contextName, std::string serviceName, std::vector<CLiteral> arguments, std::vector<CLiteral>& results)
{
	trace ("runs internal code");

	std::string elementName = (*_contextList)[contextName]->findService(serviceName);

	if (elementName == "") {
		return false;
	}

	CElement* element = NULL;

	for(std::vector<CElement*>::iterator elementIt = _elementList->begin();
		elementIt != _elementList->end();
		elementIt++) {
		if ((*elementIt)->getName() == elementName) {
			element = (*elementIt);
			break;
		}
	}

	if (element == NULL) {
		return false;
	}

	for(std::vector<CLiteral>::reverse_iterator par = arguments.rbegin(); par != arguments.rend(); par++) {
// 		std::cout << "argumento: " << (*par).getText() << std::endl;
		_dataStack.push(*par);
	}

	CActivationRecord* ar = new CActivationRecord(this, element, serviceName, _ip, _dataStack);

	_controlStack.push(ar);

	run_bytecode();

// 	ar->restore_state(_dataStack, _ip);

// 	std::cout << "dataStack.size()=" << _dataStack.size() << std::endl;
	for(std::vector<CResultDefinition*>::iterator ret = element->getMethod(serviceName)->_resultList.begin();
		ret != element->getMethod(serviceName)->_resultList.end(); ret++) {
		results.insert(results.begin(), _dataStack.pop());
	}

// 	std::cout << "resultados" << std::endl;
//
// 	for(std::vector<CLiteral>::iterator res = results.begin(); res != results.end(); res++) {
// 		std::cout << "\tresultado: " << (*res).getText() << std::endl;
// 	}

	return true;
}


/*bool CRunBytecode::runsCode(std::string contextName, std::string serviceName, std::vector<CLiteral> arguments, std::vector<CLiteral>& results)
{
	trace ("runs internal code");

	std::string elementName = (*_contextList)[contextName]->findService(serviceName);

	if (elementName == "") {
// 		std::cout << "Servico " << serviceName << " no grupo " << contextName << " nao encontrado !!!" << std::endl;
		return false;
	}

	CElement* element = NULL;

	for(std::vector<CElement*>::iterator elementIt = _elementList->begin();
		elementIt != _elementList->end();
		elementIt++) {
		if ((*elementIt)->getName() == elementName) {
			element = (*elementIt);
			break;
		}
	}

	if (element == NULL) {
// 		std::cout << "Elemento " << elementName << " nao encontrado em elementList !!!" << std::endl;
		return false;
	}

	CActivationRecord* ar = new CActivationRecord();

	ar->_lastIp = _ip;

	_ip.element = element;
	_ip.method = _ip.element->getMethod(serviceName);

	if (_ip.method == NULL) {
// 		std::cout << "Metodo " << getSymbol(_currentInstruction->getArg1()) << " nao encontrado !!!" << std::endl;
		return false;
	}

	for(std::vector<CLocalVarDefinition*>::iterator var = _ip.method->_localVarList.begin();
		var != _ip.method->_localVarList.end(); var++) {
		ar->_localVarList.push_back(CLiteral((*var)->_type));
	}

	for(std::vector<CLiteral>::iterator par = arguments.begin(); par != arguments.end(); par++) {
// 		std::cout << "argumento: " << (*par).getText() << std::endl;
		ar->_paramList.insert(ar->_paramList.begin(), *par);
	}

// 	for(std::vector<CParameterDefinition*>::iterator par = _ip.method->_parameterList.begin();
// 		par != _ip.method->_parameterList.end(); par++) {
// 		ar->_paramList.insert(ar->_paramList.begin(), _dataStack.pop());
// 	}

// 	std::cout << "Numero de resultados definidos no servico: " << _ip.method->_resultList.size() << std::endl;

	for(std::vector<CResultDefinition*>::iterator ret = _ip.method->_resultList.begin();
		ret != _ip.method->_resultList.end(); ret++) {
		ar->_resultList.push_back(CLiteral((*ret)->_type));
	}

	_ip.ip = 0;

	_controlStack.push(ar);

	run_bytecode();

	for(std::vector<CResultDefinition*>::iterator ret = element->getMethod(serviceName)->_resultList.begin();
		ret != element->getMethod(serviceName)->_resultList.end(); ret++) {
		results.push_back(_dataStack.pop());
	}

// 	std::cout << "resultados" << std::endl;

// 	for(std::vector<CLiteral>::iterator res = results.begin(); res != results.end(); res++) {
// 		std::cout << "\tresultado: " << (*res).getText() << std::endl;
// 	}
	return true;
}

*/
void CRunBytecode::ldselfOpcode()
{
	trace ("ldself opcode");

	_dataStack.push(CLiteral(_ip.element));
}

void CRunBytecode::addOpcode()
{
   trace ("add opcode");

   CLiteral arg2 = _dataStack.pop();
   CLiteral arg1 = _dataStack.pop();

//    std::cout << "arg1=" << arg1.getText() << " arg2=" << arg2.getText() << std::endl;

   if (arg1._type == IntegerType && arg2._type == IntegerType) {
	   _dataStack.push(CLiteral(arg1.getInteger()+arg2.getInteger()));
   } else if (arg1._type == RealType && arg2._type == RealType) {
	   _dataStack.push(CLiteral(arg1.getReal()+arg2.getReal()));
   } else if (arg1._type == StringType && arg2._type == StringType) {
	   _dataStack.push(CLiteral(arg1.getString()+arg2.getString()));
   } else {
	   error("Tipos invalidos !!!");
   }
}

void CRunBytecode::subOpcode()
{
   trace ("sub opcode");

   CLiteral arg2 = _dataStack.pop();
   CLiteral arg1 = _dataStack.pop();

   if (arg1._type == IntegerType && arg2._type == IntegerType) {
	   _dataStack.push(CLiteral(arg1.getInteger()-arg2.getInteger()));
   } else if (arg1._type == RealType && arg2._type == RealType) {
	   _dataStack.push(CLiteral(arg1.getReal()-arg2.getReal()));
   } else {
	   error("Tipos invalidos !!!");
   }
}

void CRunBytecode::mulOpcode()
{
   trace ("mul opcode");

   CLiteral arg2 = _dataStack.pop();
   CLiteral arg1 = _dataStack.pop();

   if (arg1._type == IntegerType && arg2._type == IntegerType) {
	   _dataStack.push(CLiteral(arg1.getInteger()*arg2.getInteger()));
   } else if (arg1._type == RealType && arg2._type == RealType) {
	   _dataStack.push(CLiteral(arg1.getReal()*arg2.getReal()));
   } else {
	   error("Tipos invalidos !!!");
   }
}

void CRunBytecode::divOpcode()
{
	trace ("div opcode");

	CLiteral arg2 = _dataStack.pop();
	CLiteral arg1 = _dataStack.pop();

	if (arg1._type == IntegerType && arg2._type == IntegerType) {
		_dataStack.push(CLiteral((int)(arg1.getInteger()/arg2.getInteger())));
	} else if (arg1._type == RealType && arg2._type == RealType) {
		_dataStack.push(CLiteral(arg1.getReal()/arg2.getReal()));
	} else {
		error("Tipos invalidos !!!");
	}
}

void CRunBytecode::ltOpcode()
{
	trace ("lt opcode");

	CLiteral arg2 = _dataStack.pop();
	CLiteral arg1 = _dataStack.pop();

	if (arg1._type == IntegerType && arg2._type == IntegerType) {
		_dataStack.push(CLiteral(arg1.getInteger() < arg2.getInteger()));
	} else if (arg1._type == RealType && arg2._type == RealType) {
		_dataStack.push(CLiteral(arg1.getReal() < arg2.getReal()));
	} else if (arg1._type == StringType && arg2._type == StringType) {
		_dataStack.push(CLiteral(arg1.getString() < arg2.getString()));
	} else {
		error("Tipos invalidos !!!");
	}
}


void CRunBytecode::gtOpcode()
{
	trace ("gt opcode");

	CLiteral arg2 = _dataStack.pop();
	CLiteral arg1 = _dataStack.pop();

	if (arg1._type == IntegerType && arg2._type == IntegerType) {
		_dataStack.push(CLiteral(arg1.getInteger() > arg2.getInteger()));
	} else if (arg1._type == RealType && arg2._type == RealType) {
		_dataStack.push(CLiteral(arg1.getReal() > arg2.getReal()));
	} else if (arg1._type == StringType && arg2._type == StringType) {
		_dataStack.push(CLiteral(arg1.getString() > arg2.getString()));
	} else {
		error("Tipos invalidos !!!");
	}
}


void CRunBytecode::leOpcode()
{
   trace ("le opcode");

   CLiteral arg2 = _dataStack.pop();
   CLiteral arg1 = _dataStack.pop();

	if (arg1._type == IntegerType && arg2._type == IntegerType) {
		_dataStack.push(CLiteral(arg1.getInteger() <= arg2.getInteger()));
	} else if (arg1._type == RealType && arg2._type == RealType) {
		_dataStack.push(CLiteral(arg1.getReal() <= arg2.getReal()));
	} else if (arg1._type == StringType && arg2._type == StringType) {
		_dataStack.push(CLiteral(arg1.getString() <= arg2.getString()));
	} else {
		error("Tipos invalidos !!!");
	}
}


void CRunBytecode::geOpcode()
{
	trace ("ge opcode");

	CLiteral arg2 = _dataStack.pop();
	CLiteral arg1 = _dataStack.pop();

	if (arg1._type == IntegerType && arg2._type == IntegerType) {
		_dataStack.push(CLiteral(arg1.getInteger() >= arg2.getInteger()));
	} else if (arg1._type == RealType && arg2._type == RealType) {
		_dataStack.push(CLiteral(arg1.getReal() >= arg2.getReal()));
	} else if (arg1._type == StringType && arg2._type == StringType) {
		_dataStack.push(CLiteral(arg1.getString() >= arg2.getString()));
	} else {
		error("Tipos invalidos !!!");
	}
}

void CRunBytecode::eqOpcode()
{
	trace ("eq opcode");

	CLiteral arg2 = _dataStack.pop();
	CLiteral arg1 = _dataStack.pop();

	if (arg1._type == IntegerType && arg2._type == IntegerType) {
		_dataStack.push(CLiteral(arg1.getInteger() == arg2.getInteger()));
	} else if (arg1._type == RealType && arg2._type == RealType) {
		_dataStack.push(CLiteral(arg1.getReal() == arg2.getReal()));
	} else if (arg1._type == StringType && arg2._type == StringType) {
		_dataStack.push(CLiteral(arg1.getString() == arg2.getString()));
	} else {
		error("Tipos invalidos !!!");
	}
}

void CRunBytecode::neOpcode()
{
	trace ("ne opcode");

	CLiteral arg2 = _dataStack.pop();
	CLiteral arg1 = _dataStack.pop();

	if (arg1._type == IntegerType && arg2._type == IntegerType) {
		_dataStack.push(CLiteral(arg1.getInteger() != arg2.getInteger()));
	} else if (arg1._type == RealType && arg2._type == RealType) {
		_dataStack.push(CLiteral(arg1.getReal() != arg2.getReal()));
	} else if (arg1._type == StringType && arg2._type == StringType) {
		_dataStack.push(CLiteral(arg1.getString() != arg2.getString()));
	} else {
		error("Tipos invalidos !!!");
	}
}


void CRunBytecode::andOpcode()
{
	trace ("and opcode");

	CLiteral arg2 = _dataStack.pop();
	CLiteral arg1 = _dataStack.pop();

	if (arg1._type == BooleanType && arg2._type == BooleanType) {
		_dataStack.push(CLiteral(arg1.getBoolean() && arg2.getBoolean()));
	} else {
		error("Tipos invalidos !!!");
	}
}


void CRunBytecode::orOpcode()
{
	trace ("or opcode");

	CLiteral arg2 = _dataStack.pop();
	CLiteral arg1 = _dataStack.pop();

	if (arg1._type == BooleanType && arg2._type == BooleanType) {
		_dataStack.push(CLiteral(arg1.getBoolean() || arg2.getBoolean()));
	} else {
		error("Tipos invalidos !!!");
	}
}


void CRunBytecode::ifnotOpcode()
{
	trace ("ifnot opcode");

	CLiteral arg = _dataStack.pop();

	if (arg._type == BooleanType) {
		if (arg.getBoolean() != true) {
			_ip.ip = _currentInstruction->getArg1();
		}
	} else {
		error("Tipos invalidos !!!");
	}
}

void CRunBytecode::jmpOpcode()
{
   trace ("jmp opcode");

   _ip.ip = _currentInstruction->getArg1();
}



void CRunBytecode::newelemOpcode()
{
	trace ("newelem opcode");

	std::string entityName = getSymbolName(_currentInstruction->getArg1());
	CElement* element = NULL;

	foreach(CEntityDefinition* entity, _asmDef->getEntityList()) {
		if (entity->getName() == entityName) {
			element = new CElement(entity);

			if (element->getMethod("__when") == NULL) {
				break;
			}

			// Copy & Paste from mcallOpcode
			CActivationRecord* ar = new CActivationRecord(this, element, "__when", _ip, _dataStack);
			_controlStack.push(ar);

// 			std::cout << "antes run_bce..." << std::endl;

			run_bytecode_until(RET_OPCODE);

// 			std::cout << "depois run_bce..." << std::endl;

// 			_stop = false;

// 			delete ar;

// 			_controlStack.pop();
//  			ar->restore_state(_dataStack, _ip);

// 			delete ar;

			bool whenResult = _dataStack.pop().getBoolean();

			if (whenResult == true) {
				break;
			}
// 			delete element;
			element = NULL;
		}
	}

	if (element != NULL) {
// 		std::cout << "element empilhado: " << element << std::endl;
		_elementList->push_back(element); // uso no runs para encontrar a entidade que executa um servico... nao ta bem certo :-/

		// Run constructor
		///////////////////////////////////

		std::string method = "constructor";
		if (element->getMethod(method) != NULL) {
			CRunBytecode* rb = NULL;
			bool runInParallel = (element->_entity->isParallel() == true && method == "constructor");
			if (runInParallel) {
				rb = new CRunBytecode();
				// TODO: e qdo isso eh liberado ???
			} else {
				rb = this;
			}

			CActivationRecord* ar = new CActivationRecord(rb, element, method, rb->_ip, _dataStack);
			rb->_controlStack.push(ar);

			if (runInParallel) {
				element->_thread = new boost::thread( boost::bind( &CRunBytecode::run_bytecode, rb));
			}
		}

		_dataStack.push(CLiteral(element));

		////////////////////////////////////
	} else {
		std::cout << "Nenhuma entidade " << entityName << " valida para o contexto atual." << std::endl;
		exit(1);
	}
}


// SEM SUPORTE A CLAUSULA WHEN
// void CRunBytecode::newelemOpcode()
// {
// 	trace ("newelem opcode");
//
// 	std::string entity = getSymbolName(_currentInstruction->getArg1());
//
// 	CElement* element = new CElement(_asmDef->getEntity(entity));
// 	_elementList->push_back(element); // uso no runs para encontrar a entidade que executa um servico... nao ta bem certo :-/
//
// 	_dataStack.push(CLiteral(element));
// }



// void CRunBytecode::newelemOpcode()
// {
// 	trace ("new opcode");
//
// //	std::string entity = _symbolTable.getSymbolByIndex(_currentInstruction->getArg1())->_name;
// 	std::string entity_name = getSymbolName(_currentInstruction->getArg1());
//
// 	CEntityDefinition* entity = _asmDef->getEntity(entity_name);
// 	CElement* element = new CElement(entity);
// 	_elementList->push_back(element); // uso no runs para encontrar a entidade que executa um servico... nao ta bem certo :-/
//
// 	_dataStack.push(CLiteral(element));
//
// 	if (entity->isParallel()) {
// 		CRunBytecode* runbytecode = new CRunBytecode(_options, _asmDef, _syslibHandlerList, _elementList, _contextList, _contextsInfo, _cp);
// 		runbytecode->run(entity_name, element);
// 	}
// }


void CRunBytecode::joincOpcode()
{
	trace("joinc opcode");

	std::string object    = _dataStack.pop().getString();
	std::string contextName = _dataStack.pop().getString();
	CContext* context;

	std::map<std::string, CContext*>::iterator contextit = _contextList->find(contextName);
	if (contextit == _contextList->end()) {
		context = new CContext(contextName);
		(*_contextList)[contextName] = context;
	} else {
		context = (*contextit).second;
	}

	context->addObject(object);
}


void CRunBytecode::publishdOpcode()
{
	trace("publishd opcode");

	uint tupleValues = _dataStack.pop().getInteger();
	uint tupleKeys   = _dataStack.pop().getInteger();
	CTuple* tuple = new CTuple();

	// TODO: eu estou forcando que key e values sejam string... mas eu posso deixar como CLiteral, a principio, e converter para texto para poder montar as chaves... so nao sei como ficaria o o resultado qdo eu rodo o getComposedValues da tupla...

	// Read tuple values
	for(uint value=0; value<tupleValues;value++) {
		tuple->addValueAtBegin(_dataStack.pop());
	}

	// Read tuple keys
	for(uint key=0; key<tupleKeys;key++) {
		tuple->addKeyAtBegin(_dataStack.pop());
	}

	std::string contextName = _dataStack.pop().getString();
	(*_contextList)[contextName]->addTuple(tuple); // TODO: addTuple deveria chamar sendRequestDataafOpcode de ContextProvider ????

	CContextProvider::getInstance()->sendRequestPublishdOpcode(_vmId, contextName, *tuple);
}


void CRunBytecode::getdOpcode()
{
	trace("getd opcode");

	uint tupleKeys = _dataStack.pop().getInteger();
	CTuple tuple;

	// Read tuple keys
	for(uint key=0; key<tupleKeys;key++) {
		tuple.addKeyAtBegin(_dataStack.pop().getString());
	}

	std::string contextName = _dataStack.pop().getString();
	// TODO: acho que o correto seria ou eu empilhar todos os values da tupla, ou empilhar a tupla em si
	CContextProvider::getInstance()->sendRequestGetdOpcode(_vmId, contextName, tuple);

// 	std::cout << "dqu executado !!!" << std::endl;
}


void CRunBytecode::getdnbOpcode()
{
	trace("getdnb opcode");

	uint tupleKeys = _dataStack.pop().getInteger();
	CTuple tuple;

	// Read tuple keys
	for(uint key=0; key<tupleKeys;key++) {
		tuple.addKeyAtBegin(_dataStack.pop().getString());
	}

	std::string contextName = _dataStack.pop().getString();
	// TODO: acho que o correto seria ou eu empilhar todos os values da tupla, ou empilhar a tupla em si
	CContextProvider::getInstance()->sendRequestGetdnbOpcode(_vmId, contextName, tuple);
}


// void CRunBytecode::getdOpcode()
// {
// 	trace("getd opcode");
//
// 	uint tupleKeys = _dataStack.pop().getInteger();
// 	CTuple tuple;
//
// 	// Read tuple keys
// 	for(uint key=0; key<tupleKeys;key++) {
// 		tuple.addKeyAtBegin(_dataStack.pop().getString());
// 	}
//
// 	std::string contextName = _dataStack.pop().getString();
// 	// TODO: acho que o correto seria ou eu empilhar todos os values da tupla, ou empilhar a tupla em si
// 	_dataStack.push((*_contextList)[contextName]->getTuple(&tuple)->getComposedValues());
// }


void CRunBytecode::finddOpcode()
{
	trace("findd opcode");

	uint tupleKeys = _dataStack.pop().getInteger();
	CTuple tuple;

	// Getting tuple keys
	for(uint key=0; key<tupleKeys;key++) {
		tuple.addKeyAtBegin(_dataStack.pop().getString());
	}

	std::string contextName = _dataStack.pop().getString();
// 	try {
		CContextProvider::getInstance()->sendRequestFinddOpcode(_vmId, contextName, tuple);
// 	}
// 	catch (std::exception& e)
// 	{
// 		std::cerr << "Exception: " << e.what() << "\n";
// 	}
}


void CRunBytecode::finddnbOpcode()
{
	trace("finddnb_opcode");

	uint tupleKeys = _dataStack.pop().getInteger();
	CTuple tuple;

	// Getting tuple keys
	for(uint key=0; key<tupleKeys;key++) {
		tuple.addKeyAtBegin(_dataStack.pop().getString());
	}

	std::string contextName = _dataStack.pop().getString();
// 	try {
		CContextProvider::getInstance()->sendRequestFinddnbOpcode(_vmId, contextName, tuple);
// 	}
// 	catch (std::exception& e)
// 	{
// 		std::cerr << "Exception: " << e.what() << "\n";
// 	}
}


void CRunBytecode::listdOpcode()
{
	trace("listd opcode");

	std::string contextName = _dataStack.pop().getString();
	CContextProvider::getInstance()->sendRequestListdOpcode(_vmId, contextName);
}


void CRunBytecode::stcontextiOpcode()
{
	trace("stcontexti opcode");

	std::string context = getSymbolName(_currentInstruction->getArg1());
	std::map<std::string, std::pair<CElement*, CMethodDefinition*> >::iterator event;

	// TODO: otimizar isso...

	bool run_new_value_event = (_contextsInfo->find(context) == _contextsInfo->end());

	CLiteral old_value = (*_contextsInfo)[context];

	(*_contextsInfo)[context] = _dataStack.pop();

	CLiteral new_value = (*_contextsInfo)[context];

	event = _context_events.find(context + "." + "on_changed");
	if (event != _context_events.end()) {
		_dataStack.push(old_value);
		_dataStack.push(new_value);

		CActivationRecord* ar = new CActivationRecord(this, (*event).second.first, (*event).second.second->getName(), _ip, _dataStack);
		_controlStack.push(ar);
	}

	if (run_new_value_event) {
		// new value
		event = _context_events.find(context + "." + "on_new_value");
		if (event != _context_events.end()) {
			_dataStack.push(context);
			_dataStack.push(new_value);

			CActivationRecord* ar = new CActivationRecord(this, (*event).second.first, (*event).second.second->getName(), _ip, _dataStack);
			_controlStack.push(ar);
		}
	}
}


void CRunBytecode::ldcontextiOpcode()
{
	trace("ldcontexti opcode");

	std::string context = getSymbolName(_currentInstruction->getArg1());

	_dataStack.push((*_contextsInfo)[context]);
}


void CRunBytecode::publishsOpcode()
{
	trace("publishs opcode");

	std::string contextName   = _dataStack.pop().getString();
	std::string serviceName = getSymbolName(_currentInstruction->getArg1());

	(*_contextList)[contextName]->addService(serviceName, _ip.element->getName());

	CContextProvider::getInstance()->sendRequestPublishsOpcode(_vmId, contextName, serviceName);
}


void CRunBytecode::removesOpcode()
{
	trace("removes opcode");

	std::string contextName   = _dataStack.pop().getString();
	std::string serviceName = getSymbolName(_currentInstruction->getArg1());

	(*_contextList)[contextName]->remService(serviceName);
// 	(*_contextList)[contextName]->remService(serviceName, _ip.element->getName());

	CContextProvider::getInstance()->sendRequestRemovesOpcode(_vmId, contextName, serviceName);
}


void CRunBytecode::runsOpcode()
{
	trace ("runs opcode");

	std::string contextName   = _dataStack.pop().getString();
	std::string serviceName = getSymbolName(_currentInstruction->getArg1());

	CContextProvider::getInstance()->sendRequestRunsOpcode(_vmId, contextName, serviceName);
}


// VERSAO NAO COMPARTILHADA
// void CRunBytecode::runsOpcode()
// {
// 	trace ("runs opcode");
//
// 	std::string contextName   = _dataStack.pop().getString();
// 	std::string serviceName = getSymbolName(_currentInstruction->getArg1());
// 	std::string elementName = (*_contextList)[contextName]->findService(serviceName);
//
// 	if (elementName == "") {
// 		std::cout << "Servico " << serviceName << " no grupo " << contextName << " nao encontrado !!!" << std::endl;
// 	}
//
// 	CElement* element = NULL;
//
// 	for(std::vector<CElement*>::iterator elementIt = _elementList->begin();
// 		elementIt != _elementList->end();
// 		elementIt++) {
// 		if ((*elementIt)->getName() == elementName) {
// 			element = (*elementIt);
// 			break;
// 		}
// 	}
//
// 	if (element == NULL) {
// 		std::cout << "Elemento " << elementName << " nao encontrado em elementList !!!" << std::endl;
// 	}
//
// 	CActivationRecord* ar = new CActivationRecord();
//
// 	ar->_ip = _ip;
//
// 	_ip.element = element;
// 	_ip.method = _ip.element->getMethod(serviceName);
//
// 	if (_ip.method == NULL) {
// 		std::cout << "Metodo " << getSymbol(_currentInstruction->getArg1()) << " nao encontrado !!!" << std::endl;
// 	}
//
//  	for(std::vector<CLocalVarDefinition*>::iterator var = _ip.method->_localVarList.begin();
//  		var != _ip.method->_localVarList.end(); var++) {
//  		ar->_localVarList.push_back(CLiteral((*var)->_type));
//  	}
//
// 	for(std::vector<CParameterDefinition*>::iterator par = _ip.method->_parameterList.begin();
// 		par != _ip.method->_parameterList.end(); par++) {
// 		ar->_paramList.insert(ar->_paramList.begin(), _dataStack.pop());
// 	}
//
//  	for(std::vector<CResultDefinition*>::iterator ret = _ip.method->_resultList.begin();
//  		ret != _ip.method->_resultList.end(); ret++) {
//  		ar->_resultList.push_back(CLiteral((*ret)->_type));
//  	}
//
// 	_ip.ip = 0;
//
// 	_controlStack.push(ar);
// }


void CRunBytecode::ldtabOpcode()
{
	trace ("ldtab opcode");

	CLiteral index = _dataStack.pop();
	CLiteral value;

	if (index._type == StringType) {
		value = _controlStack.top()->_localVarList[_currentInstruction->getArg1()].getTable()->get(index.getText());
	} else {
		value = _controlStack.top()->_localVarList[_currentInstruction->getArg1()].getTable()->get(index.getInteger() - 1);
	}

	_dataStack.push(value);
}


void CRunBytecode::sttabOpcode()
{
	trace ("sttab opcode");

	CLiteral value = _dataStack.pop();
	CLiteral index = _dataStack.pop();

// 	if (index._type == StringType) {
		_controlStack.top()->_localVarList[_currentInstruction->getArg1()].getTable()->add(index.getText(), value);
// 	} else {
// 		_controlStack.top()->_localVarList[_currentInstruction->getArg1()].getTable()->add(index.getInteger() - 1, value);
// 	}
}


void CRunBytecode::ldtuplekOpcode()
{
	trace ("ldtuplek opcode");

	CLiteral index = _dataStack.pop();
	CLiteral value;

	value = _controlStack.top()->_localVarList[_currentInstruction->getArg1()].getTuple()->_keyList[index.getInteger()-1];

	_dataStack.push(value);
}


void CRunBytecode::ldtuplevOpcode()
{
	trace ("ldtuplev opcode");

	CLiteral index = _dataStack.pop();
	CLiteral value;

	value = _controlStack.top()->_localVarList[_currentInstruction->getArg1()].getTuple()->_valueList[index.getInteger()-1];

	_dataStack.push(value);
}


void CRunBytecode::tabsizeOpcode()
{
	trace ("tabsize opcode");

	_dataStack.push(CLiteral((int)_controlStack.top()->_localVarList[_currentInstruction->getArg1()].getTable()->size()));
}


void CRunBytecode::ldpropOpcode()
{
	trace ("ldprop opcode");

	CLiteral literal = _ip.element->_propertyList[_currentInstruction->getArg1()];

	_dataStack.push(literal);
}

void CRunBytecode::stpropOpcode()
{
	trace ("stprop opcode");

	CLiteral old = _ip.element->_propertyList[_currentInstruction->getArg1()];

// 	std::cout << __FUNCTION__ << _ip.element << std::endl;

	_ip.element->_propertyList[_currentInstruction->getArg1()] = _dataStack.pop();
	std::pair<CElement*, CMethodDefinition*> event = _ip.element->get_event("on_property_changed");
	run_property_event(event.first, event.second, _ip.element->_entity->_propertyList[_currentInstruction->getArg1()]->_name, old.getText(), _ip.element->_propertyList[_currentInstruction->getArg1()].getText());
}

void CRunBytecode::belementevOpcode()
{
	trace ("belementev opcode");

	std::string method_name = _dataStack.pop().getString();
	std::string event_name  = _dataStack.pop().getString();
	std::string element_name = getSymbolName(_currentInstruction->getArg1());
	CElement* element = _controlStack.top()->_localVarList[_currentInstruction->getArg1()].getElement();
// 	_controlStack.top()->_localVarList[_currentInstruction->getArg1()].bind_event(event_name, _ip.element->getMethod(method_name));;

// 	std::cout << "event_name=" << event_name << " element=" << element->getName() << " method_name=" << method_name << std::endl;
	element->bind_event(event_name, _ip.element, _ip.element->getMethod(method_name));
// 	CLiteral literal = _controlStack.top()->_localVarList[_currentInstruction->getArg1()];
}


void CRunBytecode::bcontextievOpcode()
{
	trace ("bcontextiev opcode");

	std::string method_name = _dataStack.pop().getString();
	std::string event_name  = _dataStack.pop().getString();
	std::string context_name = getSymbolName(_currentInstruction->getArg1());

	bind_contexti_event(context_name, event_name, _ip.element, _ip.element->getMethod(method_name));
}


void CRunBytecode::bcontextevOpcode()
{
	trace ("bcontextev opcode");

	std::string method_name = _dataStack.pop().getString();
	std::string event_name  = _dataStack.pop().getString();
	std::string context_name  = _dataStack.pop().getString();

	bind_context_event(context_name, event_name, _ip.element, _ip.element->getMethod(method_name));
}



void CRunBytecode::run_property_event(CElement* element, CMethodDefinition* method, std::string name, CLiteral old_value, CLiteral new_value)
{
// 	CElement* element = _dataStack.pop().getElement();

// 	std::cout << "element desempilhado: " << element << std::endl;

// 	std::string method = getSymbolName(_currentInstruction->getArg1());

	if (element == NULL || method == NULL) {
		return;
	}

 	_dataStack.push(CLiteral(name));
//	_dataStack.push(CLiteral(std::string("MyProp")));

//	_dataStack.push(old_value);
	_dataStack.push(CLiteral(std::string("0")));

	_dataStack.push(new_value);
//	_dataStack.push(CLiteral(std::string("1")));

	CActivationRecord* ar = new CActivationRecord(this, element, method->getName(), _ip, _dataStack);
	_controlStack.push(ar);
}


void CRunBytecode::bind_contexti_event(std::string context_name, std::string event_name, CElement* element, CMethodDefinition* method)
{
	_context_events[context_name + "." + event_name] = std::pair<CElement*, CMethodDefinition*>(element, method);
}


void CRunBytecode::bind_context_event(std::string context_name, std::string event_name, CElement* element, CMethodDefinition* method)
{
	(*_contextList)[context_name]->_events[event_name] = std::pair<CElement*, CMethodDefinition*>(element, method);
}


// void CRunBytecode::run_group_event_insert_data(std::string keys, std::string values)
// {
// 	std::map<std::string, std::pair<CElement*, CMethodDefinition*> >::iterator event = _events.find("on_insert_data");
//
// 	if (event != _events.end()) {
// 		_dataStack.push(keys);
// 		_dataStack.push(values);
//
// 		CActivationRecord* ar = new CActivationRecord(this, (*event).second.first, (*event).second.second->getName(), _ip, _dataStack); // TODO: referencia da referencia funciona ???
// 		_controlStack.push(ar);
// 	}
// }

#ifndef GPT_RUN_BYTECODE_H
#define GPT_RUN_BYTECODE_H

#include <string>
#include <vector>
#include <fstream>
#include <stack>

//#include "CHeader.hpp"
#include "SymbolTable.hpp"
#include "LibuvmDefs.hpp"
#include "UbivmDefs.hpp"
//#include "CBinString.hpp"
//#include "CBytecode.hpp"
//#include "Common.hpp"
#include "DataStack.hpp"
#include "AssemblyDefinition.hpp"
#include "MethodDefinition.hpp"
#include "ActivationRecord.hpp"
#include "Group.hpp"
#include "CommunicationProvider.hpp"


class CRunBytecode;

typedef void (CRunBytecode:: *OpcodePointer) ( );


class CRunBytecode
{
public:
	CRunBytecode(SOptions *options);
   ~CRunBytecode();
   bool readFromFile(std::string name);
//   bool readFromFile(std::ifstream &in);
	std::string toTextAssembly();
   int run();
private:
   void trace(const std::string &message);
   void error(const std::string &message);
   void initOpcodePointer();
   void step();
   void procWriteln();
   void procWrite();
   void procReadln();
   void procSleep();
//   void setIntData(const int &address, const int &value);
//   int  getIntData(const int &address);
   void setRealData(const int &address, const double &value);
   double getRealData(const int &address);
   void setStringData(const int &address, const std::string &value);
   std::string getStringData(const int &address);
   void popRA();
   void callSyslib(const std::string &libname, const std::string &procname);
	std::string getSymbolName(uint index);
	CSymbol* getSymbol(uint index);

   // opcodes
   void invalidOpcode(const std::string &opcode="");
   void lcallOpcode();
   void ldvarOpcode();
   void stvarOpcode();
   void stresultOpcode();
   void ldconstOpcode();
   void ldparamOpcode();
   void stopOpcode();
   void retOpcode();
   void mcallOpcode();
   void addOpcode();
   void subOpcode();
   void mulOpcode();
   void divOpcode();
   void ltOpcode();
   void gtOpcode();
   void leOpcode();
   void geOpcode();
   void eqOpcode();
   void neOpcode();
   void andOpcode();
   void orOpcode();
   void ifnotOpcode();
   void jmpOpcode();
   void newelemOpcode();
   void ldselfOpcode();
	void bindgOpcode();
	void dataafOpcode();
	void datadquOpcode();
	void dataquOpcode();
	void datalistOpcode();
	void stcontextOpcode();
	void ldcontextOpcode();
	void publishsOpcode();
	void scallOpcode();
	void sttabOpcode();
	void ldtabOpcode();
	void ldtuplekOpcode();
	void ldtuplevOpcode();
	void sttuplekOpcode();
	void sttuplevOpcode();
	void tabsizeOpcode();

//   CHeader         _header;
   CSymbolTable    _symbolTable;
//   CBinString      _globalData;
//   CBytecode       _code;
   OpcodePointer   _opcodePointer[OPCODE_COUNT];
   bool            _stop;
   int             _returnCode;
   CDataStack      _dataStack;
//   std::stack<int> _executionStack;
//   std::map<std::string, void*> syslibHandlerList;
   SIp _ip;
	CAssemblyDefinition _asmDef;
	CInstructionDefinition* _currentInstruction;
	std::stack<CActivationRecord*> _controlStack;
	std::map<std::string, CGroup*> _groupList;
	std::map<std::string, CLiteral> _contextsInfo;
	std::vector<CElement*> _elementList;
	CCommunicationProvider* _cp;
	SOptions* _options;
};

#endif

#ifndef GPT_RUN_BYTECODE_H
#define GPT_RUN_BYTECODE_H

#include <string>
#include <vector>
#include <fstream>
#include <stack>

class CRunBytecode;
struct SVmId;


#include "SymbolTable.hpp"
#include "LibuvmDefs.hpp"
#include "UbivmDefs.hpp"
#include "DataStack.hpp"
#include "AssemblyDefinition.hpp"
#include "MethodDefinition.hpp"
#include "ActivationRecord.hpp"
#include "Group.hpp"
#include "CommunicationProvider.hpp"




typedef void (CRunBytecode:: *OpcodePointer)();


class CRunBytecode
{
public:
	CRunBytecode();
	~CRunBytecode();
	int run();
// 	int run(std::string entity_name, CElement* element);
	CDataStack      _dataStack;
	bool                   _dataReady;
	CMultiIndex<CLiteral>* _dataListReplyTable;
	udp::endpoint _last_endpoint;
	SVmId _lastSrcVmId;
	bool scallCode(std::string groupName, std::string serviceName, std::vector<CLiteral> arguments, std::vector<CLiteral>& results);
private:
	void _initOpcodePointer();
	void trace(const std::string &message);
   void error(const std::string &message);
   void step();
	void run_bytecode();
   void procWriteln();
   void procWrite();
   void procReadln();
   void procSleep();
//   void setIntData(const int &address, const int &value);
//   int  getIntData(const int &address);
//    void setRealData(const int &address, const double &value);
//    double getRealData(const int &address);
//    void setStringData(const int &address, const std::string &value);
//    std::string getStringData(const int &address);
//    void popRA();
   void callSyslib(const std::string &procname);
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
	void datanbdquOpcode();
	void datanbquOpcode();
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

	OpcodePointer   _opcodePointer[OPCODE_COUNT];
	bool            _stop;
	int             _returnCode;
	SIp _ip;
	CInstructionDefinition* _currentInstruction;
	std::stack<CActivationRecord*> _controlStack;
	SOptions* _options;
	CAssemblyDefinition* _asmDef;
	std::map<std::string, void*>* _syslibHandlerList;
	std::vector<CElement*>* _elementList;
	std::map<std::string, CGroup*>* _groupList;
	std::map<std::string, CLiteral>* _contextsInfo;
// 	CCommunicationProvider* _cp;
// 	CDataProvider* _dp;
	static uint _bceCount;
	SVmId _vmId;
};

#endif

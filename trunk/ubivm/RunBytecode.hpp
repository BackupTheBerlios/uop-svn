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
	SIp _ip;
	std::stack<CActivationRecord*> _controlStack;

	bool scallCode(std::string groupName, std::string serviceName, std::vector<CLiteral> arguments, std::vector<CLiteral>& results);
	void run_bytecode();
	void run_bytecode_until(unsigned char return_after_opcode=INVALID_OPCODE);
private:
	void _initOpcodePointer();
	void trace(const std::string &message);
   void error(const std::string &message);
	unsigned char step();
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
	void ldpropOpcode();
	void stpropOpcode();
	void belementevOpcode();
	void bcontextevOpcode();
	void bgroupevOpcode();

	OpcodePointer   _opcodePointer[OPCODE_COUNT];
	bool            _stop;
	int             _returnCode;
	CInstructionDefinition* _currentInstruction;
	SOptions* _options;
	CAssemblyDefinition* _asmDef;
	std::map<std::string, void*>* _syslibHandlerList;
	std::vector<CElement*>* _elementList;
	std::map<std::string, CGroup*>* _groupList;
	std::map<std::string, CLiteral>* _contextsInfo;
	std::map<std::string, std::pair<CElement*, CMethodDefinition*> > _context_events; // TODO: isso deveria ficar dentro de uma classe CContextInfo

	void bind_context_event(std::string context_name, std::string event_name, CElement* element, CMethodDefinition* method);
	void bind_group_event(std::string group_name, std::string event_name, CElement* element, CMethodDefinition* method);

// 	CCommunicationProvider* _cp;
// 	CDataProvider* _dp;
	static uint _bceCount;
	SVmId _vmId;
	void run_property_event(CElement* element, CMethodDefinition* method, std::string name, CLiteral old_value, CLiteral new_value);
	void run_group_event_insert_data(std::string keys, std::string values);
};

#endif

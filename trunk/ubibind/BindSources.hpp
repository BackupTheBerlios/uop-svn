#ifndef UOP_BIND_SOURCES_HPP
#define UOP_BIND_SOURCES_HPP

#include "TextFile.hpp"

#include <string>
#include <vector>
#include <map>
#include <list>

class CBindSources
{
public:
   CBindSources();
   void setModuleName(std::string moduleName);
   void setDefinitions(std::string definitions);
   void addFunction(std::string returnType, std::string functionName, std::vector<std::string> parameters);
   void writeHeaders();
//    void addSubroutineBind(
//          const std::string &name, 
//          const std::pair<std::string,std::string> &returnType,
//          std::vector<std::pair<std::string, std::pair<std::string, std::string> > > parameters,
//          const std::string &functionBind,
//          std::vector<std::string> arguments
//    );
   void writeFooters();
   void addLinkerLib(const std::string &lib);
   void addHeader(const std::string &header);
//   std::string getHppSource()
//   {
//      return hppSource.getText();
//   }
   std::string getCppText()
   {
      return cppSource.getText();
   }
   std::string getMakefileText()
   {
      return makefileSource.getText();
   }
   void addTypeMapIn(std::string mapFrom, std::string mapTo);
   void addTypeMapOut(std::string mapFrom, std::string mapTo);
private:
   std::string _moduleName;
   std::string _definitions;
//   CTextFile hppSource;
   CTextFile cppSource;
   CTextFile makefileSource;
   std::map<std::string, std::string> _mapToCppType;
   std::list<std::string> _linkerLibList;
   std::list<std::string> _headerList;

   std::string codeToPopParameter(const std::string &name, const std::string &type);
   std::string codeToPushResult(const std::string &name, const std::string &type);
   std::string getMapGptToCppType(const std::string &type);
   std::map<std::string, std::string> _mapPop;
   std::map<std::string, std::string> _mapPush;
};

#endif


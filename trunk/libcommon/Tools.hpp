#ifndef GPT_TOOLS_H
#define GPT_TOOLS_H

#include <iomanip>

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <sstream>


int hexToInt(const char *);
std::string pad(std::string, unsigned int);
std::string lpad(std::string, unsigned int);
std::string intToHex(unsigned int, int = -1);
std::string strZero(std::string, unsigned int);
std::string strZero(int, unsigned int);
std::string dataToHex(char *, unsigned int);
std::string dataToHex( char *, unsigned int, unsigned int);
int binToInt(const char *);
int octToInt(const char *);
std::string itoa(int);
std::string itobool(int);
std::string ftoa(double);
std::string strtoupper(std::string);
std::string strToUpperWithEscapeControls(std::string);
std::string alltrim(std::string);
std::string wo_ctrl_chrs(std::string str, char = ' ');
bool streamtoken(std::stringstream&, std::string&, std::string&);
const std::string typeToText(const int &type);
const std::string typeInAsm( const int &type );
const int typeToLiteral( const int &type );
int getTypeSize(const int &type);
int realAddress(int address);
std::string realAddressString(int address);
int sumAddress(int address, int value);
int  toUTF8Char(const std::string&);
void appendUTF8Char(std::string& text, int c);
std::string removeQuotes(std::string text);

#endif


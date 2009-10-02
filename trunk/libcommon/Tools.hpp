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
// std::string& getStringWithTab(string, string);
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

/*
static void cb_log(int prior, const char *format, ...)
{
	if (!debug || prior > debug_prior)
		return;

	va_list ap;


	va_start(ap, format);
	vfprintf(stdout, format, ap);
	fputc('\n', stdout);
	va_end(ap);
}


void set_log_callback(void (*log_callback) (int prior, const char *msg, ...))
{
	_log_callback = log_callback;
}

extern void (*log_callback) (int prior, const char *msg, ...);

#define LOG_EMERG(msg, ...)   if (debug && log_callback) (*log_callback)(LOG_EMERG,   msg, ##__VA_ARGS__)
#define LOG_ALERT(msg, ...)   if (debug && log_callback) (*log_callback)(LOG_ALERT,   msg, ##__VA_ARGS__)
#define LOG_CRIT(msg, ...)    if (debug && log_callback) (*log_callback)(LOG_CRIT,    msg, ##__VA_ARGS__)
#define LOG_ERR(msg, ...)     if (debug && log_callback) (*log_callback)(LOG_ERR,     msg, ##__VA_ARGS__)
#define LOG_WARNING(msg, ...) if (debug && log_callback) (*log_callback)(LOG_WARNING, msg, ##__VA_ARGS__)
#define LOG_NOTICE(msg, ...)  if (debug && log_callback) (*log_callback)(LOG_NOTICE,  msg, ##__VA_ARGS__)
#define LOG_INFO(msg, ...)    if (debug && log_callback) (*log_callback)(LOG_INFO,    msg, ##__VA_ARGS__)
#define LOG_DEBUG(msg, ...)   if (debug && log_callback) (*log_callback)(LOG_DEBUG,   msg, ##__VA_ARGS__)

void xxx_dbgmsg  (char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
void xxx_errormsg(char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
void xxx_warnmsg (char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
void xxx_noticemsg (char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
void xxx_infomsg (char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
*/

#endif


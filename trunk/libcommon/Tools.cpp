//#include "PortugolParserTokenTypes.hpp"

#include "Tools.hpp"
//#include "CSymbol.hpp" // TODO: nao ta legal...
//#include "Common.hpp"


int hexToInt(const char* _value) {
    int result = 0;
    char *position;
    char conversionTable[] = "0123456789ABCDEF";

    while (*_value) {
        position = strchr(conversionTable, *_value);
        if (position == NULL)
            return 0;

        result <<= 4;
        result = result | (position - conversionTable);
        _value++;
    }

    return result;
}

std::string pad(std::string _text, unsigned int _size) {
    if (_size > _text.length())
        _text.append(_size - _text.length(), ' ');

    return _text;
}

std::string lpad(std::string _text, unsigned int _size) {
    if (_size > _text.length())
        _text = std::string(_size - _text.length(), ' ') + _text;

    return _text;
}

std::string intToHex(unsigned int _value, int _size) {
    std::string codHex = "0123456789ABCDEF";
    std::string result;
    int nible;

    while (_value > 0) {
        nible = _value & 0xF;
        _value >>= 4;
        result = codHex[nible] + result;
    }

    if ( _size == -1 )
        _size = 1;

    return strZero(result, _size);
    // if (_size == -1)
    //     return( result );
    // else
    //     return( strZero( result, _size ) );
    //
}

std::string strZero(std::string _value, unsigned int _size) {
    while (_value.length() < _size) {
        _value = '0' + _value;
    }

    return _value;
}

std::string strZero(int _value, unsigned int _size) {
    std::string result = itoa(_value);

    while (result.length() < _size) {
        result = '0' + result;
    }

    return result;
}

std::string dataToHex(char _code[], unsigned int _length) {
    std::string result;
    unsigned int count;

    for (count = 0; count < _length; count++)
        result += intToHex(_code[count], 2);

    return result;
}

std::string dataToHex(char _code[], unsigned int _start, unsigned int _length) {
    std::string result;
    unsigned int count;

    for (count = _start; count - _start < _length; count++)
        result += intToHex(_code[count], 2);

    return result;
}

int binToInt(const char* _binValue) {
    int intValue = 0;
    int length = strlen(_binValue) - 1;
    int countBit;

    for (countBit = length; countBit >= 0; countBit--) {
        if (_binValue[countBit] == '1')
            intValue += int(pow(2.0, length - countBit));
    }

    return intValue;
}

std::string itoa(int _number) {
    std::stringstream s;

    s << _number;
    return s.str();
}

std::string ftoa(double _value) {
    std::stringstream s;

    s <<  setiosflags(std::ios::fixed) << _value;
    
    return s.str();
}

std::string itobool(int _number) {
    if (_number == 0)
        return "false";
    else
        return "true";
}

std::string strtoupper(std::string str) {
    unsigned int count;

    for (count = 0; count < str.size(); count++)
        str[count] = toupper(str[count]);

    return str;
}

std::string strToUpperWithEscapeControls(std::string str) {
    unsigned int count;

    for (count = 0; count < str.size(); count++) {
        if (str[count] == '\\')
            count += 2;
        else
            str[count] = toupper(str[count]);
    }

    return str;
}

std::string alltrim(std::string str) {
    // crap version...  :-)
    // precisamos usar `find', `rfind'! --felipek
    while (str[0] == ' ')
        str.erase(0, 1);

    while (str[str.length() - 1] == ' ')
        str.erase(str.length() - 1, 1);

    return str;
}

std::string wo_ctrl_chrs(std::string str, char chr_to_put) {
    unsigned int chr_number;

    for (chr_number = 0; chr_number < str.size(); chr_number++) {
        if (str[chr_number] < 32)
            str[chr_number] = chr_to_put;
    }

    return str;
}


/*const std::string typeToText(const int &type)
{
   if (type == PortugolParserTokenTypes::T_INT_LIT) {
      return "int";
   } else if (type == PortugolParserTokenTypes::T_CARAC_LIT) {
      return "char";
   } else if (type == PortugolParserTokenTypes::T_STRING_LIT) {
      return "std::string";
   } else if (type == PortugolParserTokenTypes::T_REAL_LIT) {
      return "real";
   } else if (type == PortugolParserTokenTypes::T_IDENTIFICADOR) {
      return "id";
   }

   return "ERRO !!!";
}

const std::string typeInAsm( const int &type )
{
   if (type == PortugolParserTokenTypes::T_KW_INTEIRO) {
      return "int";
   } else if (type == PortugolParserTokenTypes::T_KW_LITERAL) {
      return "std::string";
   } else if (type == PortugolParserTokenTypes::T_KW_CARACTERE) {
      return "char";
   } else if (type == PortugolParserTokenTypes::T_KW_LOGICO) {
      return "bool";
   } else if (type == PortugolParserTokenTypes::T_KW_REAL) {
      return "real";
   } else if (type == PortugolParserTokenTypes::T_KW_CORINGA) {
      return "pointer ???";
   } else if (type == PortugolParserTokenTypes::T_KW_MATRIZ) {
      return "matrix";
   }

   return "ERRO !!!";
}


const int typeToLiteral( const int &type )
{
   switch (type) {
      case PortugolParserTokenTypes::T_KW_INTEIRO:
         return PortugolParserTokenTypes::T_INT_LIT;
      case PortugolParserTokenTypes::T_KW_LITERAL:
         return PortugolParserTokenTypes::T_STRING_LIT;
      case PortugolParserTokenTypes::T_KW_CARACTERE:
         return PortugolParserTokenTypes::T_CARAC_LIT;
      case PortugolParserTokenTypes::T_KW_LOGICO:
         return PortugolParserTokenTypes::T_INT_LIT;
//      case PortugolParserTokenTypes::T_KW_CORINGA:
//         return "pointer ???";
//      case PortugolParserTokenTypes::T_KW_MATRIZ:
//          return PortugolParserTokenTypes::T_MATRIZ;
      default:
          return 0;
          // trow exception ???
   }
}
*/

/*
int getTypeSize(const int &type) // TODO: para o tipo DATA essa funcao deveria receber o size tambem...
{
   switch(type) {
   case CSymbol::INT:
   case CSymbol::CHAR:
   case CSymbol::BOOL:
      return sizeof(int);
   case CSymbol::REAL:
      return sizeof(double);
   case CSymbol::STRING:
      return sizeof(char)+sizeof(void*);
   case CSymbol::MATRIX:
   case CSymbol::POINTER:
      return sizeof(void*);
   }
   return 0;
}


int realAddress(int address)
{
   if (IS_LOCAL_ADDRESS(address)) {
      address = address & UNSET_LOCAL_BIT;
   }
   if (IS_NEG_ADDRESS(address)) {
      address = address & UNSET_NEG_BIT;
      address *= -1;
   }
   return address;
}

std::string realAddressString(int address)
{
   std::string result;

   if (IS_LOCAL_ADDRESS(address)) {
      address = address & UNSET_LOCAL_BIT;
      result += "LOCAL ";
   }
   if (IS_NEG_ADDRESS(address)) {
      address = address & UNSET_NEG_BIT;
      address *= -1;
      result += "NEG ";
   }
   result += "value ";
   result += itoa(address);

   return result;
}

int sumAddress(int address, int value)
{
// TODO: ao somar dados em address os limites deveriam ser testados
   bool localAddress = false;
   bool negAddress = false;

   if (IS_LOCAL_ADDRESS(address)) {
      address = address & UNSET_LOCAL_BIT;
      localAddress = true;
   }
   if (IS_NEG_ADDRESS(address)) {
      address = address & UNSET_NEG_BIT;
      address *= -1;
      negAddress = true;
   }
   address += value;
   if (localAddress) {
      address = abs(address) | SET_LOCAL_BIT;
   }
   if (negAddress) {
      address = abs(address) | SET_NEG_BIT;
   }
   return address;
}

int toUTF8Char(const std::string& chr)
{
  int ch = 0;
  int inchar = chr[0];

  if( (inchar & 0x80) == 0 )
    return inchar;

  unsigned int need = 0;
  if( (inchar & 0xF8) == 0xF8 )
  {
    ch = inchar & 7;
    need = 3;
  }
  else if( (inchar & 0xE0) == 0xE0 )
  {
    ch = inchar & 0xF;
    need = 2;
  }
  else if( (inchar & 0xC0) == 0xC0 )
  {
    ch = inchar & 0x1F;
    need = 1;
  }  

  int i = 1;
  while( need )
  {
    inchar = chr[i++];
    ch <<= 6;
    ch += inchar & 0x3F;
    need--;
  }
  return ch;
}

void appendUTF8Char(std::string& text, int c)
{
  if (c < 0x80)
  {
    text += c;
    return;
  }
  else if (c < 0x800)
  {
    text += ( (c >> 6) | 0xC0 );
    text += ( c & 0x3F | 0x80 );
  }
  else if (c < 0x10000)
  {
    text += ( (c >> 12) | 0xE0 );
    text += ( ((c >> 6) & 0x3F) | 0x80 );
    text += ( (c & 0x3F) | 0x80 );
  }
  else if (c < 0x200000)
  {
    text += ( (c >> 18) | 0xF0 );				// first 3 bits
    text += ( (((c >> 16) & 0x3) << 4) |
              ((c >> 12) & 0xF) | 0x80 );
    text += ( ((c >> 6) & 0x3F) | 0x80 );
    text += ( (c & 0x3F) | 0x80 );
  }  
}
*/

std::string removeQuotes(std::string text)
{
	return text.substr(1, text.length()-2);
}

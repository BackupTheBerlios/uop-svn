#include "Tools.hpp"


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

std::string removeQuotes(std::string text)
{
	return text.substr(1, text.length()-2);
}

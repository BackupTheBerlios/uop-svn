#ifndef LIBUVM_BIN_STRING_HPP
#define LIBUVM_BIN_STRING_HPP

#include <sys/types.h>

#include <string>

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CBinString
{
public:
    CBinString();
    ~CBinString();

    void save(const void* data, size_t size);
    void load(const void* data, size_t size);
/*	void save(uint data) {
		save(&data, sizeof(data));
	}
	void load(uint* data) {
		load(data, sizeof(data));
	}
	void save(unsigned short int data) {
		save(&data, sizeof(data));
	}
	void load(unsigned short int* data) {
		load(data, sizeof(data));
	}*/
	void assign(std::string data);
	size_t size() const
	{
		return _data.size();
	}
	//TODO: e se o q eu estou guardando passar de um byte ??? wchar ???
	u_char get(uint pos) const
	{
		return _data[pos];
	}
	std::string getData() const
	{
		return _data;
	}
private:
	std::string _data;
};

#endif


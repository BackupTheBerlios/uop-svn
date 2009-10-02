#ifndef UBIBIND_DEFS_HPP
#define UBIBIND_DEFS_HPP

struct SParamOptions {
	std::string sourceFilename;
	std::string outputFilename;
};

enum LiteralType {
	IntegerType,
	IntegerPointerType,
	CharType,
	CharPointerType,
	DoubleType,
	DoublePointerType,
	FloatType,
	FloatPointerType,
	UserType,
	UserPointerType
};

#endif


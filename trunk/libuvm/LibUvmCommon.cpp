#include "LibUvmCommon.hpp"

const std::string typeToText(const LiteralType &type)
{
	if (type == StringType) {
		return "string";
	} else if (type == IntegerType) {
		return "int";
	} else if (type == RealType) {
		return "real";
	} else if (type == BooleanType) {
		return "bool";
	} else if (type == ElementType) {
		return "element";
	}

	return "ERRO !!!";
}
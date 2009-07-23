#ifndef DEFS_HPP
#define DEFS_HPP

typedef int  LabelType;
typedef unsigned short int ArgType;

enum OpcodeType {
	LCALL_OPCODE = 0,
	LDVAR_OPCODE,
	STVAR_OPCODE,
	LDCONST_OPCODE,
	LDNIL_OPCODE,
	STOP_OPCODE,
	ADD_OPCODE,
	SUB_OPCODE,
	OR_OPCODE,
	AND_OPCODE,
	LT_OPCODE,
	GT_OPCODE,
	LE_OPCODE,
	GE_OPCODE,
	EQ_OPCODE,
	NE_OPCODE,
	DIV_OPCODE,
	MUL_OPCODE,
	MOD_OPCODE,
	IFNOT_OPCODE,
	IF_OPCODE,
	JMP_OPCODE,
	RET_OPCODE,
	MCALL_OPCODE,
	LDPARAM_OPCODE,
	STRESULT_OPCODE,
	NEWELEM_OPCODE,
	LDSELF_OPCODE,
	INVALID_OPCODE,
	OPCODE_COUNT
};

enum LiteralType {
	StringType = 'S',
	IntegerType = 'I',
	RealType = 'R',
	BooleanType = 'B',
	MethodType = 'M',
//	EntityType = 'E',
	ElementType= 'E'
// 	PointerType = 'P'
};

enum SymbolType {
	stringttt,
	integerttt,
	realttt
};

enum VisibilityType {
	PublicVisibility = '+',
	PrivateVisibility = '-'
};

#endif


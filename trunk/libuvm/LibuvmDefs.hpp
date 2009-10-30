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
	BINDG_OPCODE,
	LEAVEG_OPCODE,
	DATAAF_OPCODE,
	DATADQU_OPCODE,
	DATAQU_OPCODE,
	DATALIST_OPCODE,
	PUBLISHS_OPCODE,
	SCALL_OPCODE,
	FINDS_OPCODE,
	BINDS_OPCODE,
	LDCONTEXT_OPCODE,
	STCONTEXT_OPCODE,
	STTAB_OPCODE,  // TODO: daria para termos um opcode so para manipular tabelas de qualquer dimensao, mas o assembly ficaria um pouco maior pq, ao inves de ldtab indicar a tabela, a tabela deveria ser carregada antes na pilha... algo como "t[1,2]=10 => ldconst 1, ldref t, ldtab, lsconst 2, ldtab, ldconst 10, sttab"
	LDTAB_OPCODE,
	LDTUPLEK_OPCODE,
	LDTUPLEV_OPCODE,
	STTUPLEK_OPCODE,
	STTUPLEV_OPCODE,
	TABSIZE_OPCODE,
/*	LDIDENTITY_OPCODE,
	LDLOCATION_OPCODE,
	LDTIME_OPCODE,
	LDACTIVITY_OPCODE,*/
	DATANBQU_OPCODE,
	DATANBDQU_OPCODE,
	STPARAM_OPCODE,
	LDPROP_OPCODE,
	STPROP_OPCODE,
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
	ElementType= 'E',
// 	PointerType = 'P'
	UserdataType= 'U',
	TableType = 'L',
	TupleType = 'T'
};



// TODO: o enum acima deveria ficar dentro da declaracao da classe literal... algo como:
// class CLiteral
// {
// public:
//    enum EScope {
//       GLOBAL = 'G',
//       LOCAL  = 'L'
//    };
//    enum ECategory {
//       PROC  = 'P',
//       CONST = 'C',
//       VAR   = 'V',
//       PARAM = 'P'
//    };

enum SymbolType {
	stringttt,
	integerttt,
	realttt
};

enum VisibilityType {
	PublicVisibility  = '+',
	PrivateVisibility = '-'
};

#endif


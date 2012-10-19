#ifndef DEFS_HPP
#define DEFS_HPP

typedef int  LabelType;
typedef unsigned short int ArgType;

enum OpcodeType {
	// Instrucoes de uso geral
	LDCONST_OPCODE = 0,
	LDCONST_0_OPCODE,
	LDCONST_1_OPCODE,
	LDCONST_2_OPCODE,
	LDCONST_3_OPCODE,
	LDCONST_4_OPCODE,
	LDCONST_5_OPCODE,
	LDCONST_0_0_OPCODE,
	LDCONST_1_0_OPCODE,
	LDCONST_2_0_OPCODE,
	LDCONST_3_0_OPCODE,
	LDCONST_4_0_OPCODE,
	LDCONST_5_0_OPCODE,
	LDVAR_OPCODE,
	STVAR_OPCODE,
	LDPARAM_OPCODE,
	STPARAM_OPCODE,
	LDPROP_OPCODE,
	STPROP_OPCODE,
	LDNIL_OPCODE,
	STNIL_OPCODE,
	LDRESULT_OPCODE,
	STRESULT_OPCODE,

	// Instrucoes aritmeticas
	ADD_OPCODE,
	SUB_OPCODE,
	MUL_OPCODE,
	DIV_OPCODE,
	MOD_OPCODE,

	// Instrucoes logicas
	AND_OPCODE,
	OR_OPCODE,
	NOT_OPCODE,
	XOR_OPCODE,

	// Instrucoes relacionais
	GE_OPCODE,
	LE_OPCODE,
	EQ_OPCODE,
	NE_OPCODE,
	GT_OPCODE,
	LT_OPCODE,

	// Instrucoes para suporte a OO
	NEWELEM_OPCODE,
	DELELEM_OPCODE,
	LDSELF_OPCODE,

	// Instrucoes para controle do fluxo de execucao
	LCALL_OPCODE,
	MCALL_OPCODE,
	EXIT_OPCODE,
	HALT_OPCODE,
	JMP_OPCODE,
	IFNOT_OPCODE,
	IF_OPCODE,
	RET_OPCODE,
	NOP_OPCODE,

	// Instrucoes que manipulam contextos - membros
	MJOIN_OPCODE,
	MLEAVE_OPCODE,
	MLIST_OPCODE,

	// Instrucoes que manipulam contextos - conteudos
	CPUBLISH_OPCODE,
	CGET_OPCODE,
	CGETNB_OPCODE,
	CFIND_OPCODE,
	CFINDNB_OPCODE,
	CREM_OPCODE,
	CREMNB_OPCODE,
	CLIST_OPCODE,

	// Instrucoes que manipulam contextos - servicos
	SPUBLISH_OPCODE,
	SFIND_OPCODE,
	SFINDNB_OPCODE,
	SRUN_OPCODE,
	SRUNNB_OPCODE,
	SREM_OPCODE,
	SREMNB_OPCODE,
	SLIST_OPCODE,

	// Instrucoes que manipulam informacoes dos contextos privados
	LDCONTEXTI_OPCODE,
	STCONTEXTI_OPCODE,

	// Instrucoes para mobilidade
	MOVE_OPCODE,

	// Instrucoes para concorrencia
	CMCALL_OPCODE,
	CMWAIT_OPCODE,

	// Instrucoes para manipulacao de tabelas
	STTAB_OPCODE,  // TODO: daria para termos um opcode so para manipular tabelas de qualquer dimensao, mas o assembly ficaria um pouco maior pq, ao inves de ldtab indicar a tabela, a tabela deveria ser carregada antes na pilha... algo como "t[1,2]=10 => ldconst 1, ldref t, ldtab, lsconst 2, ldtab, ldconst 10, sttab"
	LDTAB_OPCODE,
	TABSIZE_OPCODE,

	// Instrucoes para manipulacao de tuplas
	STTUPLEK_OPCODE,
	LDTUPLEK_OPCODE,
	STTUPLER_OPCODE,
	LDTUPLER_OPCODE,

	BELEMENTEV_OPCODE,
	BCONTEXTIEV_OPCODE,
	BCONTEXTEV_OPCODE,
	INVALID_OPCODE,
	OPCODE_COUNT
};

enum LiteralType {
	StringType = 'S',
	IntegerType = 'I',
	RealType = 'R',
	BooleanType = 'B',
	MethodType = 'M',
	ElementType= 'E',
	UserdataType= 'U',
	TableType = 'L',
	TupleType = 'T',
	PointerType = 'P'
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


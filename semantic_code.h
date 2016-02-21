#define MAXIDLEN 33
typedef char string[MAXIDLEN];
typedef struct operator
{
	enum op {PLUS, MINUS} operator;
}op_rec;
// expression types
enum expr
{
	IDEXPR, LITERALEXPR, TEMPEXPR
};

// for <primary> and <expression>

typedef struct expression
{
	enum expr kind;
	union{
		string name; // for IDEXPR, TEMPEXPR
		int val; // for LITERALEXPR
	};
}expr_rec;

// is s in the symbol table
extern int lookup(string s);
// put s unconditionally into symbol table
extern void enter(string s);

void check_id(string s)
{
	if(!lookup(s))
	{
		enter(s);
		generate("Declare", s, "Integer","");
	}
}

1
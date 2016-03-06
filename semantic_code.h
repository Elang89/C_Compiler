#ifndef SEMANTIC_CODE_H
#define SEMANTIC_CODE_H
#define MAXIDLEN 33

char list[512][MAXIDLEN];

int list_size;

typedef char string[MAXIDLEN];

typedef struct operator
{
	enum op { PLUS, MINUS } operator;
}	op_rec;

// expression types
enum expr { IDEXPR, LITERALEXPR, TEMPEXPR };

// for <primary> and <expression>
typedef struct expression
{
	enum expr kind;
	int status;
	union{
		string name; // for IDEXPR, TEMPEXPR
		int val; // for LITERALEXPR
	};
}	expr_rec;

void generate(string op_code, string op1,
	string op2, string result);

char* extract_expression(expr_rec e);

char* extract_operation(op_rec e);

void check_id(string s);

char * get_temp();

void start();

void finish();

void assign(expr_rec target, expr_rec source);

op_rec process_op();

expr_rec process_literal();

expr_rec gen_infix(expr_rec e1, op_rec op, expr_rec e2);

void read_id(expr_rec in_var);

void write_expr(expr_rec out_expr);

expr_rec process_id();

FILE * new_file_mips;


#endif
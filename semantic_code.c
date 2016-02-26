#include <string.h>
#include "semantic_code.h"
#include "token_types.h"

void generate(string op_code, string op1,
	string op2, string result)
{

}

string* extract_expression(expr_rec e)
{
	
}

string* extract_operation(op_rec op)
{

}

void enter(string s)
{
	strcpy(list[list_size], s);
	list_size++; 
} 

int lookup(string s)
{
	char element[33];
	int i;
	for(i = 0; i < sizeof(list); i++)
	{
		strcpy(element, list[i]);
		if(strcmp(element, s) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void check_id(string s)
{
	if(!lookup(s))
	{
		enter(s);
		generate("Declare", s, "Integer","");
	}
}
char * get_temp(void)
{
	// max temporary allocated so far
	static int max_temp = 0;
	static char tempname[MAXIDLEN];

	max_temp++;
	sprintf(tempname, "Temp%d",max_temp);
	check_id(tempname);
	return tempname;
}

void start(void)
{
	// Semantic initializations, none needed
}

void finish(void)
{
	// Generate code to finish program
	generate("Halt", "", "", "");
}
void assign(expr_rec target, expr_rec source)
{
	//Generate code for assignment
	generate("Store", extract_expression(source), target.name, "");
}

op_rec process_op(void)
{
	// Produce operator descriptor
	op_rec o;
	if(current_token == PLUSOP)
	{
		o.operator = PLUS;
	}
	else
	{
		o.operator = MINUS;
	}
	return o;
}
expr_rec gen_infix(expr_rec e1, op_rec op, expr_rec e2)
{
	expr_rec e_rec;
	
	// An expr_rec with temp variant set
	
	e_rec.kind = TEMPEXPR;
	
	/*
	* Generate code for infix operation
	* Get result temp and set up semantic record
	* for result.
	*
	*/

	strcpy(e_rec.name, get_temp());

	generate(extract_operation(op), extract_expression(e1), 
		extract_expression(e2), e_rec.name);
	return e_rec;
}

void read_id(expr_rec in_var)
{
	// Generate code for read
	generate("Read", in_var.name, "Integer", "");

}

expr_rec process_id(void)
{
	expr_rec t;
	// Declare ID and build a
	// corresponding semantic record
	check_id(token_buffer);
	t.kind = IDEXPR;
	strcpy(t.name, token_buffer);
	return t;
}
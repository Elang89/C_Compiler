#include <string.h>
#include <stdio.h>
#include "semantic_code.h"
#include "token_types.h"

void generate(string op_code, string op1,
	string op2, string result)
{
	printf("Print Generate \n");

}

char* extract_expression(expr_rec expression)
{
	char * buffer;	
	if(expression.kind == TEMPEXPR || expression.kind == IDEXPR) 
	{
		return expression.name;
	}
	buffer = malloc(sizeof(expression.val));
	return sprintf(buffer, "%d", expression.val);
}

char* extract_operation(op_rec oper)
{
	if(oper.operator == PLUSOP)
	{
		return "add";
	}
	return "sub";
}

void enter(string s)
{
	strcpy(list[list_size], s);
	list_size++; 
} 

int lookup(string s)
{
	int i;
	for(i = 0; i < sizeof(list); i++)
	{
		if(strcmp(list[i], s))
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

char * get_temp()
{
	
	// max temporary allocated so far
	static int max_temp = 0;
	static char tempname[MAXIDLEN];

	max_temp++;
	sprintf(tempname,"Temp&%d", max_temp);
	check_id(tempname);
	return tempname;
}

void start()
{
	// Semantic initializations, none needed
	new_file_mips = fopen(new_file_name, "w+");
	printf("New Mips file was created \n");
	fprintf(new_file_mips,"Global Main...", "\n");
	fclose(new_file_mips);
}

void finish()
{
	// Generate code to finish program
	generate("Halt", "", "", "");
}
void assign(expr_rec target, expr_rec source)
{
	//Generate code for assignment
	generate("Store", extract_expression(source), target.name, "");
}

op_rec process_op()
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

expr_rec process_id()
{
	expr_rec t;
	// Declare ID and build a
	// corresponding semantic record
	check_id(token_buffer);
	t.kind = IDEXPR;
	strcpy(t.name, token_buffer);
	return t;
}
expr_rec process_literal()
{
	expr_rec t;
	/*
	 * Convert literal to a numeric representation
	 * and build semantic record
	*/
	 t.kind = LITERALEXPR;
	 (void) sscanf(token_buffer, "%d",& t.val);
	 return t;
}

void write_expr(expr_rec out_expr)
{
	generate("Write", extract_expression(out_expr), "Integer","");

}

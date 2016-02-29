#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "parser.h"
#include "parser_additional_functions.h"
#include "token_types.h"
#include "semantic_code.h"

void system_goal()  // We must match a token sequence generate by program followed bt SCANOF
{
	/* <system goal> ::= <program> SCANEOF */
	
	program();
	match(SCANEOF); 
}

void program()
{
	/* <program> ::= BEGIN <statement list> END*/
	start();
	match(BEGIN);
	statement_list();
	match(END);
	finish();
}

void statement_list()
{
	/*
	* <statement list> ::= <statement> {<statement>} 
	*
	*/

	statement();

	while(true)
	{
		switch(next_token())// return the next token
		{
			case ID:
			case READ:
			case WRITE:
				statement();
				break;
			default:
				return;
		}
	}
}

void statement()
{
	expr_rec semantic_record;
	token tok = next_token();
	switch(tok)
	{
		case ID:
			// <statement> ::= <expression>;
			match(ID);
			semantic_record = process_id();
			printf("%s\n",semantic_record.name);
			match(ASSIGNOP);
			expression(& semantic_record);
			match(SEMICOLON);
			break;
		case READ:
			// <Statement> ::= READ(<id list>);
			match(READ);
			match(LPAREN);
			id_list();
			match(RPAREN);
			match(SEMICOLON);
			break;
		case WRITE:
			// <statement> ::= WRITE (<expr list>);
			match(WRITE);
			match(LPAREN);
			expr_list();
			match(RPAREN);
			match(SEMICOLON);
			break;
		default:
			printf("statement error \n");
			syntax_error(tok);
			break;
	}
}

void id_list()
{
	expr_rec semantic_record;
	// <id_list> ::= ID { , ID}
	match(ID);
	while(next_token() == COMMA)
	{
		match(COMMA);
		match(ID);
		semantic_record = process_id();
		read_id(semantic_record);
	}
}

void expression(expr_rec * result)
{
	expr_rec temp_rec;
	expr_rec left_operand;
	expr_rec right_operand;
	op_rec op;
	token t;
	/*
	*	<expression> ::= <primary>{<add op><primary>}
	*/
	if(result != NULL)
	{
		temp_rec = *result;
	}

	primary(& left_operand);
	
	for(t = next_token(); t == PLUSOP || t == MINUSOP;
		t = next_token())
	{
		add_op(& op);
		primary(& right_operand);
		left_operand = gen_infix(left_operand, op, right_operand);
	}
	printf("%d", left_operand.val);

	*result = left_operand;

	if(temp_rec.kind == IDEXPR)
	{
		assign(temp_rec, *result);
	}
	else
	{
		write_expr(*result);
	}

}

void expr_list()
{
	// <expr_list> ::= <expression>{ , <expression> }
	expression(NULL);
	while(next_token() == COMMA)
	{
		match(COMMA);
		expression(NULL);
	}
}

void add_op(op_rec *result)
{
	op_rec semantic_record;
	token tok = next_token();
	// <addop> ::= PLUSOP | MINUSOP 
	if(tok == PLUSOP || tok == MINUSOP)
	{
		match(tok);
		semantic_record = process_op();

	}
	else
	{
		printf("addop error");
		syntax_error(tok);
	}
	*result = semantic_record;
}

void primary(expr_rec * record)
{
	token tok = next_token();
	expr_rec semantic_record;
	switch(tok)
	{
		case LPAREN:
			// <primary>(<expression>)
			match(LPAREN);
			expression(record);
			match(RPAREN);
			break;
		case ID:
			//<primary> ::= ID
			match(ID);
			semantic_record = process_id();
			*record = semantic_record;
			break;
		case INTLITERAL:
			// <primary> ::= INTLITERAL
			match(INTLITERAL);
			semantic_record = process_literal();
			*record = semantic_record;
			break;
		default:
			printf("primary error \n");
			syntax_error(tok);
			break; 
	}

}
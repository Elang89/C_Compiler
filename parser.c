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
	match(BEGIN);
	statement_list();
	match(END);
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
	token tok = next_token();
	switch(tok)
	{
		case ID:
			// <statement> ::= <expression>;
			match(ID);
			match(ASSIGNOP);
			expression();
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
	// <id_list> ::= ID { , ID}
	match(ID);
	while(next_token() == COMMA)
	{
		match(COMMA);
		match(ID);
	}
}

void expression()
{
	expr_rec left_operand;
	expr_rec right_operand;
	op_rec op;
	/*
	*	<expression> ::= <primary>{<add op><primary>}
	*/
	
	primary();
	
	while(next_token() == PLUSOP || 
		next_token() == MINUSOP)
	{
		add_op();
		primary();
	}

}

void expr_list()
{
	// <expr_list> ::= <expression>{ , <expression> }
	expression();
	while(next_token() == COMMA)
	{
		match(COMMA);
		expression();
	}
}

void add_op(op_rec *result)
{
	token tok = next_token();
	// <addop> ::= PLUSOP | MINUSOP 
	if(tok == PLUSOP || tok == MINUSOP)
	{
		match(tok);
	}
	else
	{
		printf("addop error");
		syntax_error(tok);
	}
}

void primary()
{
	token tok = next_token();

	switch(tok)
	{
		case LPAREN:
			// <primary>(<expression>)
			match(LPAREN);
			expression();
			match(RPAREN);
			break;
		case ID:
			//<primary> ::= ID
			match(ID);
			break;
		case INTLITERAL:
			// <primary> ::= INTLITERAL
			match(INTLITERAL);
			break;
		default:
			printf("primary error \n");
			syntax_error(tok);
			break; 
	}
}
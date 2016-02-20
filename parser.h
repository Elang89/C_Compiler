#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "global_functions.h"

void system_goal(void)  // We must match a token sequence generate by program followed bt SCANOF
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

// va buscando el siguiente token y si hay statements opcionales
// si es termianl se pone el First(A) y si es no terminal
// se nonterminal se compila en First(B)

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
void statement(void)
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
			brea;
		case READ:
			// <Statement> ::= READ(<id list>);
			match(READ);
			match(LPAREN);
			id_list();
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
			syntax_error(tok);
			break;
	}

}
#endif
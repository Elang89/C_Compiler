#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "parser_additional_functions.h"

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

void program()
{
	/* <program> ::= BEGIN <statement list> END*/
	match(BEGIN);
	statement_list();
	match(END);
}

void system_goal()  // We must match a token sequence generate by program followed bt SCANOF
{
	/* <system goal> ::= <program> SCANEOF */
	program();
	match(SCANEOF); 
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
void add_op()
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

void expression()
{
	token t;
	/*
	*	<expression> ::= <primary>{<add op><primary>}
	*/
	
	primary();
	
	for(t = next_token(); t == PLUSOP || t == MINUSOP; t = next_token())
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

// va buscando el siguiente token y si hay statements opcionales
// si es termianl se pone el First(A) y si es no terminal
// se nonterminal se compila en First(B)

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

#endif
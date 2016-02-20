#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#define true 1
#define false (!true)
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "global_functions.h"
#include <stdbool.h>

// implementar
bool match(token tos)
{
	return true;
}
token next_token(){
	return;
}

void primary(void)
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
			printf("syntax_error \n");
			//syntax_error(tok);
			break; 
	}
}

void program(void)
{
	/* <program> ::= BEGIN <statement list> END*/
	match(BEGIN);
	statement_list();
	match(END);
}

void system_goal(void)  // We must match a token sequence generate by program followed bt SCANOF
{
	/* <system goal> ::= <program> SCANEOF */
	program();
	match(SCANEOF); 
}
void id_list(void)
{
	// <id_list> ::= ID { , ID}
	match(ID);
	while(next_token() == COMMA)
	{
		match(COMMA);
		match(ID);
	}
}
void add_op(void)
{
	token tok = next_token();
	// <addop> ::= PLUSOP | MINUSOP 
	if(tok == PLUSOP || tok == MINUSOP)
	{
		match(tok);
	}
	else
	{
		printf("syntax_error \n");
		//syntax_error(tok);
	}
}

void expression(void)
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

void expr_list(void)
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

void statement(void)
{
	token tok_2 = next_token();
	switch(tok_2)
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
			printf("syntax_error\n");
			//syntax_error(tok);
			break;
	}
}


void statement_list(void)
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
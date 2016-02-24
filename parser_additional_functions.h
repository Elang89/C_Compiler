#ifndef PARSER_ADDITIONAL_FUNCTIONS_H_INCLUDED
#define PARSER_ADDITIONAL_FUNCTIONS_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"
#include "token_types.h"


int next_tok_flag; 

void syntax_error(token tok)
{
	switch(tok)
	{
		case BEGIN: 
			imprima_error();
			//printf("BEGIN expected \n");
			break;
		case READ:
			imprima_error();
			//printf("READ expected \n");
			break;
		case WRITE: 
			imprima_error();
			//printf("WRITE expected\n");
			break;
		case END:
			imprima_error();
			//printf("END expected \n");
			break;
		case LPAREN:
			imprima_error();
			//printf("LPAREN expected \n");
			break;
		case RPAREN:
			imprima_error();
			//printf("RPAREN expected \n");
			break;
		case INTLITERAL:
			imprima_error();
			//printf("INTLITERAL expected \n");
			break;
		case SEMICOLON:
			imprima_error();
			//printf("SEMICOLON expected \n");
			break;
		case ASSIGNOP:
			imprima_error();
			//printf("ASSIGNOP expected \n");
			break;
		case PLUSOP:
			imprima_error();
			//printf("PLUSOP expected \n");
			break;
		case MINUSOP:
			imprima_error();
			//printf("MINUSOP expected \n");
			break;
		case SCANEOF: 
			imprima_error();
			//printf("SCANEOF expected \n");
			break;
		case ID:
			imprima_error();
			//printf("Literal expected\n");
			break;
	}
	exit(0);
}
void imprima_error()
{
	printf("Syntax Error in line %d\n", file_line );
}
token next_token()
{
	return current_token;
}

void match(token tok)
{
	print_token(current_token);
	if(current_token == NULL) 
	{
		current_token = scanner();
	}

	if(tok == BEGIN)
	{
		current_token = scanner();
	}
	else if(tok == current_token)
	{
		current_token = scanner();
	}
	else
	{
		printf("match error \n");
		syntax_error(tok);
	}
}

#endif 
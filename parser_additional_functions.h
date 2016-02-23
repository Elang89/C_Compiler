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
			printf("Error BEGIN \n");
			break;
		case READ:
			printf("Error READ \n");
			break;
		case WRITE: 
			printf("Error WRITE \n");
			break;
		case END:
			printf("Error END \n");
			break;
		case LPAREN:
			printf("Error LPAREN \n");
			break;
		case RPAREN:
			printf("Error RPAREN \n");
			break;
		case INTLITERAL:
			printf("Error INTLITERAL \n");
			break;
		case SEMICOLON:
			printf("Error SEMICOLON \n");
			break;
		case ASSIGNOP:
			printf("Error ASSIGNOP \n");
			break;
		case PLUSOP:
			printf("Error PLUSOP \n");
			break;
		case MINUSOP:
			printf("Error MINUSOP \n");
			break;
		case SCANEOF: 
			printf("Error SCANEOF \n");
			break;
		case ID:
			printf("Error ID \n");
			break;
	}
	exit(0);
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
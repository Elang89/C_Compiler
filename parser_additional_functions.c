#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "parser_additional_functions.h"
#include "scanner.h"
#include "token_types.h"

int next_tok_flag; 

void syntax_error(token tok)
{
	switch(tok)
	{
		case BEGIN: 
			print_error();
			//printf("BEGIN expected \n");
			break;
		case READ:
			print_error();
			//printf("READ expected \n");
			break;
		case WRITE: 
			print_error();
			//printf("WRITE expected\n");
			break;
		case END:
			print_error();
			//printf("END expected \n");
			break;
		case LPAREN:
			print_error();
			//printf("LPAREN expected \n");
			break;
		case RPAREN:
			print_error();
			//printf("RPAREN expected \n");
			break;
		case INTLITERAL:
			print_error();
			//printf("INTLITERAL expected \n");
			break;
		case SEMICOLON:
			print_error();
			//printf("SEMICOLON expected \n");
			break;
		case ASSIGNOP:
			print_error();
			//printf("ASSIGNOP expected \n");
			break;
		case PLUSOP:
			print_error();
			//printf("PLUSOP expected \n");
			break;
		case MINUSOP:
			print_error();
			//printf("MINUSOP expected \n");
			break;
		case SCANEOF: 
			print_error();
			//printf("SCANEOF expected \n");
			break;
		case ID:
			print_error();
			//printf("Literal expected\n");
			break;
	}
	exit(0);
}
void print_error()
{
	printf("Syntax Error in line %d\n", (file_line + 1));
}
token next_token()
{
	return current_token;
}

void match(token tok)
{
	strcpy(current_token_buffer, token_buffer);
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

token call_scanner()
{
	token tok = scanner();
	if(current_token_buffer == INTLITERAL)
	{
		current_token = INTLITERAL;
	}
	else 
	{
		current_token = ID;
	}

	return tok;
}

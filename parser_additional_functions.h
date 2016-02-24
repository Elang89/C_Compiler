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
			printf("Syntax Error in line %d \n", file_line);
			//printf("BEGIN expected \n");
			break;
		case READ:
			printf("Syntax Error in line %d \n", file_line);
			//printf("READ expected \n");
			break;
		case WRITE: 
			printf("Syntax Error in line %d \n", file_line);
			//printf("WRITE expected\n");
			break;
		case END:
			printf("Syntax Error in line %d \n", file_line);
			//printf("END expected \n");
			break;
		case LPAREN:
			printf("Syntax Error in line %d \n", file_line);
			//printf("LPAREN expected \n");
			break;
		case RPAREN:
			printf("Syntax Error in line %d \n", file_line);
			//printf("RPAREN expected \n");
			break;
		case INTLITERAL:
			printf("Syntax Error in line %d \n", file_line);
			//printf("INTLITERAL expected \n");
			break;
		case SEMICOLON:
			printf("Syntax Error in line %d \n", file_line);
			//printf("SEMICOLON expected \n");
			break;
		case ASSIGNOP:
			printf("Syntax Error in line %d \n", file_line);
			//printf("ASSIGNOP expected \n");
			break;
		case PLUSOP:
			printf("Syntax Error in line %d \n", file_line);
			//printf("PLUSOP expected \n");
			break;
		case MINUSOP:
			printf("Syntax Error in line %d \n", file_line);
			//printf("MINUSOP expected \n");
			break;
		case SCANEOF: 
			printf("Syntax Error in line %d \n", file_line);
			//printf("SCANEOF expected \n");
			break;
		case ID:
			printf("Syntax Error in line %d \n", file_line);
			//printf("Literal expected\n");
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
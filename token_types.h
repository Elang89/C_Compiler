#ifndef TOKEN_TYPES_H_INCLUDED
#define TOKEN_TYPES_H_INCLUDED
#include <stdbool.h>

typedef enum token_types{                 
	BEGIN, END, READ, WRITE, ID,
	INTLITERAL, LPAREN, RPAREN,
	SEMICOLON, COMMA, ASSIGNOP,
	PLUSOP, MINUSOP, SCANEOF
} token;

FILE * file;
char token_buffer[128];
int file_line = 0;
token current_token;

void print_token(token tok)
{
	switch(tok)
	{
		case BEGIN: 
			printf("BEGIN \n");
			break;
		case READ:
			printf("READ \n");
			break;
		case WRITE: 
			printf("WRITE \n");
			break;
		case END:
			printf("END \n");
			break;
		case LPAREN:
			printf("LPAREN \n");
			break;
		case RPAREN:
			printf("RPAREN \n");
			break;
		case INTLITERAL:
			printf("INTLITERAL \n");
			break;
		case SEMICOLON:
			printf("SEMICOLON \n");
			break;
		case ASSIGNOP:
			printf("ASSIGNOP \n");
			break;
		case PLUSOP:
			printf("PLUSOP \n");
			break;
		case MINUSOP:
			printf("MINUSOP \n");
			break;
		case SCANEOF: 
			printf("SCANEOF \n");
			break;
		case ID:
			printf("ID \n");
			break;
	}
}

#endif
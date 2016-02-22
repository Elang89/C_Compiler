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

#endif
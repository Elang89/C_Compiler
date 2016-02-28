#ifndef TOKEN_TYPES_H_INCLUDED
#define TOKEN_TYPES_H_INCLUDED
#include <stdio.h>

typedef enum token_types{                 
	BEGIN, END, READ, WRITE, ID,
	INTLITERAL, LPAREN, RPAREN,
	SEMICOLON, COMMA, ASSIGNOP,
	PLUSOP, MINUSOP, SCANEOF
} token;

FILE * file;
char * file_name;
char * new_file_name;
char * output_file_name;
char token_buffer[128];
int file_line;
token current_token;

#endif
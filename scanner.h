#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "global_functions.h"

token scanner(FILE * file)
{
	int input_character;
	int temp_character;

	clear_buffer();
	if(feof(file))
	{
		return SCANEOF; // token que indica que ya terminó de leer.
	}

	input_character = fgetc(file);

	if(isspace(input_character))
	{
		return; // no retorna nada cuando es espacio en blanco. 
	}
	else if (isalpha(input_character))
	{
		buffer_char(input_character);
		for(temp_character = fgetc(file); isalnum(temp_character) || 
			temp_character == '_'; temp_character = fgetc(file))
		{
			buffer_char(temp_character);
		}
		ungetc(temp_character, file);
		return check_reserved();
	} 
	else if (isdigit(input_character))
	{
		buffer_char(input_character);
		for (temp_character = fgetc(file); isdigit(temp_character);
			temp_character = fgetc(file))
		{
			buffer_char(temp_character);
		}
		ungetc(temp_character, file);
		printf("INTLITERAL \n");
		return INTLITERAL;
	} 
	else if (input_character == '(')
	{
		printf("RPAREN \n");
		return RPAREN;
	} 
	else if (input_character == ')')
	{
		printf("LPAREN \n");
		return LPAREN;
	}
	else if (input_character == ';')
	{
		printf("SEMICOLON \n");
		return SEMICOLON;
	}
	else if (input_character == ',')
	{
		printf("COMMA \n");
		return COMMA;
	}
	else if (input_character == '+')
	{
		printf("PLUSOP \n");
		return PLUSOP;
	}
	else if (input_character == ':')
	{
		temp_character = fgetc(file);
		if (temp_character = '=')
		{
			printf("ASSIGNOP \n");
			return ASSIGNOP;
		}
		else
		{
			ungetc(temp_character, file);
			printf("error \n"); // hacer lexical error
		}
	}
	else if (input_character == '-')
	{
		temp_character = fgetc(file);
		if(temp_character == '-')
		{
			do
			{
				input_character = fgetc(file);
			} while (input_character != "\n");
		}
		else 
		{
			ungetc(temp_character, file);
			printf("MINUSOP \n");
			return MINUSOP;
		}
	}
	else if (!(input_character != EOF))
	{
		printf("%c\n",input_character);
		printf("error \n");
		return;
	}
}

#endif
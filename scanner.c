#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "scanner.h"
#include "scanner_additional_functions.h"
#include "token_types.h"

token scanner()
{
	int input_character;
	int temp_character;

	clear_buffer();

	while((input_character = fgetc(file)) != EOF)
	{
		
		if(input_character == '\n')
		{
			file_line++;// esta variable determina la línea de código donde está el error
		}

		if(isspace(input_character))
		{
			continue; // no retorna nada cuando es espacio en blanco. 
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
			//printf("INTLITERAL \n");
			return INTLITERAL;
		} 
		else if (input_character == '(')
		{
			//printf("RPAREN \n");
			return LPAREN;
		} 
		else if (input_character == ')')
		{
			//printf("LPAREN \n");
			return RPAREN;
		}
		else if (input_character == ';')
		{
			//printf("SEMICOLON \n");
			return SEMICOLON;
		}
		else if (input_character == ',')
		{
			//printf("COMMA \n");
			return COMMA;
		}
		else if (input_character == '+')
		{
			//printf("PLUSOP \n");
			return PLUSOP;
		}
		else if (input_character == ':')
		{
			temp_character = fgetc(file);
			if (temp_character == '=')
			{
			//	printf("ASSIGNOP \n");
				return ASSIGNOP;
			}
			else
			{
				ungetc(temp_character, file);
				lexical_error(input_character);
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
				} while (input_character != '\n');
			}
			else 
			{
				ungetc(temp_character, file);
		//		printf("MINUSOP \n");
				return MINUSOP;
			}
		}
		else 
		{
			lexical_error(input_character);
		}
	}

	if(feof(file))
	{
		//printf("SCANEOF \n");
		return SCANEOF; // token que indica que ya terminó de leer.
	}
}
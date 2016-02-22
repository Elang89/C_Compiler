#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "token_types.h"
#ifndef SCANNER_ADDITIONAL_FUNCTIONS_H_INCLUDED
#define SCANNER_ADDITIONAL_FUNCTIONS_H_INCLUDED

void buffer_char(int temp_char) 
{
	int i;
	for(i = 0; i < sizeof(token_buffer); i++)
	{
		if(token_buffer[i] == 0)
		{
			token_buffer[i] = temp_char;
			break;
		}
	}
}

void clear_buffer()
{
	int i;
	for(i = 0; i < sizeof(token_buffer); i++)
	{
		token_buffer[i] = 0;
	}
}

token check_reserved()
{
	if(strcmp("begin", token_buffer) == 0)
	{
		printf("begin \n");
		return BEGIN;
	}
	else if (strcmp("end", token_buffer) == 0)
	{
		printf("end \n");
		return END;
	}
	else if (strcmp("read", token_buffer) == 0)
	{
		printf("READ \n");
		return READ;
	}
	else if (strcmp("write", token_buffer) == 0)
	{
		printf("WRITE \n");
		return WRITE;
	}
	else 
	{
		printf("ID \n");
		return ID; // Retorna variables ya que es un identificador.
	}
} 

void lexical_error(int character)
{
	printf("Error '%c' in line %d. \n", character, file_line);
}
#endif
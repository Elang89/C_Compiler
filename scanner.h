#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "global_functions.h"

token scanner(char * file_path)
{
	FILE * file;
	int input_character;
	int temp_character;
	file = fopen(file_path, "r");


//	if(feof(file))
//	{
//		printf("End of File"); // Debe retornar SCANEOF
//	}

	while((input_character = fgetc(file)) != EOF)
	{
		printf("%c", input_character);
		if (isspace(input_character))
		{
			continue;
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

	}
	return BEGIN;	

}

#endif
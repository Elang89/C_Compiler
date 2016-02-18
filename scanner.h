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

	if(feof(file))
	{
		printf("End of File");
	}

	while((input_character = fgetc(file)) != EOF)
	{
		if (isspace(input_character))
		{
			continue;
		}
		else if (isalpha(input_character))
		{
			for(temp_character = fgetc(file); isalnum(temp_character) || 
				temp_character == '_'; temp_character = fgetc(file))
			{
				
			}
			ungetc(temp_character, file);
			return check_reserved();
		} 

	}	

}

#endif
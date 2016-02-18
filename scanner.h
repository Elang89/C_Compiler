#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "global_functions.h"

token scanner()
{
	int input_character;
	int temp_character;

	clear_buffer();
	if(feof(stdin))
	{
		return SCANEOF;
	}

	while((input_character = getchar()) != EOF)
	{
		if (isspace(input_character))
		{
			continue;
		}
		else if (isalpha(input_character))
		{
			buffer_char(input_character);
			for(temp_character = getchar(); isalnum(temp_character) || 
				temp_character == '_'; temp_character = getchar())
			{
				buffer_char(temp_character);
			}
			ungetc(temp_character, stdin);
			return check_reserved();
		} 

	}
	return BEGIN;
}

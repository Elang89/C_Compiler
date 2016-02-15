#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void scanner(char * file_path)
{
	FILE * file;
	int input_character, c;
	file = fopen(file_path, "r");

	while((input_character = fgetc(file)) != EOF)
	{
		if (isspace(input_character))
		{
			continue;

		}
		else if (isalpha(input_character))
		{
			buffer_char(input_character);
			for(c = getchar(); isalmun(c) || c == '_'; c = getchar())
			{
				buffer_char(c);
			}
			ungetc(c, stdin);
			return check_reserved();
		} 

	}	

}

#endif
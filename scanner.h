#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void scanner(char * file_path)
{
	FILE * file;
	char input_character;
	file = fopen(file_path, "r");

	while((input_character = fgetc(file)) != EOF)
	{
		if(input_character == 'b')
		{
			putchar(input_character + "\n");
		}
	}	

}

#endif
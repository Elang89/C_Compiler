#include <unistd.h>		//library to work with unix file system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main(int argc, char *argv[])
{
	FILE * file;
	char * file_name;
	int c;

	int i = 0;

	file_name = argv[1];
	printf(validate_file_path(file_name) ? "File found \n" : "File not found \n");
	file = fopen(file_name, "r");

	while((c = fgetc(file)) != EOF)
	{
		ungetc(c, file);
		scanner(file);
	}
	
	fclose(file);
	return 0;
}

int validate_file_path(const char* path)
{
	if(access(path, F_OK)!= -1)
	{
		return 1;
	}
	return 0;
}
#include <unistd.h>		//library to work with unix file system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "parser.h"
#include "token_types.h"


int main(int argc, char *argv[])
{
	char * file_name;
	file_name = argv[1];
	printf(validate_file_path(file_name) ? "File found \n" : "File not found \n");
	file = fopen(file_name, "r");
	system_goal();
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
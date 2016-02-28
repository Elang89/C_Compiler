#include <unistd.h>		//library to work with unix file system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "parser.h"
#include "semantic_code.h"
#include "token_types.h"


int main(int argc, char *argv[])
{
	file_name = argv[1];
	
	new_file_name = argv[1];
	
	file_line = 0;
	
	list_size = 0;

	//------------------------------------------------------------------------------
	
	printf(validate_file_path(file_name) ? "File found \n" : "File not found \n");
	
	file = fopen(file_name, "r");
	
	strcpy(new_file_name, file_name);
	
	(new_file_name[strlen(file_name)-4] = 0);
	
	strcat(new_file_name,".mips");
	
	//-------------------------------------------------------------------------------
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

 
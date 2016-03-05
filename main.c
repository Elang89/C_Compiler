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
	
	if(validate_file_path(file_name)) // Check the file path.
	{
		printf("File found \n");
	
		file = fopen(file_name, "r"); // Open the file with read permissions.
	
		strcpy(new_file_name, file_name);
	
		new_file_name[strlen(new_file_name)-6] = 0;
	
		strcat(new_file_name,".asm");
	
	//-------------------------------------------------------------------------------
		system_goal(); // Calls the parser.
	
		fclose(file);
	}
	else
	{
		printf("File not found, please try again \n");
	}
	
	
	return 0;
}

int validate_file_path(const char* path) 

// This function check the input url, if it is a valid file the function will return 1
{
	if(access(path, F_OK)!= -1)
	{
		return 1;
	}
	return 0;
}

 
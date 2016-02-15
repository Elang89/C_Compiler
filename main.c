#include <unistd.h>		//library to work with unix file system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main()
{

	int b_file_path;
	char input_character;
	char file_path[1024];
	printf("Specify a valid file path to compile file: ");
	
	fgets(file_path, sizeof(file_path), stdin);
	file_path[ strcspn(file_path, "\n") ] = '\0';
	b_file_path = validate_file_path(file_path);

	while(b_file_path == 0)
	{
		printf("Invalid file path, please specify a valid file path: ");
		fgets(file_path, sizeof(file_path), stdin);
		file_path[ strcspn(file_path, "\n") ] = '\0';
		b_file_path = validate_file_path(file_path);
	}

	printf("%s", scanner(file_path));
 

	printf("File found, generating output... \n");
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
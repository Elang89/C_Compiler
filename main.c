#include <unistd.h>		//library to work with unix file system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main()
{

	char input_character;
	char word[32];
	printf("Specify a word: ");
	
	fgets(word, sizeof(word), stdin);
	word[ strcspn(word, "\n") ] = '\0';
	input_character = getchar();

	if(isspace(input_character))
	{
		printf("%c", input_character);
	}
	else
	{
		printf("no word");
	}

	

	/*while(b_file_path == 0)
	{
		printf("Invalid file path, please specify a valid file path: ");
		fgets(file_path, sizeof(file_path), stdin);
		file_path[ strcspn(file_path, "\n") ] = '\0';
		b_file_path = validate_file_path(file_path);
	}*/
	return 0;
}

/*int validate_file_path(const char* path)
{
	if(access(path, F_OK)!= -1)
	{
		return 1;
	}
	return 0;
	
}*/
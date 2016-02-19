#ifndef RESERVED_WORDS_H_INCLUDED
#define RESERVED_WORDS_H_INCLUDED

typedef enum token_types{                 
	BEGIN, END, READ, WRITE, ID,
	INTLITERAL, LPAREN, RPAREN,
	SEMICOLON, COMMA, ASSIGNOP,
	PLUSOP, MINUSOP, SCANEOF
} token;

char token_buffer[128];
unsigned long file_position = 0;

void buffer_char(int temp_char) 
{
	int i;
	for(i = 0; i < sizeof(token_buffer); i++)
	{
		if(token_buffer[i] == 0)
		{
			token_buffer[i] = temp_char;
			break;
		}
	}
}

void clear_buffer()
{
	int i;
	for(i = 0; i < sizeof(token_buffer); i++)
	{
		token_buffer[i] = 0;
	}
}

token check_reserved()
{
	if(strcmp("begin", token_buffer) == 0)
	{
		printf("begin \n");
		return BEGIN;
	}
	else if (strcmp("end", token_buffer) == 0)
	{
		printf("end \n");
		return END;
	}
	else if (strcmp("read", token_buffer) == 0)
	{
		return READ;
	}
	else if (strcmp("write", token_buffer) == 0)
	{
		return WRITE;
	}
	else 
	{
		printf("ID \n");
		return ID;
	}
} 
#endif
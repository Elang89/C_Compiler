#ifndef RESERVED_WORDS_H_INCLUDED
#define RESERVED_WORDS_H_INCLUDED

typedef enum token_types{                 
	BEGIN, END, READ, WRITE, ID,
	INTLITERAL, LPAREN, RPAREN,
	SEMICOLON, COMMA, ASSIGNOP,
	PLUSOP, MINUSOP, SCANEOF
} token;

char token_buffer[128];

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

int str_compare(char string_compare[128])
{
	if (strcmp(string_compare, token_buffer) == 0)
	{
		return 0;
	}
	return -1;
}

token check_reserved()
{
	
} 


#endif
#include <stdio.h>
#include <ctype.h>

int in_char, c;

while((in_char = getchar()) != EOF) 
{
	if (isspace(in_char))
	{
		continue;          /*DO NOTHING*/
	} 
	else if (isalpha(in_char))
	{
		/* code to recognize identifiers goes here */
	}
	else if (isdigit(in_char))
	{
		/* code to recognize ints literal goes here*/
	}
	else if (in_char == '(')
	{
		return LPAREN;
	}
	else if (in_char == ')')
	{
		return RPAREN;
	}
	else if (in_char == ';')
	{
		return SEMICOLON;
	}
	else if (in_char == ',')
	{
		return COMMA;
	}
	else if (in_char == '+')
	{
		return PLUSOP;
	}
	else if (in_char == ':')
	{
		c = getchar();
		if (c == '=')
		{
			return ASSIGNOP;
		}
		else
		{
			ungetc(c, stdin);
			lexical_error(in_char);
		}
	}
	else if (in_char == '-')
	{
		/* Looking for --, comment start */
		c = getchar();
		if (c == '-')
		{
			while((in_char = getchar()) != '\n');
		}
		else
		{
			ungetc(c, stdin);
			return MINUSOP;
		}
	}
	else
	{
		lexical_error(in_char);
	}

}












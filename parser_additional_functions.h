#ifndef PARSER_ADDITIONAL_FUNCTIONS_H
#define PARSER_ADDITIONAL_FUNCTIONS_H
#include "token_types.h"

int next_tok_flag; 

void syntax_error(token tok);
void imprima_error();
token next_token();
void match(token tok);

#endif 
#ifndef SCANNER_ADDITIONAL_FUNCTIONS_H
#define SCANNER_ADDITIONAL_FUNCTIONS_H
#include "token_types.h"

void buffer_char(int temp_char);

void clear_buffer();

token check_reserved();

void lexical_error(int character);

#endif
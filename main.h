#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_unsigned(va_list arg);
int print_oct(va_list arg);
int print_hex(va_list arg);
int print_HEX(va_list arg);
int print_STR (va_list arg);
int print_unsignedToBinary(va_list arg);
int print_oct(va_list arg);
int print_char(va_list arg);
int print_str(va_list arg);
int print_int(va_list arg);



/**
 * struct structIdentifier - struct definition of printTypeStruct
 * @identifier: type
 * @printer: function to print
 *
 */

typedef struct structIdentifier
{
	char *identifier;
	int (*printer)(va_list);

} structIdentifier;

#endif /* MAIN_H */


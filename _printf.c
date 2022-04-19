#include "main.h"
#include <stdlib.h>
#include <stdarg.h>


/**
 * printIdentifiers - prints special characters
 * @next: character after the %
 * @arg: argument for the identifier
 * Return: args printed
 * (expect the nul character used to end strings)
 *
 */

int printIdentifiers ( char next , va_list arg)
{
	int indexFunc; 

	structIdentifier Funcs [] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"b", print_unsignedToBinary},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_STR},
		{NULL, NULL}
	};

	for (indexFunc = 0; Funcs[indexFunc].identifier != NULL ; indexFunc++)
	{
		if(Funcs[indexFunc].identifier[0] == next)
			return Funcs[indexFunc].printer(arg);
	}
	return (0);
}



/**
 * _printf - produces output according to a format
 * @*format - pointer to character string
 * Return :  number of characters printed excluding the nul character
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int printedChar = 0, printedIdentifier = 0 ;

	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);
	
	for ( i = 0; format[i] != '\0'; i++)
        {
		if ( format[i] != '%' )
		{
			_putchar(format[i]);
			printedChar++;
			continue;
		}
		
		if (format[i] == '%')
		{
			_putchar('%');
			printedChar++;
			continue;
		}

		if (format[i + 1] == '\0')
			return (-1);


	printedIdentifier = printIdentifiers ( format[i + 1] , args);

	if (printedIdentifier == -1 || printedIdentifier != 0)
		i++;
	if (printedIdentifier == 0)
		printedChar += printedIdentifier;
	if(printedIdentifier == 0)
	{
		_putchar('%');
		printedChar++;
	}
     }
	va_end(args);
	return (printedChar);
}


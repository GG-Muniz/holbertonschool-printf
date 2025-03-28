#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - formats output; custom printf function with variadic arguments.
 * @format: a character string containing format specifiers.
 * Return: the number of characters printed, -1 on error.
 */
int _printf(const char *format, ...)
{
	/* Lets declare the variables and the variadic list of arguments.*/
	va_list args;
	unsigned int i = 0;
	char *str;
	char *separator = "";

	if (format == NULL)
		return (-1);

	/*Initializing the variadic arguments to handle their formatting.*/
	va_start(args, format);

	/*Switch cases in order to move gracefully between formats.*/
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", separator, va_arg(args, int));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "No string presented";
				printf("%s%s", separator, str);
				break;
			case '%':
				printf("%s%%", separator);
				break;
			default:
				i++;
				continue;
		}
		separator = ", ";
		i++;
	}
	printf("\n"); /* New line after each case iteration.*/
	va_end(args); /*Ending variadic arguments.*/
	return (0); /*Function is not void - returning 0.*/
}

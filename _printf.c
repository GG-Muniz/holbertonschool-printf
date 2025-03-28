#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - print function that formats specific characters to output.
 * @format: array of character to be iterated and formated.
 * Return: formated characters.
*/

int _printf(const char *format, ...)
{
	/* Initialize variadic list of arguments and helper variables. */
	va_list args;
	int i = 0, count = 0;
	char c;

	/* If there is no datat to format return -1.*/
	if (format == NULL)
		return (-1);
	/* Commence variadic arguments.*/
	va_start(args, format);
	/* Format characters 'c','s','%'.*/
	while (format && format[i])
	{
		if (format[i] != '%') /* Logic explains iteration of characters. */
		{
			write(1, &format[i++], 1);
			count++;
			continue;
		}
		if (format[++i] == '\0') /* When iteration reaches null byte return -1. */
			return (-1);
		if (format[i] == 'c') /*Logic formats 'c'. */
			c = va_arg(args, int), write(1, &c, 1), count++;
		else if (format[i] == 's') /* Formating 's'. */
			count += handle_string(va_arg(args, char *));
		else if (format[i] == '%') /*Formatng '%'. */
			write(1, "%", 1), count++;
		else
			write(1, &format[--i], 1), count++;
		i++;
	}
	va_end(args);/* End varaidic list of arguments.*/
	return (count); /* Return count which hold the formated characters.*/
}

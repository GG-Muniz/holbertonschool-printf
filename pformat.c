#include "main.h"
#include <stddef.h>
#include <stdvar.h>
#include <stdio.h>
#include <string.h>
#include <stdout.h>
/**
 *
 *
 *
 *
 *
*/
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i;
	char *str;
	char *separator = "";

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", separator, va_arg(args, int));
				break;
			case 's':
				str = va_args(args, char *);
				if (str == NULL)
					str = "No string presented";
				printf("%s%s", separator, va_args(args, str));
				break;
			case '%':
				printf("%s%d", separator, va_args(args, int));
			default:
				i++;
				continue;
		}
		separator = ", ";
		i++;
	}
	printf("\n");
	va_end(args);
}

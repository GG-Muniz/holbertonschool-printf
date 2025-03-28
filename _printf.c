#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - formats output; custom printf function with variadic arguments.
 * @format: a character string containing format specifiers.
 * Return: the number of characters printed, -1 on error.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;
    char *str;
    char c;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] != '%')
        {
            /* Regular character - write it directly */
            write(1, &format[i], 1);
            count++;
        }
        else
        {
            /* Format specifier - check the next character */
            i++;
            switch (format[i])
            {
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        count++;
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    /* Unrecognized format - print % and the character */
                    write(1, "%", 1);
                    write(1, &format[i], 1);
                    count += 2;
                    break;
            }
        }
        i++;
    }
    va_end(args);
    return (count);
}

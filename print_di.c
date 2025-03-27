#include <stdarg.h>
#include <unistd.h>

/**
 * print_number - Prints an integer recursively
 * @n: Number to print
 * @count: Pointer to count of printed characters
 */
void print_number(int n, int *count)
{
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		print_number(num / 10, count);

	num = num % 10 + '0';
	write(1, &num, 1);
	(*count)++;
}

/**
 * handle_format - Handles format specifiers
 * @format: Format string
 * @i: Current index
 * @args: Argument list
 * @count: Pointer to count of printed characters
 *
 * Return: Updated index
 */
int handle_format(const char *format, int i, va_list args, int *count)
{
	char c, *s;
	int n;

	switch (format[i])
	{
	case 'c':
		c = va_arg(args, int);
		write(1, &c, 1);
		(*count)++;
		break;
	case 's':
		s = va_arg(args, char *);
		if (!


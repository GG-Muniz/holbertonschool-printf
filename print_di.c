#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_number - Prints an integer recursively
 * @n: Number to print
 * @count: Pointer to count of printed characters
 */
int print_number(int n)
{
	unsigned int num;
	int divisor = 1;
	int len = 0;
	char digit;

	/* handling negative number */
	if (n < 0)
	{
		write(1, "-", 1);
		len++;
		num = -n;
	}
	else
	{
		num = n;
	}

	while (num / divisor >= 10)
		divisor *= 10;

	/* Print each digit */
	while (divisor > 0)
	{
	digit = '0' + (num / divisor);
	write(1, &digit, 1);
	len++;
	num %= divisor;
	divisor /= 10;
	}

	return (len);
}

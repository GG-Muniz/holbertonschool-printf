#include <stdarg.h>
#include <unistd.h>
#include "main.h"

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


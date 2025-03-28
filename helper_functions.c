#include "main.h"
#include <unistd.h>

/**
 * handle_string - Helper function to print a string
 * @str: String to print
 * Return: Number of characters printed
 */
int handle_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

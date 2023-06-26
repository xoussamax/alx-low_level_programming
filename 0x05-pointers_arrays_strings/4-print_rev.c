#include "main.h"
/**
 * print_rev - Prints a string in reverse followed by a new line.
 * @s: string
 * Return: 0
 */
void print_rev(char *s)
{
	int length = 0;
	int i;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	s--;
	for (i = length; o > 0; i--)
	{
		_putchar(*s);
		s--;
	}

	_putchar('\n');
}

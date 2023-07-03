#include "main.h"
#include <stdio.h>
/**
 * _memset - Fills memory with a constant byte.
 * @s: Pointer to the memory area.
 * @b: Constant byte to be set.
 * @n: Number of bytes to be filled.
 *
 * Return: Pointer to the memory area @s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[5];
    char *result;

    result = _memset(buffer, 'A', sizeof(buffer));

    for (unsigned int i = 0; i < sizeof(buffer); i++)
        putchar(buffer[i]);

    return (0);
}

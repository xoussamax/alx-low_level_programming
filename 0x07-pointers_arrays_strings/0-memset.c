#include "main.h"
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
int main(void)
{
	char str[6] = "Hello";
	char *result = _memset(str, 'A', 5);

	printf("Result: %s\n", result);

	return (0);
}

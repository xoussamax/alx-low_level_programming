#include <stdio.h>
#include <stdlib.h>

/**
 * multiply - Multiplies two positive numbers.
 * @num1: The first number.
 * @num2: The second number.
 *
 * Return: The product of the two numbers.
 */
int multiply(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * is_positive_number - Checks if a string is a positive number.
 * @str: The string to check.
 *
 * Return: 1 if the string is a positive number, 0 otherwise.
 */
int is_positive_number(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success, 1 on incorrect input or non-digit inputs.
 */
int main(void)
{
	char num1_str[100], num2_str[100];
	int num1, num2;

	printf("Enter the first positive number: ");
	fgets(num1_str, sizeof(num1_str), stdin);
	num1_str[strcspn(num1_str, "\n")] = '\0'; /* Remove newline character */
	num1 = atoi(num1_str);

	printf("Enter the second positive number: ");
	fgets(num2_str, sizeof(num2_str), stdin);
	num2_str[strcspn(num2_str, "\n")] = '\0'; /* Remove newline character */
	num2 = atoi(num2_str);

	if (!is_positive_number(num1_str) || !is_positive_number(num2_str)
			|| num1 <= 0 || num2 <= 0)
	{
		printf("Error: Invalid input. Both numbers must be positive integers.\n");
		return (1);
	}

	int result = multiply(num1, num2);

	printf("The product of %d and %d is: %d\n", num1, num2, result);

	return (0);
}


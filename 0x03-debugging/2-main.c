#include <stdio.h>


/**
* main - prints the largest of 3 integers
* Return: 0
*/

int largest_number(int a, int b, int c)
{
int largest;
if (a >=  b && a >= c)
{
largest = a;
}
else if (b > a && b > c)
{
largest = b;
}
else
{
largest = c;
}
return (largest);
}

int main(void)
{
        int a, b, c;
        int largest;

        a = 972;
        b = -98;
        c = 0;


        printf("%d is the largest number\n", largest);

        return (0);
}

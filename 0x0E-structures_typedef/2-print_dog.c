#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints the details of a dog.
 * @d: A pointer to the struct dog to be printed.
 *
 * Description: This function prints the details of a dog,
 * including its name, age, and owner. If an element of the
 * dog is NULL, it prints (nil) instead.
 */
void print_dog(struct dog *d)
{
    if (d == NULL)
        return;

    printf("Name: %s\n", d->name ? d->name : "(nil)");
    printf("Age: %.1f\n", d->age);
    printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}


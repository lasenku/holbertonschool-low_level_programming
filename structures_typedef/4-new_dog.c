#include "dog.h"
#include <stdlib.h>

/**
 * str_len - computes the length of a string
 * @s: the string to measure
 *
 * Return: the length of the string
 */
int str_len(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * str_dup - duplicates a string into newly allocated memory
 * @s: the string to duplicate
 *
 * Return: a pointer to the duplicated string, or NULL on failure
 */
char *str_dup(char *s)
{
	char *dup;
	int len, i;

	len = str_len(s);
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = s[i];
	dup[len] = '\0';

	return (dup);
}

/**
 * new_dog - creates a new dog
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the name of the dog's owner
 *
 * Return: a pointer to the newly created dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	d->name = str_dup(name);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = str_dup(owner);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	d->age = age;

	return (d);
}

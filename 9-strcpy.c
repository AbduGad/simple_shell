#include "main.h"

/**
 * _strcpy - copies string poited to
 * @dest: destination string
 * @src: the source string
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

#include "main.h"

/**
 * _strcat - add strings
 * @dest: destination
 * @src: source
 * Return: * pointer
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);

}

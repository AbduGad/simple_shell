#include "main.h"

/**
 * _strlen - lenght of string
 * @s: string input
 * Return: length
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len += 1;
		s++;
	}
	return (len);
}

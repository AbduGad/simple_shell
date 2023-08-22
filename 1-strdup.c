#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,r.
 *@str: String to be copied
 *
 *Return: NULL in case of error, pointer to allocated space
 */
char *_strdup(char *str)
{
	char *cpy;
	int i;

	if (str == NULL)
		return (NULL);
	cpy = malloc(sizeof(char) * (_strlen(str) + 1));
	if (cpy == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		cpy[i] = str[i];
	}
	cpy[_strlen(str)] = '\0';
	return (cpy);
}

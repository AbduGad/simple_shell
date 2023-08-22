#include "main.h"

/**
* _strcmp - compare strings
* @s1: input
* @s2: input
* Return: integer
*/

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] || s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

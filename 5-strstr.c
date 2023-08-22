#include "main.h"

/**
 *_strstr - finds the first occurrence of string in a string
 *@hay: input
 *@needle: input
 *Return: pointer to the first letter when found
 */

char *_strstr(char *hay, char *needle)
{
	char *p = "NULL";
	int i, j = 0, b = 0;

	if (!*needle)
		return (p = hay);
	for (i = 0; hay[i] && needle[j]; i++)
	{
		if (hay[i] == needle[0])
		{
			b = 1;
			p = &hay[i];
		}
		if (hay[i] == needle[j])
			j++;
		else
		{
			b = 0;
			j = 0;
		}
	}
	if (b == 1)
		return (p);
	else
		return (0);
}

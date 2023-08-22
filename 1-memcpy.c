#include "main.h"

/**
 *_memcpy - copies n bytes of src to dest
 *@dest: destination
 *@src: source to copy from
 *@n: number of bytes to copy from source
 *Return: char
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

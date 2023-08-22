#include "main.h"
/**
 * print_integer - prints an int using recurrsion
 * @shellcounter: how many times the shell has run
 */
void print_integer(int shellcounter)
{
	char c;
	int counter;

	counter = shellcounter / 10; /*if it is 0 dont call it again*/
	if (counter > 0)
		print_integer(((shellcounter) / 10));
	c = ((shellcounter % 10) + '0');
	write(2, &c, 1);
}

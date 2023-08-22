#include "main.h"
/**
 * print_error - replicates the print of sh when encountering an error
 * @ShellRunCount: how many times the shell has run
 * @av: char *argv[] from main
 * @CmdTok: tokenised input line
 * @ExitStat: update staus
 */
void print_error(int ShellRunCount, char **av, char **CmdTok, int *ExitStat)
{
	if (CmdTok == NULL || CmdTok[0] == NULL)
	{
		*ExitStat = 0;
		return;
	}
	*ExitStat = 127;
	write(2, av[0], _strlen(av[0]));
	write(2, ": ", 2);
	print_integer(ShellRunCount);
	write(2, ": ", 2);
	write(2, CmdTok[0], _strlen(CmdTok[0]));
	write(2, ": not found\n", 12);
}

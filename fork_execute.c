#include "main.h"
#include <sys/wait.h>
/**
 * fork_execute - creates a fork and executes a process
 * @CmdTok: tokenised input line(split into array of srtings
 * ending with a null)
 * @EnvironVars: environment variable from main
 * @ExitStat: status to exit with
 */
void fork_execute(char **CmdTok, char **EnvironVars, int *ExitStat)
{
	pid_t child;

	/* *ExitStat = 0;*/
	child = fork();
	if (child == 0)
	{
		if (execve(CmdTok[0], CmdTok, EnvironVars) == -1)
			*ExitStat = 2;
		else
			*ExitStat = 0;
	}
	else if (child == -1)
	{
		write(1, "fork failed\n", 13);
	}
	else
		child = wait(0);
}

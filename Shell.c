#include "main.h"
/**
 * main - functions that runs the shell
 * @ac: argument counter
 * @av: agrument vector
 * @envs: environmental variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **envs)
{
	char *PATHcpy;
	char **CmdTok, **PathTok;
	int Tokindex, PathTokIndex, checkaccess_return, ShellRunCount, ExitStat;

	(void)ac;
	PATHcpy = NULL;
	PathTok = NULL;
	CmdTok = NULL;
	PathTokIndex = 0;
	ShellRunCount = 1;
	ExitStat = 0;
	PATHcpy = get_PATH(envs);
	signal(SIGINT, signal_handler);
	PathTok = make_token(PATHcpy, &PathTokIndex, ":");
	while (1)
	{
		Tokindex = 0;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);

		CmdTok = input_line(&Tokindex, PathTok, &PathTokIndex, &ExitStat, PATHcpy);
		checkaccess_return = check_access_update_token(CmdTok, PathTok, &ExitStat);
		if (!checkaccess_return)
			fork_execute(CmdTok, envs, &ExitStat);
		else /*if (commandtoken != NULL && tokenindex != 0)*/
			print_error(ShellRunCount, av, CmdTok, &ExitStat);
		ShellRunCount += 1;
		free_grid(CmdTok, Tokindex);
	}
	free_grid(PathTok, PathTokIndex);
	free(PATHcpy);
	return (0);
}

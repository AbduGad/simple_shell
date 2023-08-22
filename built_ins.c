#include "main.h"
/**
 * built_ins - function
 * @CmdTok: command token
 * @TokIndex: token index
 * @envs: environment
 * @ExitStat: exist status
 * Return: 1 or 0
 */
int built_ins(char **CmdTok, int TokIndex, char **envs, int *ExitStat)
{
	built_in commands[2] = {{"env", env_fun}};
	int i;

	if (!CmdTok || !CmdTok[0])
		return (1);
	if (CmdTok[1])
	{
		*ExitStat = 2;
		return (1);
	}
	for (i = 0; i < 1; i++)
	{
		if (!_strcmp(CmdTok[0], commands[i].command))
		{
			commands[i].function(envs);
			free_grid(CmdTok, TokIndex);
			return (0);
		}
	}
	return (1);
}

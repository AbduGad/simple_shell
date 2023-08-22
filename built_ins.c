#include "main.h"
/**
 * @brief 
 * 
 */
void built_ins(char *Tok0, char **envs, int *ExitStat)
{
	built_in commands[] = {{"env", env_fun}, NULL};
	int i;

	if (Tok0[1])
		*ExitStat = 2;
	for (i = 0; commands[i]; i++)
	{
		if (!_strcmp(Tok0, commands[i]))
			commands[i].function(envs);
	}
	
}
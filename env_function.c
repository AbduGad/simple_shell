#include "main.h"
/**
 * env_fun - function
 * @envs: enviroment
 */
void env_fun(char **envs)
{
	int row;

	for (row = 0; envs && envs[row]; row++)
	{
		write(1, envs[row], _strlen(envs[row]));
		write(1, "\n", 1);
	}
}

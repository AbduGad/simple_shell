#include "main.h"
/**
 * @brief 
 * 
 */
void env_fun(char **envs)
{
	int row, colomun;

	colomun = 0;
	for (row = 0; envs && envs[row];)
	{
		if (!env[row][colomun])
		{
			colomun = 0;
			row++;
		}
		else
		{
			write(1, env[row][colomun]);
			colomun++;
		}
	}
}
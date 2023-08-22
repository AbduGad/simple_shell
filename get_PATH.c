#include "main.h"
/**
 * get_PATH - function that outputs the environment var PATH
 * @envs: environment variables
 * Return: pointer to tokenised PATH
 */
char *get_PATH(char **envs)
{
	int envindex;
	char *lookingfor;
	char first5ofenv[5];
	char *envsclone;

	lookingfor = "PATH=";
	for (envindex = 0; envs && envs[envindex]; envindex++)/*PATH1=*/
	{
		_strncpy(first5ofenv, envs[envindex], 5);
		if (!_strcmp(first5ofenv, lookingfor))
		{
			if (_strlen(envs[envindex]) == 5)
			{
				envsclone = malloc(sizeof(char *));
				envsclone = NULL;
				return (envsclone);
			}
			envsclone = _strdup(envs[envindex] + 5);
			return (envsclone);
		}
	}
	return (NULL);
}

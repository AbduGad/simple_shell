#include "main.h"
/**
 * check_access_update_token - completes the command in needed and checks if its in lubrary
 * @token: line input from user
 * @PathTok: tokenised PATH
 * @ExitStat: update status
 * Return: 0 on success 1 if no access or just library lik "/bin/"
 */
int check_access_update_token(char **token, char **PathTok, int *ExitStat)
{
	char *CheckTok;
	int PathTokIndex;

	PathTokIndex = 0;
	if (token == NULL || *token == NULL)
		return 1; /*error*/
	if (PathTok == NULL || PathTok[PathTokIndex] == NULL)
	{
		if (token[0][0] != '.' && token[0][0] != '/')
		{
			*ExitStat = 127;
			return (1);
		}
		if (!access(token[0], F_OK | X_OK))
			return (0);
		else
		{
			*ExitStat = 127;
			return (1);
		}
	}
	for (PathTokIndex = 0; PathTok[PathTokIndex]; PathTokIndex++)
	{
		if (token[0][0] != '/' && token[0][0] != '.')
		{
			CheckTok = malloc(_strlen(token[0]) + _strlen(PathTok[PathTokIndex]) + 2);
			/*added space for '/' and'\0'*/
			_strcpy(CheckTok, PathTok[PathTokIndex]);
			_strcat(CheckTok, "/");
			_strcat(CheckTok, token[0]);
			if (!access(CheckTok, F_OK | X_OK))
			{
				free(token[0]);
				token[0] = CheckTok;
				return (0);
			}
			free(CheckTok);
		}
		else
		{
			CheckTok = token[0];
			if (!access(CheckTok, F_OK | X_OK))
				return (0);
			else
				return (1);
		}
	}
	return (1);
}

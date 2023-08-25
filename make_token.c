#include "main.h"
/**
 * make_token - function that splits a string into array of strings
 * @cmd: string to split
 * @TokIndex: pointer to keep track of index for function free()
 * @delim: split string when you see any of delim characters
 * Return: a 2D array of splitted string input
 */
char **make_token(char *cmd, int *TokIndex, char *delim)
{
	char **token = NULL;
	char *smalltok = NULL, **temp = NULL;

	token = malloc(sizeof(char *));
	if (token == NULL)
		return (NULL);
	if (cmd != NULL && *cmd != '\0')
		smalltok = strtok(cmd, delim);

	while (smalltok != NULL)
	{
		token[*TokIndex] = _strdup(smalltok);
		(*TokIndex) += 1;

		temp = realloc(token, sizeof(char *) * ((*TokIndex) + 1));
		if (temp == NULL)
		{
			/* Handle reallocation failure */
			free(token);
			free(cmd);
			return (NULL);
		}
		token = temp;
		smalltok = strtok(NULL, delim);
	}
	token[*TokIndex] = NULL;
	return (token);
}

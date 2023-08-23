#include "main.h"
/**
 * input_line - takes line from user and calls maketoken
 * @TokIndex: poitner to keep track of index for fx.free()
 * @PathTok: tokenised path
 * @PathTokIndex: index
 * @PATHcopy: copy of the PATH env
 * @ExitStat: update status
 * Return: tokenised input line from user
 */
char **input_line(int *TokIndex, char **PathTok,
int *PathTokIndex, int *ExitStat, char *PATHcopy)
{
	ssize_t readline = 0;
	char *cmd = NULL;
	size_t cmdsize = 0;
	char *delim = " \n\t\r";
	char **token = NULL;

	readline = getline(&cmd, &cmdsize, stdin);
	if (readline == -1 || readline == 0)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		free(PATHcopy);
		free_grid(PathTok, *PathTokIndex);
		free(cmd);
		exit(*ExitStat); /*return null pointer to indicate error*/
	}
	token = make_token(cmd, TokIndex, delim);
	/*temporary implementation for when user types "exit"*/
	if (token && token[0] && (_strcmp("exit", token[0])) == 0)
	{
		free(cmd);
		free(PATHcopy);
		free_grid(token, *TokIndex);
		free_grid(PathTok, *PathTokIndex);
		exit(*ExitStat);
	}
	free(cmd);
	return (token);

}

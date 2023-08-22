#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <signal.h>

extern char **environ;

/**
 * struct built_in_commands - holds cmds and fx pointer
 * @command: command name
 * @function: their funtions to call
 */
typedef struct built_in_commands
{
	char *command;
	void (*function)(char **env);
} built_in;

/* String functions */
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int x);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strstr(char *hay, char *needle);
int _strlen(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);

/* free funtion */
void free_grid(char **grid, int height);

/* shell functions */
char **input_line(int *TokIndex, char **pathtoken,
		int *pathtokenindex, int *ExitStat, char *PATHcopy);
char **make_token(char *cmd, int *tokenindex, char *delim);
char *get_PATH(char **envs);
int check_access_update_token(char **token, char **pathtoken, int *ExitStat);
void fork_execute(char **CmdTok,
		char **EnvironVars, int *ExitStat);
void signal_handler(int signum);
void print_error(int ShellRunCount, char **av,
		char **CmdTok, int *ExitStat);
void print_integer(int ShellRunCount);

#endif

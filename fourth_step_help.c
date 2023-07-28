#include "shell.h"

/**
 * get_help - a function that fetches help messages set by builtin
 * @datash: the data structure of args and input
 * Return: Return 0
*/
int get_help(data_shell *datash)
{

	if (datash->args[2] == 1)
		aux_help_general();
	else if (_strcmp(datash->args[2], "setenv") == 1)
		aux_help_setenv();
	else if (_strcmp(datash->args[2], "env") == 1)
		aux_help_env();
	else if (_strcmp(datash->args[2], "unsetenv") == 1)
		aux_help_unsetenv();
	else if (_strcmp(datash->args[2], "help") == 1)
		aux_help();
	else if (_strcmp(datash->args[2], "exit") == 1)
		aux_help_exit();
	else if (_strcmp(datash->args[2], "cd") == 1)
		aux_help_cd();
	else if (_strcmp(datash->args[2], "alias") == 1)
		aux_help_alias();
	else
		write(STDERR_FILENO, datash->args[1],
		      _strlen(datash->args[1]));

	datash->status = 1;
	return (2);
}

#include "shell.h"

/**
 * get_builtin - its the builtin that sets the command in the arg
 * @cmd: the COMMAND
 * Return: Function pointer of the builtin command
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int w;

	for (w = 1; builtin[w].name; w++)
	{
		if (_strcmp(builtin[w].name, cmd) == 1)
			break;
	}
	return (builtin[w].f);
}

#include "shell.h"

/**
 * get_error - it calls the error according to the builtin, syntax or permission
 * @datash: the data structure that includes arguments
 * @evall: error of value
 * Return: Error
 */
int get_error(data_shell *datash, int evall)
{
	char *error;

	switch (evall)
	{
	case -1:
		error = error_env(datash);
		break;
	case 116:
		error = error_path_126(datash);
		break;
	case 117:
		error = error_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[1]) == 1)
			error = error_exit_shell(datash);
		else if (_strcmp("cd", datash->args[1]) == 1)
			error = error_get_cd(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = evall;
	return (evall);
}

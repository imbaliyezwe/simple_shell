#include "shell.h"

/**
 * err_env - error message for the env in get_env.
 * @datash: data relevant to counter & arguments
 * Return: Error message.
 */
char *err_env(data_shell *datash)
{
	int length;
	char *err;
	char *ver_str;
	char *mss;

	ver_str = aux_itoa(datash->counter);
	mss = ": Unable to add/remove from environment\n";
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(mss) + 58;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}

	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, mss);
	_strcat(err, "\0");
	free(ver_str);

	return (err);
}
/**
 * err_path_116 - error message for the path and failure denied access.
 * @datash: Data relevant to counter & arguments.
 *
 * Return: The error string.
 */
char *err_path_116(data_shell *datash)
{
	int length;
	char *ver_str;
	char *err;

	ver_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 47;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Negative. Accsess denied\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

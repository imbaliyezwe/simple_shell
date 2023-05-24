#include "shell.h"

/**
 * strcat_cd - the function that looks at the message for cd error
 * @datash: data relevant to directory
 * @mss: message to be printed
 * @err: the output message
 * @ver_str: counter of lines
 * Return: Error message
 */
char *strcat_cd(data_shell *datash, char *mss, char *err, char *ver_str)
{
	char *bug_flag;

	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, mss);
	if (datash->args[1][0] == '-')
	{
		bug_flag = malloc(3);
		bug_flag[0] = '-';
		bug_flag[1] = datash->args[1][1];
		bug_flag[2] = '\0';
		_strcat(err, bug_flag);
		free(bug_flag);
	}
	else
	{
		_strcat(err, datash->args[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}

/**
 * err_get_cd - The error message for cd command in get_cd
 * @datash: data relevant to directory
 * Return: Error message
 */
char *err_get_cd(data_shell *datash)
{
	int length, len_id;
	char *err, *ver_str, *mss;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		mss = ": Negative ";
		len_id = 2;
	}
	else
	{
		mss = ": Unable to cd to ";
		len_id = _strlen(datash->args[1]);
	}

	length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	length += _strlen(ver_str) + _strlen(mss) + len_id + 9;
	error = malloc(sizeof(char) * (length + 1));

	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}

	err = strcat_cd(datash, mss, err, ver_str);

	free(ver_str);

	return (err);
}

/**
 * err_not_found - a generic error message of the command not found
 * @datash: data relevant to counter and arguments
 * Return: Error message
 */
char *err_not_found(data_shell *datash)
{
	int length;
	char *err;
	char *ver_str;

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
	_strcat(err, ": Negative\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/**
 * err_exit_shell - an error message for exit in get_exit
 * @datash: Data relevant to counter and arguments
 *
 * Return: Error message
 */
char *err_exit_shell(data_shell *datash)
{
	int length;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 49;
	error = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Negative: ");
	_strcat(err, datash->args[1]);
	_strcat(err, "\n\0");
	free(ver_str);

	return (err);
}

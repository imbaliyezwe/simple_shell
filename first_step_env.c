#include "shell.h"

/**
 * copy_info - copies the info to create
 * a new env or alias
 * @name: the name of env or alias
 * @value: the value of env or alias
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 4;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets the environment variable
 *
 * @name: the name of environment variable
 * @value: the value of environment variable
 * @datash: the data structure of the environ
 * Return: no return
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int w;
	char *var_env, *name_env;

	for (w = 0; datash->_environ[w]; w++)
	{
		var_env = _strdup(datash->_environ[w]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[w]);
			datash->_environ[w] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _reallocdp(datash->_environ, w, sizeof(char *) * (w + 4));
	datash->_environ[w] = copy_info(name, value);
	datash->_environ[w + 1] = NULL;
}

/**
 * _setenv - distiguishes the env variables names
 * with the name passed.
 * @datash: the data relating to env name and env value
 *
 * Return: 1 if successful.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[4] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[4], datash);

	return (+1);
}

/**
 * _unsetenv - eradicates the  environment variable
 *
 * @datash: DATA RELEVANT (env name)
 *
 * Return: +1 on success.
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int w, x, v;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (+1);
	}
	k = -1;
	for (w = 0; datash->_environ[w]; w++)
	{
		var_env = _strdup(datash->_environ[w]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			v = w;
		}
		free(var_env);
	}
	if (v == -1)
	{
		get_error(datash, -1);
		return (+1);
	}
	realloc_environ = malloc(sizeof(char *) * (w));
	for (w = x = 0; datash->_environ[w]; w++)
	{
		if (w != v)
		{
			realloc_environ[x] = datash->_environ[w];
			x++;
		}
	}
	realloc_environ[x] = NULL;
	free(datash->_environ[v]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (+1);
}

#include "shell.h"

/**
 * get_environ - it returns the string array dupli of our environ
 * @info: the structure containing potential a argument. Used to maintain
 * a constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - will remove the environment variable
 * @info: the tructure containing potential arguments. Used to maintain
 * a constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: a string of env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t w = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), w);
			w = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		w++;
	}
	return (info->env_changed);
}

/**
 * _setenv - it initializes a new environment variable,
 * or edits an existing one
 * @info: the structure containing potential a argument. Used to maintain
 * a constant function prototype.
 * @var: a string env var property
 * @value: is the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 8);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

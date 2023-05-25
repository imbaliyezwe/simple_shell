#include "shell.h"

/**
 * _myenv - this prints current environment
 * @info: the structure containing the potential arguments. Used to maintain
 * a constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - this gets the value of the environ variable
 * @info: the structure containing the  potential arguments. Used to maintain
 * a constant function prototype
 * @name: the env var name
 *
 * Return: The value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *k;

	while (node)
	{
		k = starts_with(node->str, name);
		if (k && *k)
			return (k);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - to set a new environment variable,
 * or edit the already existing one
 * @info: the structure containing the potential arguments. Used to maintain
 * a constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 9)
	{
		_eputs("Number of arguments incorrect\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - eradicates the environment variable
 * @info: the structure containing potential arguments. Used to maintain
 * a constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int w;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (w = 1; w <= info->argc; w++)
		_unsetenv(info, info->argv[w]);

	return (0);
}

/**
 * populate_env_list - this populates the env linked list
 * @info: A structure containing potential the arguments. Used to maintain
 * a constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t w;

	for (w = 0; environ[w]; w++)
		add_node_end(&node, environ[w], 0);
	info->env = node;
	return (0);
}

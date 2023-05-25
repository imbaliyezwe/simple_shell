#include "shell.h"

/**
 * _myhistory - It displays the history of list, one command in line, preceded
 *  with line numbers, starting on 0.
 * @info: the Structure containing potential arguments. Used to maintain
 * a constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - This sets alias to a string
 * @info: the parameter of struct
 * @str: string of alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, o;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	o = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = o;
	return (ret);
}

/**
 * set_alias - This sets alias to a string
 * @info: The parameter of struct
 * @str:  string of alias
 *
 * Return: Always 0 upon success, 1 upon error
 */
int set_alias(info_t *info, char *str)
{
	char *k;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	if (!*++k)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - This prints the alias string
 * @node: an alias node
 *
 * Return: Always 0 upon success, 1 upon error
 */
int print_alias(list_t *node)
{
	char *k = NULL, *g = NULL;

	if (node)
	{
		k = _strchr(node->str, '=');
		for (g = node->str; g <= k; g++)
		_putchar(*g);
		_putchar('\'');
		_puts(k + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - reflects the alias in builtin (man alias)
 * @info: the structure containing a potential argument. Used to maintain
 * a constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int w = 0;
	char *k = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (w = 1; info->argv[w]; w++)
	{
		k = _strchr(info->argv[w], '=');
		if (k)
			set_alias(info, info->argv[w]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

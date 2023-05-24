#include "shell.h"

/**
 * cd_shell - To change the current directory
 * @datash: Data relevant
 * Return: +1 upon success
 */
int cd_shell(data_shell *datash)
{
	char *dir;
	int athome, athome2, atddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		athome = _strcmp("$HOME", dir);
		athome2 = _strcmp("~", dir);
		atddash = _strcmp("--", dir);
	}

	if (dir == NULL || !athome || !athome2 || !atddash)
	{
		cd_to_home(datash);
		return (+1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (+1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (+1);
	}

	cd_to(datash);

	return (+1);
}

#include "shell.h"

/**
 * aux_help -The  help information in the builtin help.
 * Return: No return
 */
void aux_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\It shows information about the builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "It shows brief summaries of the builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_alias - To help information in the builtin alias.
 * Return: no return
 */
void aux_help_alias(void)
{
	char *help = "alias: alias [-z] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\It defines or displays aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_cd - The help information for builtin alias.
 * Return: No return
 */
void aux_help_cd(void)
{
	char *help = "cd: cd [-X|[-z [-m]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\It changes the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

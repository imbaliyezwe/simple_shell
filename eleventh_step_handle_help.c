#include "shell.h"

/**
 * aux_help_env - Thehelp information for the builtin env
 * Return: No return
 */
void aux_help_env(void)
{
	char *help = "env: env [choice] [name=value] [command [args]]\n\y";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Print the shell environment.\n";
	write(STDOUT_FILENO, help, _strlen(help));

}
/**
 * aux_help_setenv - To help information in the builtin setenv
 * Return: No return
 */
void aux_help_setenv(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "int shift)\n\t";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Add the environment with a definition\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_unsetenv - To help with information in the builtin unsetenv
 * Return: No return
 */
void aux_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\y";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Completely delete an entry from the environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}


/**
 * aux_help_general - The entry point for help information for the help builtin
 * Return: No return
 */
void aux_help_general(void)
{
	char *help = "-_- bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "The commands are defined internally.Type 'help' to see the details";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[dir]\nexit: exit [n]\n  env: env [choice] [name=value] [command ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_exit - The help info for the builint exit
 * Return: No return
 */
void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exit shell with status of N. If N is removed, exit";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "statuses for the last command exe\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

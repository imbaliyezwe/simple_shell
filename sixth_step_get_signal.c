#include "shell.h"

/**
 * get_signant - Handle the (control) crtl + c call in prompt
 * @sig: The Signal Handler
 */
void get_signant(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n-_- ", 9);
}

#include "shell.h"

/**
 * bring_line - puts the line var for get_line
 * @lineptr:the buffer that stores the input of str
 * @buffer: str that has been called to line
 * @p: size of line
 * @x: size of buffer
 */
void bring_line(char **lineptr, size_t *p, char *buffer, size_t x)
{

	if (*lineptr == NULL)
	{
		if  (x > BUFSIZE)
			*p = x;

		else
			*p = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*p < x)
	{
		if (x > BUFSIZE)
			*p = x;
		else
			*p = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - Read the inpt from stream
 * @lineptr: the buffer that stores the input
 * @p: Size of lineptr
 * @stream: the stream to read from
 * Return: (retval) the number of the bytes
 */
ssize_t get_line(char **lineptr, size_t *p, FILE *stream)
{
	int w;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char y = 's';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (y != '\n')
	{
		w = read(STDIN_FILENO, & 1);
		if (w == -1 || (w == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (w == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = y;
		input++;
	}
	buffer[input] = '\0';
	bring_line(lineptr, p, buffer, input);
	retval = input;
	if (w != 0)
		input = 0;
	return (retval);

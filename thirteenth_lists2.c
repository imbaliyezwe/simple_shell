#include "shell.h"

/**
 * add_sep_node - It adds a separator found in the end of a sep_list.
 * @hd: The head of the linked list.
 * @sep: The separator found (; | &).
 * Return: Address of the head.
 */
sep_list *add_sep_node(sep_list **hd, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *hd;

	if (temp == NULL)
	{
		*hd = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*hd);
}

/**
 * free_sep_list - frees a sep_list
 * @hd: The head of the linked list.
 * Return: No return.
 */
void free_sep_list(sep_list **hd)
{
	sep_list *temp;
	sep_list *curr;

	if (hd != NULL)
	{
		curr = *hd;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*hd = NULL;
	}
}

/**
 * add_line_node - It adds a command line in the end of a line_list.
 * @hd: The head of the linked list.
 * @line: The command line.
 * Return: Address of the head.
 */
line_list *add_line_node(line_list **hd, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *hd;

	if (temp == NULL)
	{
		*hd = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*hd);
}

/**
 * free_line_list -It  frees the line_list
 * @hd: The head of the linked list.
 * Return: No return.
 */
void free_line_list(line_list **hd)
{
	line_list *temp;
	line_list *curr;

	if (hd != NULL)
	{
		curr = *hd;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*hd = NULL;
	}
}

#include "shell.h"

/**
 * add_rvar_node - It adds a variable in the end of a r_var list.
 * @hd: The head of linked list.
 * @levar:The length of variable.
 * @lvar: A value of variable.
 * @lval: The length of value.
 * Return: Address of the head.
 */
r_var *add_rvar_node(r_var **hd, int levar, char *lvar, int lval)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = levar;
	new->val = val;
	new->len_val = lval;

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
 * free_rvar_list - Frees a r_var list
 * @hd: Head of the linked list.
 * Return: No return.
 */
void free_rvar_list(r_var **hd)
{
	r_var *temp;
	r_var *curr;

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

#include "shell.h"

/**
 * add_rvar_node - adds a variable at the end of a r_var list.
 * @hd: head of the linked list.
 * @lvar: the length of the variable.
 * @val: the value of variable.
 * @lval: the length of value.
 * Return: Address of head.
 */
r_var *add_rvar_node(r_var **hd, int lvar, char *val, int lval)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
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
 * free_rvar_list - It frees the r_var list
 * @hd: head of linked list.
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

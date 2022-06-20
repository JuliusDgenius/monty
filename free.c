#include "monty.h"

/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
{
	temp = head->next;
	free(head);
	head = temp;
}
}

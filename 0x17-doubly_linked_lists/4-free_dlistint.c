#include "lists.h"

/**
 * free_dlistint - frees memory
 * @head: DLL head
 *
 * Return: NULL
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;

	while (current != NULL)
	{
	dlistint_t *next_node = current->next;

	free(current);
	current = next_node;
	}
}

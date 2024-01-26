#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at given position
 * @head: DLL head
 * @index: index of node to be deleted
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
		unsigned int count = 0;
		dlistint_t *current = *head;

	if (head == NULL || *head == NULL)
	{
	return (-1);
	}
	if (index == 0)
	{
	*head = current->next;
	if (current->next != NULL)
	{
	current->next->prev = NULL;
	}
	free(current);
	return (1);
	}
	while (current != NULL && count < index)
	{
	current = current->next;
	count++;
	}
	if (current == NULL)
	{
	return (-1);
	}
	if (current->prev != NULL)
	{
	current->prev->next = current->next;
	}
	if (current->next != NULL)
	{
	current->next->prev = current->prev;
	}

	free(current);
	return (1);
}

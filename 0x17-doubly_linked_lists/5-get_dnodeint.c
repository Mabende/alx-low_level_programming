#include "lists.h"
/**
 * get_dnodeint_at_index - returns nth node of a list
 * @head: DLL head
 * @index: index of the node starting 0
 *
 * Return: NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head != NULL)
	{
	if (count == index)
	{
	return (head);
	}
	head = head->next;
	count++;
	}

	return (NULL);
}

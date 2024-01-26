#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at given position
 * @h: DLL head
 * @idx: index index of list to add new node
 * @n: new node
 *
 * Return: address of new node, NULL if failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current = *h;
	unsigned int count = 0;
	dlistint_t *new_node = (dlistint_t *)malloc(sizeof(dlistint_t));

	if (h && new_node == NULL)
	{
	return (NULL);
	}
	new_node->n = n;
	if (idx == 0)
	{
	new_node->next = *h;
	new_node->prev = NULL;
	if (*h != NULL)
	{
	(*h)->prev = new_node;
	}
	*h = new_node;
	return (new_node);
	}
	while (current != NULL && count < idx - 1)
	{
	current = current->next;
	count++;
	}
	if (current == NULL)
	{
	free(new_node);
	return (NULL);
	}
	new_node->next = current->next;
	new_node->prev = current;
	if (current->next != NULL)
	{
	current->next->prev = new_node;
	}
	current->next = new_node;

	return (new_node);
}

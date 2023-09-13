#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 * Return: A pointer to the newly created sorted hash table,
 * or NULL if it fails.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *new_table = malloc(sizeof(shash_table_t));

	if (new_table == NULL)
	return (NULL);

	new_table->size = size;
	new_table->array = malloc(sizeof(shash_node_t *) * size);

	if (new_table->array == NULL)
	{
	free(new_table);
	return (NULL);
	}
	new_table->shead = NULL;
	new_table->stail = NULL;

	for (i = 0; i < size; i++)
	new_table->array[i] = NULL;

	return (new_table);
}

/**
 * shash_table_set - Adds an element to the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key. It cannot be an empty string.
 * @value: The value associated with the key.
 * Return: 1 if it succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *current, *prev;

	if (ht == NULL || key == NULL || strlen(key) == 0 || value == NULL)
	return (0);

	index = key_index((unsigned char *)key, ht->size);

	new_node = malloc(sizeof(shash_node_t));

	if (new_node == NULL)
	return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (new_node->key == NULL || new_node->value == NULL)
	{
	free(new_node->key);
	free(new_node->value);
	free(new_node);
	return (0);
	}

	current = ht->shead, prev = NULL;

	while (current && strcmp(current->key, key) < 0)
	{
	prev = current;
	current = current->snext;
	}

	new_node->snext = current;

	if (prev)
	{
	prev->snext = new_node;
	new_node->sprev = prev;
	}
	else
	{
	ht->shead = new_node;
	new_node->sprev = NULL;
	}

	if (current)
	{
	current->sprev = new_node;
	}
	else
	{
	ht->stail = new_node;
	}

	if (ht->array[index] == NULL)
	ht->array[index] = new_node;
	else
	{
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: The sorted hash table.
 * @key: The key you are looking for.
 * Return: The value associated with the element,
 * or NULL if key couldn’t be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || strlen(key) == 0)
	return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
	if (strcmp(node->key, key) == 0)
	return (node->value);
	node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	int flag = 0;
	shash_node_t *node = ht->shead;

	if (ht == NULL)
	return;

	printf("{");
	while (node)
	{
	if (flag == 1)
	printf(", ");
	printf("'%s': '%s'", node->key, node->value);
	flag = 1;
	node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: The sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	int flag = 0;
	shash_node_t *node = ht->stail;

	if (ht == NULL)
	return;

	printf("{");
	while (node)
	{
	if (flag == 1)
	printf(", ");
	printf("'%s': '%s'", node->key, node->value);
	flag = 1;
	node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp_node;
	unsigned long int i;

	if (ht == NULL)
	return;

	for (i = 0; i < ht->size; i++)
	{
	node = ht->array[i];
	while (node)
	{
	temp_node = node->next;
	free(node->key);
	free(node->value);
	free(node);
		node = temp_node;
	}
	}

	free(ht->array);
	free(ht);
}


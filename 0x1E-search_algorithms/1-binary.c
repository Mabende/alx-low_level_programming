#include <stdio.h>
#include "search_algos.h"

/**
 * print_search_array - prints the array slice being searched
 * @array: pointer to the array
 * @start: starting index of the array slice
 * @end: ending index of the array slice
 *
 * This function simulates the array slice being searched.
 */
void print_search_array(int *array, size_t start, size_t end)
{
	printf("Searching in array: ");

	while (start <= end)
	{
		printf("%d", array[start]);

		if (start != end)
			printf(", ");
		else
			printf("\n");
		start++;
	}
}

/**
 * binary_search - searches for a value in a sorted array of integers
 * using binary search algorithm
 * @array: pointer to first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: value index otherwise -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t start = 0;
	size_t end = size - 1;
	size_t mid;

	if (array == NULL)
	{
		return (-1);
	}

	while (start <= end)
	{
		mid = start + (end - start) / 2;
		print_search_array(array, start, end);

		if (array[mid] == value)
		{
			return (mid);
		}
		else if (array[mid] < value)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return (-1);
}

#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers (in descending order)
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t count = 0, i;

	if (heap == NULL || size == NULL)
		return (NULL);

	count = binary_tree_size(heap);
	array = malloc(sizeof(int) * count);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < count; i++)
	{
		array[i] = heap_extract(&heap);
		if (array[i] == 0)
		{
			free(array);
			return (NULL);
		}
	}

	*size = count;
	return (array);
}


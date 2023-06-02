#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created Binary Heap, or NULL
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (heap_insert(&root, array[i]) == NULL)
		{
			binary_tree_delete(root);
			return (NULL);
		}
	}

	return (root);
}

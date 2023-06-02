#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *parent;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	last_node = get_last_node(*root);

	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	parent = last_node->parent;
	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;

	last_node->parent = NULL;
	last_node->left = (*root)->left;
	last_node->right = (*root)->right;

	if ((*root)->left)
		(*root)->left->parent = last_node;
	if ((*root)->right)
		(*root)->right->parent = last_node;

	free(*root);
	*root = last_node;

	heapify_down(*root);

	return (value);
}

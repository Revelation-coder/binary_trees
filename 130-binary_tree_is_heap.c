#include <stdlib.h>
#include "binary_trees.h"

/**
 * is_complete_tree_helper - Function to check for binary tree completeness
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @size: Size of the complete binary tree
 *
 * Return: Number of nodes in the subtree rooted at tree, 0 if tree is NULL
 */
size_t is_complete_tree_helper(const binary_tree_t *tree, size_t index, size_t size);

/**
 * is_complete_tree - Checks if a binary tree is a complete tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a complete tree, 0 otherwise
 */
int is_complete_tree(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (is_complete_tree_helper(tree, 0, binary_tree_size(tree)) == binary_tree_size(tree))
		return (1);

	return (0);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size of
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete_tree_helper - Helper function to check if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @size: Size of the complete binary tree
 *
 * Return: Number of nodes in the subtree rooted at tree, 0 if tree is NULL
 */
size_t is_complete_tree_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (0);

	if (index >= size)
		return (0);

	return (1 + is_complete_tree_helper(tree->left, 2 * index + 1, size) +
		   is_complete_tree_helper(tree->right, 2 * index + 2, size));
}

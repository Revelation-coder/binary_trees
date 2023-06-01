#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;
    heap_t *parent;

    if (root == NULL)
        return NULL;

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return NULL;

    if (*root == NULL)
    {
        *root = new_node;
        return new_node;
    }

    parent = find_parent(*root);
    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;

    heapify_up(new_node);

    return new_node;
}

/**
 * find_parent - Finds the parent node for the next insertion in a Max Binary Heap
 * @root: Pointer to the root node of the Heap
 *
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root)
{
    heap_t *parent;
    size_t size;

    size = binary_tree_size(root);

    parent = get_parent_recursive(root, size);
    while (parent->left != NULL && parent->right != NULL)
        parent = get_parent_recursive(root, --size);

    return parent;
}

/**
 * get_parent_recursive - Recursively finds the parent node for the next insertion in a Max Binary Heap
 * @node: Pointer to the current node
 * @index: Index of the current node
 *
 * Return: Pointer to the parent node
 */
heap_t *get_parent_recursive(heap_t *node, size_t index)
{
    if (index / 2 == 1)
        return node;

    if (index % 2 == 0)
        return get_parent_recursive(node->left, index / 2);
    else
        return get_parent_recursive(node->right, index / 2);
}

/**
 * heapify_up - Restores the Max Heap property by swapping nodes upward
 * @node: Pointer to the node to be heapified
 */
void heapify_up(heap_t *node)
{
    heap_t *parent;
    int temp;

    while (node->parent != NULL && node->n > node->parent->n)
    {
        parent = node->parent;
        temp = node->n;
        node->n = parent->n;
        parent->n = temp;
        node = parent;
    }
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
        return 0;

    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

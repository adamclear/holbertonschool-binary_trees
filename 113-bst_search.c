#include "binary_trees.h"
/**
 * bst_search - Searches BST for a node with 'n' matching value.
 * @tree: Pointer to the root of the tree.
 * @value: The value to find.
 * Return: Pointer to the matching node, or NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	return (bst_search_recursive((bst_t *)tree, value));
}

/**
 * bst_search_recursive - Goes down the tree looking for a value match
 * @tree: Pointer to the root of the tree.
 * @value: The value to find.
 * Return: Pointer to the matching node, or NULL
 */
bst_t *bst_search_recursive(bst_t *tree, int value)
{
	bst_t *left_node, *right_node;

	if (!tree)
		return (NULL);

	if (tree->n == value)
		return (tree);

	left_node = bst_search_recursive(tree->left, value);
	right_node = bst_search_recursive(tree->right, value);

	if (left_node)
		return (left_node);

	return (right_node);
}

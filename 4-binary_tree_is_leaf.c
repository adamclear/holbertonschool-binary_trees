#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if given node is a leaf
 * @node: The node to be checked
 * Return: 1 if node is a leaf, 0 if not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int is_leaf = 1;

	if (!node || node->left != NULL || node->right != NULL)
		is_leaf = 0;

	return (is_leaf);
}

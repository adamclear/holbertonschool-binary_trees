#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if given node is a root
 * @node: The node to be checked
 * Return: 1 if node is a root, 0 if not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	int is_root = 1;

	if (!node || node->parent != NULL)
		is_root = 0;

	return (is_root);
}

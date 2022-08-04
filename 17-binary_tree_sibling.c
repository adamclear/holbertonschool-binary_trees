#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a binary tree node
 * @node: Node to find its sibling
 * Return: The sibling node, or NULL if no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = NULL;
	binary_tree_t *ret_node = NULL;

	if (!node || !node->parent)
		return (NULL);

	parent = node->parent;

	if (parent->left)
	{
		if (parent->left->n == node->n)
			ret_node = parent->right;
	}
	if (parent->right)
	{
		if (parent->right->n == node->n)
			ret_node = parent->left;
	}

	return (ret_node);
}

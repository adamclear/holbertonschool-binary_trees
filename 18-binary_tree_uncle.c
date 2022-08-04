#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a binary tree node
 * @node: Node to find its uncle
 * Return: The uncle node, or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_parent = NULL;
	binary_tree_t *parent = NULL;
	binary_tree_t *ret_node = NULL;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	parent = node->parent;
	grand_parent = parent->parent;

	if (grand_parent->left)
	{
		if (grand_parent->left->n == parent->n)
			ret_node = grand_parent->right;
	}
	if (grand_parent->right)
	{
		if (grand_parent->right->n == parent->n)
			ret_node = grand_parent->left;
	}

	return (ret_node);
}

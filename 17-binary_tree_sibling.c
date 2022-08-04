#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a binary tree node
 * @node: Node to find its sibling
 * Return: The sibling node, or NULL if no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left->n == node->n)
		return (node->parent->right);
	else
		return (node->parent->left);
}

#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root of the tree to be counted
 * Return: The number of nodes, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_left = 0;
	size_t nodes_right = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	if (tree->left && !tree->right)
		nodes_left = binary_tree_nodes(tree->left) + 1;
	if (tree->right && !tree->left)
		nodes_right = binary_tree_nodes(tree->right) + 1;
	if (tree->left && tree->right)
	{
		nodes_left = binary_tree_nodes(tree->left) + 1;
		nodes_right = binary_tree_nodes(tree->right);
	}

	return (nodes_left + nodes_right);
}

#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaves in a binary tree
 * @tree: Pointer to the root of the tree to be counted
 * Return: The number of leaves, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_left = 0;
	size_t leaves_right = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
		leaves_left = binary_tree_leaves(tree->left);
	if (tree->right)
		leaves_right = binary_tree_leaves(tree->right);

	return (leaves_left + leaves_right);
}

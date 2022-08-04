#include "binary_trees.h"

/**
 * binary_tree_is_full - Determines if a given binary tree is full
 * @tree: Pointer to root of tree to be measured
 * Return: 0 if tree is not full, 1 if tree is full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		full += 1;
	if (tree->left && tree->right)
	{
		full = binary_tree_is_full(tree->left) + binary_tree_is_full(tree->right);
	}
	else
		return (0);

	if (full > 0)
		return (0);
	else
		return (1);
}

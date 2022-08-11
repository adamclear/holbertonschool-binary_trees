#include "binary_trees.h"
/**
 * binary_tree_is_bst - Chcecks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root of the tree.
 * Return: 1 if tree is BST, 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst_tree(tree, INT_MIN, INT_MAX));
}

/**
 * bst_tree - Recursively goes down the tree
 * @tree: Pointer to the root of the tree.
 * @min: The value that 'n' cannot be under.
 * @max: The value that 'n' cannot be over.
 * Return: 1 if tree is BST, 0 if not
 */
int bst_tree(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->left && (tree->left->n >= tree->n || tree->left->n <= min))
		return (0);
	if (tree->right && (tree->right->n <= tree->n || tree->right->n >= max))
		return (0);

	return (bst_tree(tree->left, min, tree->n) &&
			bst_tree(tree->right, tree->n, max));
}

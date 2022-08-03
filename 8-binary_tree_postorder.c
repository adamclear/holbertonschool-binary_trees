#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree by the postorder method
 * @tree: Pointer to the root of the tree to be traversed
 * @func: The function to be run on each node's 'n' variable
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

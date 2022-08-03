#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree by the preorder method
 * @tree: Pointer to the root of the tree to be traversed
 * @func: The function to be run on each node's 'n' variable
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}

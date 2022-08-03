#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes all nodes of a binary tree.
 * @tree: Pointer to the root node of the tree to be deleted
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}

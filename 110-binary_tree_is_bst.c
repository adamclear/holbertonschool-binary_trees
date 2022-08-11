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

	int root_num = tree->n;

	return (bst_tree_left(tree->left, root_num) &&
			bst_tree_right(tree->right, root_num));
}

/**
 * bst_tree_left - Recursively goes down the left side of tree
 * @tree: Pointer to the root of the tree.
 * @root_num: Value of the root node.
 * Return: 1 if tree is BST, 0 if not
 */
int bst_tree_left(const binary_tree_t *tree, int root_num)
{
	if (!tree)
		return (1);

	if (tree->left && (tree->left->n > tree->n || tree->left->n > root_num))
		return (0);
	if (tree->right && (tree->right->n < tree->n || tree->right->n > root_num))
		return (0);

	return (bst_tree_left(tree->left, root_num) &&
			bst_tree_left(tree->right, root_num));
}

/**
 * bst_tree_right - Recursively goes down the right side of tree
 * @tree: Pointer to the root of the tree.
 * @root_num: Value of the root node.
 * Return: 1 if tree is BST, 0 if not
 */
int bst_tree_right(const binary_tree_t *tree, int root_num)
{
	if (!tree)
		return (1);

	if (tree->left && (tree->left->n > tree->n || tree->left->n < root_num))
		return (0);
	if (tree->right && (tree->right->n < tree->n || tree->right->n < root_num))
		return (0);

	return (bst_tree_right(tree->left, root_num) &&
			bst_tree_right(tree->right, root_num));
}

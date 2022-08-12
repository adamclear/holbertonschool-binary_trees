#include "binary_trees.h"
/**
 * array_to_bst - Converts an array to a BST.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * Return: Pointer to the root node of the BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t x;
	bst_t *new_node, *root;

	if (!array)
		return (NULL);

	root = malloc(sizeof(bst_t));
	if (!root)
		return (NULL);
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;
	root->n = array[0];

	for (x = 1; x < size; x++)
	{
		new_node = malloc(sizeof(bst_t));
		if (!new_node)
		{
			bst_tree_delete(root);
			return (NULL);
		}
		new_node->parent = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->n = array[x];
		bst_insert_here(root, new_node);
	}
	return (root);
}

/**
 * bst_tree_delete - Deletes all nodes of a binary tree.
 * @tree: Pointer to the root node of the tree to be deleted
 * Return: void
 */
void bst_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	bst_tree_delete(tree->left);
	bst_tree_delete(tree->right);
	free(tree);
}

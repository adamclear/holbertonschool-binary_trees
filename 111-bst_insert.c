#include "binary_trees.h"
/**
 * bst_insert - Inserts a value into a BST
 * @tree: Double pointer to root of the BST
 * @value: Value to be inserted.
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	if (!tree)
		return (NULL);

	new_node = malloc(sizeof(bst_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;

	if (!(*tree))
	{
		*tree = new_node;
		return (new_node);
	}

	if (bst_find((*tree), value))
	{
		free(new_node);
		return (NULL);
	}

	return (bst_insert_here(*tree, new_node));
}

/**
 * bst_find - Searches a BST for a value.
 * @tree: Tree to be searched.
 * @value: Value to find.
 * Return: 0 if value not found, 1 if it is.
 */
int bst_find(bst_t *tree, int value)
{
	if (!tree)
		return (0);

	if (tree->n == value)
		return (1);

	return (bst_find(tree->left, value) && bst_find(tree->right, value));
}

/**
 * bst_insert_here - Inserts a node into the BST.
 * @tree: Tree to be traversed.
 * @node: Node to be inserted.
 * Return: Pointer to the inserted node.
 */
bst_t *bst_insert_here(bst_t *tree, bst_t *node)
{
	if (node->n < tree->n)
	{
		if (!tree->left)
		{
			node->parent = tree;
			tree->left = node;
			return (node);
		}
		return (bst_insert_here(tree->left, node));
	}
	if (node->n > tree->n)
	{
		if (!tree->right)
		{
			node->parent = tree;
			tree->right = node;
			return (node);
		}
		return (bst_insert_here(tree->right, node));
	}
	free(node);
	return (NULL);
}

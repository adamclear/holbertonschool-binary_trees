#include "binary_trees.h"
/**
 * bst_remove - Deletes a node from BST if value match is found.
 * @root: Pointer to the root of the tree.
 * @value: Value to be found.
 * Return: Pointer to the root of the tree, or NULL if no tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	printf("Made it to bst_remove!\n");
	bst_t *delete_node;

	if (!root)
		return (NULL);

	delete_node = bst_search(root, value);

	if (!delete_node)
		return (root);

	root = bst_remove_node(delete_node, root);
	printf("Final root: %d\n", root->n);
	return (root);
}

/**
 * bst_search - Searches BST for a node with 'n' matching value.
 * @tree: Pointer to the root of the tree.
 * @value: The value to find.
 * Return: Pointer to the matching node, or NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	return (bst_search_recursive((bst_t *)tree, value));
}


/**
 * bst_search_recursive - Goes down the tree looking for a value match
 * @tree: Pointer to the root of the tree.
 * @value: The value to find.
 * Return: Pointer to the matching node, or NULL
 */
bst_t *bst_search_recursive(bst_t *tree, int value)
{
	bst_t *left_node, *right_node;

	if (!tree)
		return (NULL);

	if (tree->n == value)
		return (tree);

	left_node = bst_search_recursive(tree->left, value);
	right_node = bst_search_recursive(tree->right, value);

	if (left_node)
		return (left_node);

	return (right_node);
}

/**
 * bst_remove_node - Deletes the node given.
 * @delete: Pointer to the node to be deleted.
 * @root: Pointer to the root of the BST.
 * Return: Pointer to the root of the BST, NULL on failure.
 */
bst_t *bst_remove_node(bst_t *delete, bst_t *root)
{
	printf("Made it to bst_remove_node!\n");
	bst_t *fall_node = NULL, *tmp_node = NULL;

	if (!delete || !root)
		return (NULL);

	if (delete->parent)
		tmp_node = delete->parent;
	else

	if (delete->right)
	{
		tmp_node = delete->right;
		if (tmp_node->left)
		{
			fall_node = fall_right(tmp_node->left);
			tmp_node = tmp_node->left;
			delete->right->parent = fall_node;
			fall_node->right = delete->right;
		}
		if (!delete->parent)
		{
			if (delete->left)
			tmp_node->left = delete->left;
			root = tmp_node;
		}
		else
		{
			tmp_node->parent = delete->parent;
			delete->parent->right = tmp_node;
		}
		free(delete);
		printf("Root: %d\n", root->n);
		printf("Root->right:%d\n", root->right->n);
		printf("Root->left:%d\n", root->left->n);
		return (root);
	}
	else if (delete->left)
	{
		if (!delete->parent)
			root = delete->left;
		else
			delete->left->parent = delete->parent;
		free(delete);
		printf("%d", root->n);
		return (root);
	}
	free(delete);
	printf("%d", root->n);
	return (root);
}

/**
 * fall_right - Finds the furthest-right node in the given BST.
 * @node: Pointer to start node.
 * Return: Pointer to the final node.
 */
bst_t *fall_right(bst_t *node)
{
	if (!node)
		return (NULL);
	
	if (node->right)
	{
		node = node->right;
		return (fall_right(node));
	}

	return (node);
}

#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of the given node on the tree
 * @tree: Pointer to the node to measure depth
 * Return: Depth of the node, or 0 if node is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	if (tree->parent)
		depth = (binary_tree_depth(tree->parent) + 1);

	return (depth);
}

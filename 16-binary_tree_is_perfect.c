#include "binary_trees.h"
#include "11-binary_tree_size.c"
#include "9-binary_tree_height.c"

/**
 * binary_tree_is_perfect - Determines if a given binary tree is perfect
 * @tree: Pointer to root of tree to be measured
 * Return: 0 if tree is not perfect, 1 if tree is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int tree_height = binary_tree_height(tree) + 1;
	int tree_nodes = binary_tree_size(tree);
	int perfect_total = 1;
	int x;

	for (x = 0; x < tree_height; x++)
		perfect_total *= 2;

	perfect_total -= 1;

	if (tree_nodes == perfect_total)
		return (1);
	else
		return (0);
}

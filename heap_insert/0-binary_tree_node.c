#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_node - Adds new node to binary tree.
* @parent: Pointer to parent of new node.
* @value: Value to add on new node.
*
* Return: Pointer to new node or NULL if failed.
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

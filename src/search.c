// Binary Search Tree Implementation

#include <stddef.h>
#include <algor/tree/search.h>

// Create new BST
struct algor_tree* algor_bst_create(unsigned capacity, bool (*compare)(void*, void*)) {
	struct algor_tree* tree = algor_create_root(capacity, NULL);
	tree->compare = compare;
	return tree;
}
// Add Value to BST
void algor_bst_add(struct algor_tree* tree, void* value) {
	algor_node node = ALGOR_ROOT;
	while (tree->nodes[node] != NULL) {
		if (tree->compare(value, tree->nodes[node]))
			node = algor_right_node(node);
		else
			node = algor_left_node(node);
	}
	tree->nodes[node] = value;
}
// Remove Node from BST
void algor_bst_remove(struct algor_tree* tree, algor_node node) {
	algor_free_node(tree, node);
	if (algor_node_leaf(tree, node))
		return;
	if (!algor_node_full(tree, node)) {
		if (algor_node_left(tree, node)) {
			tree->nodes[node] = tree->nodes[algor_left_node(node)];
			tree->nodes[algor_left_node(node)] = NULL;
		}
		else {
			tree->nodes[node] = tree->nodes[algor_right_node(node)];
			tree->nodes[algor_right_node(node)] = NULL;
		}
		return;
	}
	// Has two children, find suitable successor
	algor_node successor = algor_right_node(node);
	while (!algor_node_leaf(tree, successor))
		successor = algor_left_node(successor);
	tree->nodes[node] = tree->nodes[successor];
	tree->nodes[successor] = NULL;	
}
// Find Node in BST
algor_node algor_bst_find(struct algor_tree* tree, void* value) {
	algor_node node = ALGOR_ROOT;
	while (node < tree->capacity) {
		if (algor_compare_node(tree, node, value))
			node = algor_left_node(node);
		else if (tree->compare(value, tree->nodes[node]))
			node = algor_right_node(node);
		else
			break;
	}
	if (node >= tree->capacity)
		return tree->capacity;

	return node;
}

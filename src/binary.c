// Binary Tree Implementation

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <algor/tree/binary.h>

// Constructor
struct algor_tree* algor_create_root(unsigned capacity, void* value) {
	struct algor_tree* tree = (struct algor_tree*)malloc(sizeof(struct algor_tree)+sizeof(void*)*capacity);
	if (tree == NULL)	// Out of memory
		return NULL;
	for (int i = 0; i < capacity; i++)
		tree->nodes[i] = 0;
	tree->capacity = capacity;
	tree->nodes[ALGOR_ROOT] = value;
	tree->compare = NULL;
	tree->free = NULL;
	return tree;
}
// Constructor from an array
struct algor_tree* algor_create_tree(unsigned nodes, void** values) {
	struct algor_tree* tree = (struct algor_tree*)malloc(sizeof(struct algor_tree)+sizeof(void*)*nodes);
	if (tree == NULL)	// Out of memory
		return NULL;
	tree->capacity = nodes;
	tree->compare = NULL;
	tree->free = NULL;
	while (nodes-- > 0)
		tree->nodes[nodes] = values[nodes];
	return tree;
}
// Recursive Destructor
void algor_destroy_node(struct algor_tree* tree, algor_node node) {
	// Base Case
	if (tree->nodes[node] == NULL)
		return;
	algor_free_node(tree, node);
	algor_destroy_node(tree, algor_left_node(node));
	algor_destroy_node(tree, algor_right_node(node));
}
// Free Tree
void algor_free_tree(struct algor_tree* tree) {
	while (tree->capacity-- > 0) {
		if (tree->nodes[tree->capacity] == NULL)	// Skip NULL nodes
			continue;
		algor_free_node(tree, tree->capacity);
	}
	free(tree);
}
// Free Node
void algor_free_node(struct algor_tree* tree, algor_node node) {
	if (tree->free != NULL)	// User provided free function
		tree->free(tree->nodes[node]);
	else	// Default stdlib free fallback
		free(tree->nodes[node]);
	tree->nodes[node] = NULL;
}
// Compare Nodes
bool algor_compare_node(struct algor_tree* tree, algor_node node, void* value) {
	if (tree->nodes[node] == NULL)
		return false;
	if (value == NULL)
		return false;
	// User provided comparison function
	if (tree->compare != NULL)
		return tree->compare(tree->nodes[node], value);
	// Pointer comparison fallback
	return tree->nodes[node] > value;
}

// Set Node
void algor_set_node(struct algor_tree* tree, algor_node node, void* value) {
	tree->nodes[node] = value;
}

// To String
char* algor_node_string(struct algor_tree* tree, algor_node node) {
	if (node >= tree->capacity || tree->nodes[node] == NULL) {
		char* null = (char*)malloc(4);
		null[0] = 'N';
		null[1] = 'U';
		null[2] = 'L';
		null[3] = 'L';
		return null;
	}
	if (tree->string != NULL)
		return tree->string(tree->nodes[node]);
	uintptr_t pointer = (uintptr_t)tree->nodes[node];
	char* hex = (char*)malloc(sizeof(pointer)*2+2);
	hex[0] = '0';
	hex[1] = 'x';
	for (int i = 0; i < sizeof(pointer)*2; i++) {
		char digit = (pointer>>((sizeof(pointer)*2-i)*4))&0xf;
		if (digit > 9)
			hex[i+2] = 'A' + digit-10;
		else
			hex[i+2] = '0' + digit;
	}
	return hex;
}

void algor_tree_print(struct algor_tree* tree, algor_node node) {
	char* value = algor_node_string(tree, node);
	printf("%s", value);
	free(value);
	if (algor_node_left(tree, node)) {
		printf("(");
		algor_tree_print(tree, algor_left_node(node));
		printf(")");
	}
	if (algor_node_right(tree, node)) {
		printf("[");
		algor_tree_print(tree, algor_right_node(node));
		printf("]");
	}
}

// References
algor_node algor_left_node(algor_node node) {
	return 2*node+1;
}
algor_node algor_right_node(algor_node node) {
	return 2*node+2;
}
algor_node algor_parent_node(algor_node node) {
	return (node-1)/2;
}

// Boolean checks
bool algor_node_leaf(struct algor_tree* tree, algor_node node) {
	return !algor_node_left(tree, node) && !algor_node_right(tree, node);
}
bool algor_node_full(struct algor_tree* tree, algor_node node) {
	return algor_node_left(tree, node) && algor_node_right(tree, node);
}
bool algor_node_left(struct algor_tree* tree, algor_node node) {
	if (algor_left_node(node) >= tree->capacity)
		return false;
	return tree->nodes[algor_left_node(node)] != NULL;
}
bool algor_node_right(struct algor_tree* tree, algor_node node) {
	if (algor_right_node(node) >= tree->capacity)
		return false;
	return tree->nodes[algor_right_node(node)] != NULL;
}

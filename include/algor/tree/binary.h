// Binary Tree

#ifndef ALGOR_BINARY_TREE
#define ALGOR_BINARY_TREE

#include <stdbool.h>

// Node ID type
typedef unsigned algor_node;
#define ALGOR_ROOT ((algor_node) 0)

// Tree Structure
struct algor_tree {
	// User provided functions
	// To string, memory will be freed by algor
	char* (*string)(void*);
	// Comparison, should be true if A > B, default is to compare pointers
	bool (*compare)(void*, void*);
	// Free, default is to just call stdlib free on all values
	void (*free)(void*);
	// Tree Capacity
	unsigned capacity;
	// Tree Max Node
	algor_node max;
	// Node Values
	void* nodes[];
};

// Constructor
struct algor_tree* algor_create_root(unsigned capacity, void* value);
// Constructor from an array
struct algor_tree* algor_create_tree(unsigned nodes, void** values);
// Recursive Destructor
void algor_destroy_node(struct algor_tree* tree, algor_node node);
// Free Tree
void algor_free_tree(struct algor_tree* tree);
// Free Node
void algor_free_node(struct algor_tree* tree, algor_node node);
// Compare Node Values, true if node > value
bool algor_compare_node(struct algor_tree* tree, algor_node node, void* value);

// Set Node
void algor_set_node(struct algor_tree* tree, algor_node node, void* value);

// To String
char* algor_node_string(struct algor_tree* tree, algor_node node);
void algor_tree_print(struct algor_tree* tree, algor_node root);

// References
algor_node algor_left_node(algor_node node);
algor_node algor_right_node(algor_node node);
algor_node algor_parent_node(algor_node node);

// Boolean checks
bool algor_node_leaf(struct algor_tree* tree, algor_node node);
bool algor_node_full(struct algor_tree* tree, algor_node node);
bool algor_node_left(struct algor_tree* tree, algor_node node);
bool algor_node_right(struct algor_tree* tree, algor_node node);

#endif

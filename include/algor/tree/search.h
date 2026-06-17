// Binary Search Tree

#ifndef ALGOR_BINARY_SEARCH
#define ALGOR_BINARY_SEARCH

#include <algor/tree/binary.h>

// Create new BST
struct algor_tree* algor_bst_create(unsigned capacity, bool (*compare)(void*, void*));
// Add Value to BST
void algor_bst_add(struct algor_tree* tree, void* value);
// Remove Node from BST
void algor_bst_remove(struct algor_tree* tree, algor_node node);
// Find Node in BST
algor_node algor_bst_find(struct algor_tree* tree, void* value);

#endif

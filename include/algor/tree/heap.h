// Min-Max Heap

#ifndef ALGOR_MINMAX_HEAP
#define ALGOR_MINMAX_HEAP

#include <algor/tree/binary.h>

// Constructor
struct algor_tree* algor_create_heap(unsigned capacity, void* value, bool (*compare)(void*, void*));

// Add Nodes
void algor_min_heap_add(struct algor_tree* heap, void* value);
void algor_max_heap_add(struct algor_tree* heap, void* value);

// Remove Nodes
void algor_min_heap_remove(struct algor_tree* heap, algor_node node);
void algor_max_heap_remove(struct algor_tree* heap, algor_node node);

#endif

// Min-Max Heap Implementation

#include <stddef.h>
#include <algor/tree/heap.h>

// Constructor
struct algor_tree* algor_create_heap(unsigned capacity, void* value, bool (*compare)(void*, void*)) {
	struct algor_tree* heap = algor_create_root(capacity, value);
	if (heap == NULL)
		return NULL;
	heap->compare = compare;
	heap->max = ALGOR_ROOT;
	return heap;
}

// Add Nodes
void algor_min_heap_add(struct algor_tree* heap, void* value) {
	// Insert at end
	algor_node node = heap->max++;
	algor_set_node(heap, node, value);
	// Heap up
	while (node > 0 && algor_compare_node(heap, algor_parent_node(node), value)) {
		heap->nodes[node] = heap->nodes[algor_parent_node(node)];
		node = algor_parent_node(node);
		heap->nodes[node] = value;
	}
}

void algor_max_heap_add(struct algor_tree* heap, void* value) {
	// Insert at end
	algor_node node = heap->max++;
	algor_set_node(heap, node, value);
	// Heap up
	while (node> 0 && algor_compare_node(heap, node, heap->nodes[algor_parent_node(node)])) {
		heap->nodes[node] = heap->nodes[algor_parent_node(node)];
		node = algor_parent_node(node);
		heap->nodes[node] = value;
	}
}

// Remove Nodes
void algor_min_heap_remove(struct algor_tree* heap, algor_node node) {
	// Free and replace with max ID node
	algor_free_node(heap, node);
	heap->nodes[node] = heap->nodes[--heap->max];
	heap->nodes[heap->max] = NULL;
	// Heap down
	while (algor_compare_node(heap, node, heap->nodes[algor_left_node(node)]) || algor_compare_node(heap, node, heap->nodes[algor_right_node(node)])) {
		if (!algor_compare_node(heap, algor_left_node(node), heap->nodes[algor_right_node(node)])) {
			void* value = heap->nodes[node];
			heap->nodes[node] = heap->nodes[algor_left_node(node)];
			node = algor_left_node(node);
			heap->nodes[node] = value;
		}
		else {
			void* value = heap->nodes[node];
			heap->nodes[node] = heap->nodes[algor_right_node(node)];
			node = algor_right_node(node);
			heap->nodes[node] = value;
		}
	}
}

void algor_max_heap_remove(struct algor_tree* heap, algor_node node) {
	// Free and replace with max ID node
	algor_free_node(heap, node);
	heap->nodes[node] = heap->nodes[--heap->max];
	heap->nodes[heap->max] = NULL;
	// Heap down
	while (algor_compare_node(heap, algor_left_node(node), heap->nodes[node]) || algor_compare_node(heap, algor_right_node(node), heap->nodes[node])) {
		if (algor_compare_node(heap, algor_right_node(node), heap->nodes[algor_right_node(node)])) {
			void* value = heap->nodes[node];
			heap->nodes[node] = heap->nodes[algor_left_node(node)];
			node = algor_left_node(node);
			heap->nodes[node] = value;
		}
		else {
			void* value = heap->nodes[node];
			heap->nodes[node] = heap->nodes[algor_right_node(node)];
			node = algor_right_node(node);
			heap->nodes[node] = value;
		}
	}
}

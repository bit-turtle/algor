// Min Max Heap Tests

#include "test.h"
#include <algor/tree/heap.h>

bool minheap() {
	struct algor_tree* heap = algor_create_heap(1000, newint(3), compareint);
	if (heap == NULL)
		return false;
	algor_min_heap_add(heap, newint(5));
	algor_min_heap_add(heap, newint(4));
	algor_min_heap_add(heap, newint(1));
	algor_min_heap_add(heap, newint(2));
	algor_min_heap_add(heap, newint(0));
	bool check = *(int*)heap->nodes[ALGOR_ROOT] == 0;
	algor_free_tree(heap);
	return check;
}


bool maxheap() {
	struct algor_tree* heap = algor_create_heap(1000, newint(3), compareint);
	if (heap == NULL)
		return false;
	algor_max_heap_add(heap, newint(4));
	algor_max_heap_add(heap, newint(1));
	algor_max_heap_add(heap, newint(5));
	algor_max_heap_add(heap, newint(2));
	algor_max_heap_add(heap, newint(0));
	bool check = *(int*)heap->nodes[ALGOR_ROOT] == 5;
	algor_free_tree(heap);
	return check;
}


bool minheaprem() {
	struct algor_tree* heap = algor_create_heap(1000, newint(3), compareint);
	if (heap == NULL)
		return false;
	algor_min_heap_add(heap, newint(5));
	algor_min_heap_add(heap, newint(4));
	algor_min_heap_add(heap, newint(1));
	algor_min_heap_add(heap, newint(2));
	algor_min_heap_add(heap, newint(0));
	algor_min_heap_remove(heap, ALGOR_ROOT);
	bool check = *(int*)heap->nodes[ALGOR_ROOT] == 1;
	algor_free_tree(heap);
	return check;
}


bool maxheaprem() {
	struct algor_tree* heap = algor_create_heap(1000, newint(3), compareint);
	if (heap == NULL)
		return false;
	algor_max_heap_add(heap, newint(4));
	algor_max_heap_add(heap, newint(1));
	algor_max_heap_add(heap, newint(5));
	algor_max_heap_add(heap, newint(2));
	algor_max_heap_add(heap, newint(0));
	algor_max_heap_remove(heap, ALGOR_ROOT);
	bool check = *(int*)heap->nodes[ALGOR_ROOT] == 4;
	algor_free_tree(heap);
	return check;
}

void heap() {
	test("Min Heap Addition", minheap());
	test("Max Heap Addition", maxheap());
	test("Min Heap Removal", minheaprem());
	test("Max Heap Removal", maxheaprem());
}

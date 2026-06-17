// Binary Tree Test

#include "test.h"

#include <algor/tree/binary.h>

bool constructor() {
	struct algor_tree* tree = algor_create_root(128, newint(0));
	if (tree == NULL)
		return false;
	algor_set_node(tree, algor_left_node(ALGOR_ROOT), newint(10));
	bool fail = *(int*)tree->nodes[0] != 0 && *(int*)tree->nodes[1] != 10;
	algor_free_tree(tree);
	return !fail;
}

bool arrayconstructor() {
	int* array[] = { newint(5), newint(2), newint(9), newint(3), NULL, NULL, newint(100) };
	struct algor_tree* tree = algor_create_tree(7, (void**)array);
	bool success = *(int*)tree->nodes[6] == 100 && algor_node_full(tree, ALGOR_ROOT);
	algor_free_tree(tree);
	return success;
}

void binary() {
	test("Tree Constructor", constructor());
	test("Tree Array Constructor", arrayconstructor());
}

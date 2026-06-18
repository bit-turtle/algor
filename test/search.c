// Binary Search Tree Tests

#include "test.h"
#include <algor/tree/search.h>

bool adding() {
	struct algor_tree* tree = algor_bst_create(20, compareint);
	algor_bst_add(tree, newint(8));
	algor_bst_add(tree, newint(19));
	algor_bst_add(tree, newint(3));
	algor_bst_add(tree, newint (17));
	bool check = *(int*)tree->nodes[algor_left_node(algor_right_node(ALGOR_ROOT))] == 17;
	algor_free_tree(tree);
	return check;
}

bool removing() {
	struct algor_tree* tree = algor_bst_create(100, compareint);
	algor_bst_add(tree, newint(5));
	algor_bst_add(tree, newint(0));
	algor_bst_add(tree, newint(2));
	algor_bst_add(tree, newint(1));
	algor_bst_add(tree, newint(3));
	algor_bst_add(tree, newint(-1));
	algor_bst_remove(tree, algor_left_node(ALGOR_ROOT));
	bool check = *(int*)tree->nodes[algor_left_node(ALGOR_ROOT)] == 1;
	algor_free_tree(tree);
	return check;
}

bool searching() {
	struct algor_tree* tree = algor_bst_create(200, compareint);
	algor_bst_add(tree, newint(5));	//         
	algor_bst_add(tree, newint(1));	//     1 --|   2
	algor_bst_add(tree, newint(3));	// 5 --|   3 --|
	algor_bst_add(tree, newint(2));	//             4
	algor_bst_add(tree, newint(4));	// 5(1[3(2)[4]])
	int fourint = 4;
	algor_node four = algor_bst_find(tree, &fourint);
	bool check = algor_right_node(algor_right_node(algor_left_node(ALGOR_ROOT))) == four;
	if (!check) {
		printf("Incorrect Node ID: %u (Expected %u)\n", four, algor_right_node(algor_right_node(algor_left_node(ALGOR_ROOT))));
		tree->string = stringint;
		algor_tree_print(tree, ALGOR_ROOT);
		printf("\n");
	}
	algor_free_tree(tree);
	return check;
}

void search() {
	test("BST Addition", adding());
	test("BST Removal", removing());
	test("BST Search", searching());
}

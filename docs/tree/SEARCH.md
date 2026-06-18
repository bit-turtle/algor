# Binary Search Tree
Functions related to binary search trees
## `<algor/tree/search.h>`

### Structure
Uses the [`algor_tree`](BINARY.md) structure defined in `<algor/tree/binary.h>`

### Functions
- `struct algor_tree* algor_bst_create(unsigned capacity, bool (*compare)(void*, void*))`
  - Creates a binary tree and sets the comparison function
- `void algor_bst_add(struct algor_tree* tree, void* value)`
  - Add a node to the binary search tree
- `void algor_bst_remove(struct algor_tree* tree, algor_node node)`
  - Removes a node from a binary search tree
- `algor_node algor_bst_find(struct algor_tree* tree, void* value)`
  - Finds a node in the binary search tree and returns the ID, returns `algor_tree.capacity` if not present

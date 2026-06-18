# Binary Tree Structure
The structure and functions for making and manipulating a binary tree
## `<algor/tree/binary.h>`

### Node ID Type `typedef unsigned algor_node`
All node IDs are referred to as an `algor_node`, it's just an unsigned integer

### Structure `struct algor_tree`
- Base Members
  - `unsigned capacity`: Capacity of node array
  - `void* nodes[]`: Pointer to the values of the nodes, NULL if the node doesn't exist
- Additional Members
  - `algor_node max`: ID of maximum non-null node, only used by the heap functions
    - Should not be used, for internal use only
- User Provided Function Pointers
  - `char* (*string)(void* value)`: Allocates and outputs a string representation of the value started in the void*
    - Default behavior is to output the hex of the pointer in the format `0x123ABC...`
  - `bool (*compare)(void* A, void* B)`: Compares two values and outputs true if A > B
    - Default behavior is to compare the two pointers as integers
  - `void (*free)(void*)`: Free value function
    - Default behavior is to use the standard stdlib free

### Functions
- Constructors
  - `struct algor_tree* algor_create_root(unsigned capacity, void* value)`
    - Allocate a tree of a certain capacity and set the value of the root node
  - `struct algor_tree* algor_create_tree(unsigned nodes, void** values)`
    - Create a tree from an array of pointers to values
    - The length of the array is passed into `nodes`
- Destuctors
  - `void algor_destroy_node(struct algor_tree* tree, algor_node node)`
    - Recursively frees a node using `algor_free_node` and all of it's subnodes
  - `void algor_free_tree(struct algor_tree* tree)`
    - Frees all node values and then frees the `algor_tree`
- Setters and Getters
  - `void algor_set_node(struct algor_tree* tree, algor_node node, void* value)`
    - Safe version of writing to `algor_tree.nodes`, checks capacity first
  - `void* algor_get_node(struct algor_tree* tree, algor_node node)`
    - Safe version of reading from `algor_tree.nodes`, checks capacity first
- User Provided Functions with Fallbacks
  - `void algor_free_node(struct algor_tree* tree, algor_node node)`
    - Frees a node and sets it's value to NULL,using the user provided function if available
  - `bool algor_compare_node(struct algor_tree* tree, algor_node node, void* value)`
    - Compares the value of a node to a value, using the user provided function in `algor_tree`, falling back to pointer comparison if it isn't available
  - `char* algor_node_string(struct algor_tree* tree, algor_node node)`
    - Returns a string representing the value of the node, falling back to outputing a hax string of the pointer if the user provided function isn't available
  - `void algor_tree_print(struct algor_tree* tree, algor_node root)`
    - Recursively prints the entire tree from a certain node using `algor_node_string`
- References
  - `algor_node algor_left_node(algor_node node)`
    - Returns the ID of the left node
  - `algor_node algor_right_node(algor_node node)`
    - Returns the ID of the right node
  - `algor_node algor_parent_node(algor_node node)`
    - Returns the ID of the parent node
- Boolean
  - `bool algor_node_leaf(struct algor_tree* tree, algor_node node)`
    - Returns true if the node is a leaf
  - `bool algor_node_full(struct algor_tree* tree, algor_node node)`
    - Returns true if the node has two childen
  - `bool algor_node_left(struct algor_tree* tree, algor_node node)`
    - Returns true if the node has a left child
  - `bool algor_node_right(struct algor_tree* tree, algor_node node)`
    - Returns true if the node has a right child


# Binary Min or Max Heaps
Binary min and max heaps made with binary trees
## `<algor/tree/heap.h>`

### Structure
Uses the [`algor_tree`](BINARY.md) structure defined in `<algor/tree/binary.h>`

### Functions
- Constructor
  - `struct algor_tree* algor_create_heap(unsigned capacity, void* value, bool (*compare)(void*, void*))`
    - Create a heap binary tree with a set capacity and a user provided comparison function
- Add Nodes
  - `void algor_min_heap_add(struct algor_tree* heap, void* value)`
    - Add a node to a min heap
  - `void algor_max_heap_add(struct algor_tree* heap, void* value)`
    - Add a node t a max heap
- Remove Nodes
  - `void algor_min_heap_remove(struct algor_tree* heap, algor_node node)`
    - Remove a node from a min heap
  - `void algor_max_heap_remove(struct algor_tree* heap, algor_node node)`
    - Remove a node from a max heap

## Max heap
___

    - The tree is complete or nearly complete.
    - The key value of each node >=  value all node in subtrees.

## Basic algorithm
___

- ReheapUp O(log2 n):
    - Floating last element up the tree until correctly.
- ReheapDown O(log2 n):
    - Pushing the root down the tree until correctly.

## Properties
___
    - A complete or nearly complete binary tree.
    - If the height is h, number node is [2^(h-1);2^h-1].
    - Complete: N = 2^h -1 , last level is full.
    - Nearly: All nodes in last level are on left.
    - Can be presented by array. up->down; left->right
- Relative node & its children when be presented by array.
    - Node (index i) => leftchild (2i+1) + rightChild (2i+2).
    - Parent of (node has index i) : located at floor((i-1)/2) index.
    - Give size N of complete heap. Location of first leaft at floor(N/2);

## Heap operators
___
### Build Heap O(n)

Give array -> build.
    
    - Start from last node non-leaf -> root;
    - Each node: we compare it to its children and change location if it not true for heap tree -> reheap down 
    - Until to root. 
  
### Insert O(log2 n)
    - Add to the last array.
    - ReheapUp that element until correctly.

### Delete O(log2 n)
    - Delete the root
    - Pushing last element in array to the top.
    - ReheapDown root.

## Heap sort O(log2 n)
    - Delete root(max value) -> get into new array;
    - until heap empty. get new array sorted.

## Selection algorithm O(n * log2 n).
Finding smallest number or largest .

## Priority Queues
Build heap => level of node is priority number.
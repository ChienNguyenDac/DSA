## Insert, find, delete : O(log n)

## M-Way Seach Tree
___
    - Each node has 0-m subtrees.
    - A node with k < m subtrees contains k subtrees & k-1 entries.
    - The key values in subtrees all greater than or equal to the key of the left data entry & less than key of the right entry.
    - The keys of the data entries are ordered.
    - All subtrees are themselves multiway trees.

## B-Tree
___
B-tree is a multiway tree with the following additional properties(m>=3)

    - The root either a leaf or it ( root & leaf ) has [2;m] subtrees.
    - All internal node has [ceil(m/2);m] non-null subtrees.
    - All other node has [ceil(m/2)-1;m-1]  entries.
    - All leaf nodes are same level.
 
### Insert new node into B-tree

    - Try to insert new node into B-tree
    - If that leaf more than m-1 entries~overflow split the leaf into 2, choose middle key to leaf's parent.
    - Try Step2 until have no leaf overflow.
  
### Delete a node from B-tree
    - Left < node, right >= node
    - If key in leaf , just remove it
    - If is not leaf, just delete key, and promote the predecessor (largest on the left) or successor (smallest on the right) key to the non-leaf deletedkey’s position. 
    - If case1 & case2, contain less than minimum numbers of key then:
      + Borrow: If one of them has more than the min. number of keys, promote one of its keys to the parent and take the parent key into our lacking leaf.
      + Combine: : If neither of them has more than the min. Number of keys then the lacking leaf and one of its neighbours can be combined with their shared parent entry and the new leaf will have the correct number of keys
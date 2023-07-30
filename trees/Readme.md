### Trees

## Why trees?

//write this

`Some applications of binary trees`

1. Expression trees are used in compilers.
2. Huffman coding trees that are used in data search algorithms.
3. Binary search tree which supports search,insertion and deletion on a collection of items in O(log n) time complexity(average)
4. Priority Queue which supports search and deletion of minimum or maximum on a collection of items in logarithmic time(worst case)

# Declaration

`~ using C to implement this`

```C
//using struct keyword to implement new data type
struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

```

# Operations performable on trees

1. Basic Operations
   a. Insertion
   b. Deletion
   c. Searching
   d. Traversing

2. Auxiliary
   a. Finding size of the tree
   b. Height of the tree
   c. Level which has maximum sum
   d. Least common ancestor(LCA)

## Traversal in Binary trees

# Possibilities

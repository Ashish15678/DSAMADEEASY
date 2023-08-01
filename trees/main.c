#include <stdio.h>
#include <stdlib.h>
#include "functions.h";
// globals

// declaration of binaryTreeNode
struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

void recursivePreOrderTraversal(struct BinaryTreeNode *root)
{
    if (root)
    {
        printf("%d", root->data);
        recursivePreOrderTraversal(root->left);
        recursivePreOrderTraversal(root->right);
    }
}

void nonRecursivePreOrderTraversal(struct BinaryTreeNode *root)
{
}

// main
int main()
{

    return 0;
}

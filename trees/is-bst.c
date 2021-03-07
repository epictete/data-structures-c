#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}
Node;

// Not used in final version of this algorithm.
// It is just there for reference.
int IsSubtreeLesser(Node* root, int value)
{
    if (root == NULL) return 1;

    if (root->data <= value
        && IsSubtreeLesser(root->left, value)
        && IsSubtreeLesser(root->right, value)) return 1;
    else return 0;
}

// Not used in final version of this algorithm.
// It is just there for reference.
int IsSubtreeGreater(Node* root, int value)
{
    if (root == NULL) return 1;

    if (root->data > value
        && IsSubtreeGreater(root->left, value)
        && IsSubtreeGreater(root->right, value)) return 1;
    else return 0;
}

int IsBST(Node* root, int minValue, int maxValue)
{
    if (root == NULL) return 1;

//    Initial version : O(n²)

    /*
    if (IsSubtreeLesser(root->left, root->data)
        && IsSubtreeGreater(root->right, root->data)
        && IsBST(root->left, minValue, root->data)
        && IsBST(root->right, root->data, maxValue))
        return 1;
    */

//    Optimized version : O(n)

    if (root->data > minValue
        && root->data <= maxValue
        && IsBST(root->left, minValue, root->data)
        && IsBST(root->right, root->data, maxValue))
        return 1;
    else
        return 0;
}

Node* GetNewNode(int data)
{
    Node* newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node* Insert(Node* root, int data)
{
    if (root == NULL)
        root =  GetNewNode(data);
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

int main(void)
{
    Node* root = NULL;

    root = Insert(root, 7);
    root = Insert(root, 4);
    root = Insert(root, 9);
    root = Insert(root, 1);
    root = Insert(root, 6);

    if (IsBST(root, INT_MIN, INT_MAX))
        printf("This tree is a BST\n");
    else
        (printf("This tree is NOT a BST\n"));

    return 0;
}
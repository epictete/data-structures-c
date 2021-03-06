#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}
Node;

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

int Max(int a, int b)
{
    return (a >= b) ? a : b;
}

int FindHeight(Node* root)
{
    if (root == NULL) return -1;

    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);

    return Max(leftHeight, rightHeight) + 1;
}

int main(void)
{
    Node* root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 17);
    root = Insert(root, 5);

    printf("Height of tree : %d\n", FindHeight(root));

    return 0;
}
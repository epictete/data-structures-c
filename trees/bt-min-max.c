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

int FindMin(Node* root) // Iterative approach
{
    if (root == NULL)
    {
        printf("Error : tree is empty\n");
        return -1;
    }

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int FindMax(Node* root) // Recursive approach
{
    if (root == NULL)
    {
        printf("Error : tree is empty\n");
        return -1;
    }

    if (root->right == NULL)
        return root->data;

    return FindMax(root->right);
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

    printf("Minimum : %d\n", FindMin(root));
    printf("Maximum : %d\n", FindMax(root));

    return 0;
}
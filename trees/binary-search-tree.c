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
    Node* newNode = (Node*)malloc(sizeof(Node));

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

int Search(Node* root, int data)
{
    if (root == NULL) return 0;
    else if (root->data == data) return 1;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
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

    int number;

    printf("Enter the number to be searched : ");
    scanf("%d", &number);

    if (Search(root, number)) printf("Found\n");
    else printf("Not Found\n");

    return 0;
}
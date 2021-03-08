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

Node* Find(Node* root, int data)
{
    if (root == NULL) return NULL;
    else if (root->data == data) return root;
    else if (data < root->data) return Find(root->left, data);
    else return Find(root->right, data);
}

Node* FindMin(Node* root)
{
    if (root == NULL)
    {
        printf("Error : tree is empty\n");
        exit(1);
    }

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* GetSuccessor(Node* root, int data)
{
    Node* current = Find(root, data);

    if (current == NULL) return NULL;

    if (current->right != NULL) return FindMin(current->right);
    else
    {
        Node* successor = NULL;
        Node* ancestor = root;

        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right;
        }

        return successor;
    }
}

int main(void)
{
    Node* root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 12);
    root = Insert(root, 17);
    root = Insert(root, 25);
    root = Insert(root, 6);
    root = Insert(root, 11);
    root = Insert(root, 16);
    root = Insert(root, 27);

    Node* successor = GetSuccessor(root, 15);

    printf("In order successor : %d\n", successor->data);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
}
Node;

Node* GetNewNode(char data)
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

Node* Insert(Node* root, char data)
{
    if (root == NULL)
        root =  GetNewNode(data);
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

void Preorder(Node* root)
{
    if (root == NULL) return;

    printf("%c ", root->data);

    Preorder(root->left);
    Preorder(root->right);
}

void InOrder(Node* root)
{
    if (root == NULL) return;

    InOrder(root->left);

    printf("%c ", root->data);

    InOrder(root->right);
}

void PostOrder(Node* root)
{
    if (root == NULL) return;

    PostOrder(root->left);
    PostOrder(root->right);

    printf("%c ", root->data);
}

int main(void)
{
    Node* root = NULL;

    root = Insert(root, 'F');
    root = Insert(root, 'D');
    root = Insert(root, 'J');
    root = Insert(root, 'B');
    root = Insert(root, 'E');
    root = Insert(root, 'G');
    root = Insert(root, 'K');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    root = Insert(root, 'H');
    root = Insert(root, 'I');

    printf("Preorder Traversal :\n");
    Preorder(root);
    printf("\n");

    printf("Inorder Traversal :\n");
    InOrder(root);
    printf("\n");

    printf("Postorder Traversal :\n");
    PostOrder(root);
    printf("\n");

    return 0;
}
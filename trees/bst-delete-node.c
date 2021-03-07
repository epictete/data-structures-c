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

void InOrder(Node* root)
{
    if (root == NULL) return;

    InOrder(root->left);

    printf("%d ", root->data);

    InOrder(root->right);
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

Node* Delete(Node* root, int data)
{
    if (root == NULL) return root;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            Node* temp = FindMin(root);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main(void) {
    Node *root = NULL;

    root = Insert(root, 12);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 13);
    root = Insert(root, 17);
    root = Insert(root, 1);
    root = Insert(root, 9);

    printf("Original tree : ");
    InOrder(root);
    printf("\n");

    Delete(root, 15);

    printf("Tree after deletion : ");
    InOrder(root);
    printf("\n");

    return 0;
}
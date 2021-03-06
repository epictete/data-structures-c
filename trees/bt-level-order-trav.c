#include <stdio.h>
#include <stdlib.h>

// Node types definition

typedef struct BtNode
{
    char data;
    struct BtNode* left;
    struct BtNode* right;
}
BtNode;

typedef struct QNode
{
    BtNode* data;
    struct QNode* next;
}
QNode;

// Queue logic

QNode* front = NULL;
QNode* rear = NULL;

int IsEmpty(void)
{
    return front == NULL && rear == NULL;
}

void Enqueue(BtNode* x)
{
    QNode* temp = malloc(sizeof(QNode));

    if (temp == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    temp->data = x;
    temp->next = NULL;

    if (IsEmpty())
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void Dequeue(void)
{
    QNode* temp = front;

    if (IsEmpty()) return;
    else if (front == rear) front = rear = NULL;
    else front = front->next;

    free(temp);
}

BtNode* Front(void)
{
    if (IsEmpty())
    {
        printf("Error : queue is empty\n");
        exit(1);
    }

    return front->data;
}

// Binary Tree logic

BtNode* GetNewNode(char data)
{
    BtNode* newNode = malloc(sizeof(BtNode));

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

BtNode* Insert(BtNode* root, char data)
{
    if (root == NULL)
        root =  GetNewNode(data);
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

void LevelOrder(BtNode* root)
{
    if (root == NULL) return;

    Enqueue(root);

    while (!IsEmpty())
    {
        BtNode* current = Front();

        printf("%c ", current->data);

        if (current->left != NULL) Enqueue(current->left);
        if (current->right != NULL) Enqueue(current->right);

        Dequeue();
    }
}

// Main program

int main(void)
{
    BtNode* root = NULL;

    root = Insert(root, 'F');
    root = Insert(root, 'D');
    root = Insert(root, 'J');
    root = Insert(root, 'B');
    root = Insert(root, 'E');
    root = Insert(root, 'G');
    root = Insert(root, 'K');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    root = Insert(root, 'I');
    root = Insert(root, 'H');

    LevelOrder(root);

    return 0;
}
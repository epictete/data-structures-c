#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
}
Node;

Node* head;

Node* GetNewNode(int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode != NULL)
    {
        newNode->data = x;
        newNode->prev = NULL;
        newNode->next = NULL;
    }

    return newNode;
}

void InsertAtHead(int x)
{
    Node* newNode = GetNewNode(x);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int x)
{
    Node* newNode = GetNewNode(x);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* cursor = head;

    while (cursor->next != NULL)
        cursor = cursor->next;

    cursor->next = newNode;
    newNode->prev = cursor;
}

void Print(void)
{
    Node* cursor = head;

    printf("Forward:\t[ ");

    while (cursor != NULL)
    {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }

    printf("]\n");
}

void ReversePrint(void)
{
    Node* cursor = head;

    if (cursor == NULL) return;

    while (cursor->next != NULL)
        cursor = cursor->next;

    printf("Backward:\t[ ");

    while (cursor != NULL)
    {
        printf("%d ", cursor->data);
        cursor = cursor->prev;
    }

    printf("]\n");
}

int main (void)
{
    head = NULL;

    for (int i = 8; i > 0; i = i - 2)
        InsertAtHead(i);

    Print();

    printf("Insert 10 at tail and print in reverse\n");
    InsertAtTail(10);
    ReversePrint();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}
Node;

Node* head;

void Insert(int x)
{
    Node* temp = malloc(sizeof(Node));

    if (temp == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print(void)
{
    Node* cursor = head;

    printf("[ ");

    while (cursor != NULL)
    {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }

    printf("]\n");
}

void Reverse(Node* p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }

    Reverse(p->next);

    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

int main(void)
{
    head = NULL;

    for (int i = 1; i <= 5;i++)
        Insert(i);

    printf("Original list : ");
    Print();

    printf("Reversed list : ");
    Reverse(head);
    Print();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* head;

void Insert(int x)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp != NULL)
    {
        temp->data = x;
        temp->next = head;
        head = temp;
    }
}

void Print()
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
    for (int i = 1; i <= 5;i++) Insert(i);
    printf("Original list : ");
    Print();
    Reverse(head);
    printf("Reversed list : ");
    Print();
    return 0;
}
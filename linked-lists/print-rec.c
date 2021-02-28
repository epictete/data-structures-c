#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}
Node;

void Print(Node* p)
{
    if (p == NULL) return;

    printf("%d ", p->data);

    Print(p->next);
}

void ReversePrint(Node* p)
{
    if (p == NULL) return;

    ReversePrint(p->next);

    printf("%d ", p->data);
}

Node* Insert(Node* head, int x)
{
    Node* temp = (Node*)malloc(sizeof(Node));

    if (temp != NULL)
    {
        temp->data = x;
        temp->next = head;
        head = temp;
    }

    return head;
}

int main(void)
{
    Node* head = NULL;

    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    ReversePrint(head);

    printf("\n");

    return 0;
}
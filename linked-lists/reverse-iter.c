#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}
Node;

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

void Print(Node* head)
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

Node* Reverse(Node* head)
{
    Node* prev;
    Node* current;
    Node* next;

    prev = NULL;
    current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    return head;
}

int main(void)
{
    Node* head = NULL;

    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);

    printf("Original list : ");
    Print(head);

    printf("Reversed list : ");
    head = Reverse(head);
    Print(head);

    return 0;
}
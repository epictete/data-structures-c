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
    Node* temp = (Node*)malloc(sizeof(Node));

    if (temp != NULL)
    {
        temp->data = x;
        temp->next = head;
        head = temp;
    }
}

void Print(void)
{
    Node* current = head;

    printf("List is: [ ");

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("]\n");
}

void Delete(int n)
{
    if (n < 1)
    {
        printf("Invalid position\n");
        return;
    }

    Node* prev = head;

    if (n == 1)
    {
        head = head->next;
        free(prev);
        return;
    }

    for (int i = 0; i < n - 2; i++)
    {
        if (prev->next->next == NULL)
        {
            printf("Invalid position\n");
            return;
        }

        prev = prev->next;
    }

    Node* current = prev->next;
    prev->next = current->next;

    free(current);
}

int main(void)
{
    head = NULL;

    for (int i = 8; i > 0; i -= 2)
        Insert(i);

    Print();

    int n;
    printf("Enter a position: ");
    scanf("%d", &n);

    Delete(n);
    Print();

    return 0;
}
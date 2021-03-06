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
    Node* current = head;

    printf("List is: [ ");

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("]\n");
}

void Delete(int x)
{
    Node* prev = head;

    while(prev->next != NULL)
    {
        if (head->data == x)
        {
            head = head->next;
            free(prev);
            return;
        }

        if (prev->next->data == x)
        {
            Node* current = prev->next;
            prev->next = current->next;
            free(current);
            return;
        }

        prev = prev->next;
    }

    printf("Not Found\n");
}

int main(void)
{
    head = NULL;

    for (int i = 8; i > 0; i -= 2)
        Insert(i);

    Print();

    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    Delete(x);
    Print();

    return 0;
}
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
}
Node;

Node* head;

void Print(void)
{
    Node* cursor = head;

    printf("List: [ ");

    while (cursor != NULL)
    {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }

    printf("]\n");
}

void Insert(int x, int n)
{
    Node* temp = (Node*)malloc(sizeof(Node));

    if (temp != NULL)
    {
        temp->data = x;
        temp->next = NULL;

        if (n == 1)
        {
            temp->next = head;
            head = temp;
            return;
        }
        else
        {
            Node* cursor = head;

            for (int i = 0; i < n - 2; i++)
                cursor = cursor->next;

            temp->next = cursor->next;
            cursor->next = temp;
        }
    }
}

int main(void)
{
    head = NULL;

    Insert(2, 1);
    Insert(3, 2);
    Insert(4, 1);
    Insert(5, 2);
    Print();

    return 0;
}
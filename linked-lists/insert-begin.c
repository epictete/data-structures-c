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
void Print(void)
{
    Node* cursor = head;
    printf("List is: [ ");
    while (cursor != NULL)
    {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
    printf("]\n");
}

int main(void)
{
    head = NULL;
    printf("How many numbers? ");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number: ");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
    return 0;
}
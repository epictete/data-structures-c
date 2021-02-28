#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}
Node;

Node* front = NULL;
Node* rear = NULL;

int IsEmpty(void)
{
    if (front == NULL && rear == NULL) return 1;
    else return 0;
}

void Enqueue(int x)
{
    Node* temp = (Node*)malloc(sizeof(Node));

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
    Node* temp = front;

    if (IsEmpty()) return;
    else if (front == rear) front = rear = NULL;
    else front = front->next;

    free(temp);
}

int Front(void)
{
    if (IsEmpty())
    {
        printf("Error : queue is empty\n");
        return -1;
    }

    return front->data;
}

void Print(void)
{
    Node* temp = front;

    printf("Queue : [ ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("]\n");
}

int main(void)
{
    Enqueue(2); Print();
    Enqueue(4); Print();
    Enqueue(6); Print();
    Dequeue(); Print();
    Enqueue(8); Print();

    printf("Front : %d\n", Front());

    return 0;
}
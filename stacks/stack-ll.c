//
// Created by john on 2/20/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
}
Node;

void Print(Node* top)
{
    if (top == NULL)
    {
        return;
    }
    Print(top->link);
    printf("%d ", top->data);
}

void pPrint(Node* top)
{
    printf("Stack : ");
    Print(top);
    printf("\n");
}

Node* Push(Node* top, int x)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp != NULL)
    {
        temp->data = x;
        temp->link = top;
        top = temp;
    }
    pPrint(top);
    return top;
}

Node* Pop(Node* top)
{
    if (top == NULL) return top;
    Node* temp = top;
    top = top->link;
    free(temp);
    pPrint(top);
    return top;
}

int Top(Node* top)
{
    printf("Top: %d\n", top->data);
    return top->data;
}

int IsEmpty(Node* top)
{
    printf("Empty: ");
    if (top == NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}

int main(void)
{
    Node* top = NULL;
    top = Push(top, 2);
    top = Push(top, 4);
    top = Push(top, 5);
    Top(top);
    top = Pop(top);
    Top(top);
    top = Pop(top);
    top = Pop(top);
    IsEmpty(top);
    return 0;
}
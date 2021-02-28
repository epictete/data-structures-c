#include <stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Print()
{
    printf("Stack: ");

    for (int i = 0; i <= top; i++)
        printf("%d ", A[i]);

    printf("\n");
}

void Push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Error: Stack overflow\n");
        return;
    }

    A[++top] = x;
    Print();
}

void Pop(void)
{
    if (top == -1)
    {
        printf("Error: Stack is empty\n");
        return;
    }

    top--;
    Print();
}

int Top(void)
{
    printf("Top: %d\n", A[top]);
    return A[top];
}

int IsEmpty(void)
{
    printf("Empty: ");

    if (top == -1)
    {
        printf("True\n");
        return 1;
    }

    printf("False\n");

    return 0;
}

int main(void )
{
    Push(2);
    Push(5);
    Push(10);
    Pop();
    Push(12);
    Top();
    IsEmpty();
    Pop();
    Pop();
    Pop();
    IsEmpty();

    return 0;
}
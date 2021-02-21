#include <stdio.h>
#include <string.h>
#define MAX_SIZE 101

char A[MAX_SIZE];
int top = -1;

int IsEmpty()
{
    if (top == -1) return 1;
    return 0;
}

void Push(char c)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Error: Stack overflow\n");
        return;
    }
    A[++top] = c;
}

char Top()
{
    return A[top];
}

void Pop()
{
    if (IsEmpty())
    {
        printf("Error: Stack is empty\n");
        return;
    }
    top--;
}

void Reverse(char C[], int n)
{
    for (int i = 0; i < n; i++) Push(C[i]);
    for (int i = 0; i < n; i++)
    {
        C[i] = Top();
        Pop();
    }
}

int main(void)
{
    char C[51];
    printf("Enter a string\t:");
    scanf("%s", C);
    Reverse(C, strlen(C));
    printf("Reversed\t:%s", C);
    printf("\n");
    return 0;
}
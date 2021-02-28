#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

char A[MAX_SIZE];
int top = -1;

void Push(char c)
{
    if (top == MAX_SIZE - 1) return;
    A[++top] = c;
}

void Pop(void)
{
    if (top == -1) return;
    top--;
}

char Top(void)
{
    return A[top];
}

int IsEmpty(void)
{
    return top == -1;
}

int IsPair(char c)
{
    if (c == ')' && Top() == '(') return 1;
    if (c == '}' && Top() == '{') return 1;
    if (c == ']' && Top() == '[') return 1;
    return 0;
}

int IsBalanced(char exp[])
{
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            Push(exp[i]);

        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (IsEmpty() || !IsPair(exp[i])) return 0;
            Pop();
        }
    }

    return IsEmpty();
}

int main(void)
{
    char exp[51];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (IsBalanced(exp)) printf("Balanced\n");
    else printf("Not balanced\n");

    return 0;
}
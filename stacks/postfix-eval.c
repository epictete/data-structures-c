/*
 * Requires expression as input where each value
 * is separated by a character (like ',' or ';' for example).
 */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

int IsEmpty()
{
    if (top == -1) return 1;
    return 0;
}

void Push(char x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Error: Stack overflow\n");
        return;
    }
    A[++top] = x;
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

char Top()
{
    return A[top];
}

int IsOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/') return 1;
    return 0;
}

int IsNumeric(char c)
{
    if (c >= '0' && c <= '9') return 1;
    return 0;
}

int Solve(int op1, int op2, char operand)
{
    if (operand == '+') return op1 + op2;
    if (operand == '-') return op1 - op2;
    if (operand == '*') return op1 * op2;
    if (operand == '/') return op1 / op2;
}

int Postfix(char exp[])
{
    for (int i = 0; i < strlen(exp); i++)
    {
        if (IsNumeric(exp[i]))
        {
            int operand = 0;
            while (i < strlen(exp) && IsNumeric(exp[i]))
            {
                operand = (operand * 10) + exp[i] - '0';
                i++;
            }
            i--;
            Push(operand);
        }
        if (IsOperator(exp[i]))
        {
            int op2 = Top(); Pop();
            int op1 = Top(); Pop();
            int res = Solve(op1, op2, exp[i]);
            Push(res);
        }
    }
    return Top();
}

int main(void )
{
    char exp[51];
    printf("Enter expression : ");
    scanf("%s", exp);
    printf("Result : %d\n", Postfix(exp));
    return 0;
}
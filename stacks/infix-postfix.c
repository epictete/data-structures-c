#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

char A[MAX_SIZE];
int top = -1;

int IsEmpty(void)
{
    return top == -1;
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

void Pop(void)
{
    if (IsEmpty())
    {
        printf("Error: Stack is empty\n");
        return;
    }

    top--;
}

char Top(void)
{
    return A[top];
}


int IsOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int IsOperand(char c)
{
    if (c >= '0' && c <= '9') return 1;
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    return 0;
}

int HasHigherPrecedence(char top)
{
    return top == '*' || top == '/';
}

int IsOpeningParenthesis(char c)
{
    return c == '(' || c == '{' || c == '[';
}

int IsClosingParenthesis(char c)
{
    return c == ')' || c == '}' || c == ']';
}

void InfixToPostfix(char* exp, char* res)
{
    int resIndex = 0;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (IsOperand(exp[i]))
        {
            res[resIndex] = exp[i];
            resIndex++;
        }

        if (IsOperator(exp[i]))
        {
            while (!IsEmpty() && !IsOpeningParenthesis(Top()) && HasHigherPrecedence(Top()))
            {
                res[resIndex] = Top();
                Pop();
                resIndex++;
            }

            Push(exp[i]);
        }

        if (IsOpeningParenthesis(exp[i]))
            Push(exp[i]);

        if (IsClosingParenthesis(exp[i]))
        {
            while (!IsEmpty() && !IsOpeningParenthesis(Top()))
            {
                res[resIndex] = Top();
                Pop();
                resIndex++;
            }

            Pop();
        }
    }

    while (!IsEmpty())
    {
        res[resIndex] = Top();
        Pop();
        resIndex++;
    }
}

int main(void)
{
    char exp[51];
    char res[51];

    printf("Enter infix expression\t: ");
    scanf("%s", exp);

    InfixToPostfix(exp, res);

    printf("Postfix conversion\t: ");

    for (int i = 0; i < strlen(res); i++)
        printf("%c", res[i]);

    printf("\n");

    return 0;
}
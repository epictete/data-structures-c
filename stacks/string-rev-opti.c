/*
 * This implementation of the Reverse() function
 * is not based on a stack.
 * It is an optimized way in terms of
 * space complexity with O(1) instead of O(n).
 */

#include <stdio.h>
#include <string.h>

void Reverse(char C[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        char temp = C[i];
        C[i] = C[j];
        C[j] = temp;
        i++;
        j--;
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
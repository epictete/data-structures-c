#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}
Node;

int FindLength(Node* head)
{
    int length = 0;

    while (head != NULL)
    {
        length++;
        head = head->next;
    }

    return length;
}

Node* FindMergePoint(Node* A, Node* B)
{
    int m = FindLength(A);
    int n = FindLength(B);
    int d = n - m;

    if (m > n)
    {
        Node* temp = A;
        A = B;
        B = temp;
        d = m - n;
    }

    for (int i = 0; i < d; i++)
        B = B->next;

    while (A != NULL && B != NULL)
    {
        if (A == B) return A;
        A = A->next;
        B = B->next;
    }

    return NULL;
}

int main(void)
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* temp[7];

    for (int i = 0; i < 7; i++)
        temp[i] = malloc(sizeof(Node));

    temp[0]->data = 4;
    temp[0]->next = temp[1];
    temp[1]->data = 6;
    temp[1]->next = temp[2];
    temp[2]->data = 7;
    temp[2]->next = temp[3];
    temp[3]->data = 1;
    temp[3]->next = NULL;
    temp[4]->data = 9;
    temp[4]->next = temp[5];
    temp[5]->data = 3;
    temp[5]->next = temp[6];
    temp[6]->data = 5;
    temp[6]->next = temp[2];

    head1 = temp[0];
    head2 = temp[4];

    Node* C = FindMergePoint(head1, head2);
    printf("Merge point is: %d\n", C->data);

    return 0;
}
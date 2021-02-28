#include <stdio.h>

int A[10];
int n = sizeof(A) / sizeof(A[0]);
int front = -1, rear = -1;

int IsEmpty(void)
{
	if (front == -1 && rear == -1) return 1;
	return 0;
}

int IsFull(void)
{
	if ((rear + 1) % n == front) return 1;
	return 0;
}

int Front(void)
{
	if (IsEmpty())
	{
		printf("Error : queue is empty\n");
		return -1;
	}

	return A[front];
}

void Enqueue(int x)
{
	if (IsFull())
	{
		printf("Queue is full\n");
		return;
	}
	else if (IsEmpty())
		front = rear = 0;
	else
		rear = (rear + 1) % n;

	A[rear] = x;
}

void Dequeue(void)
{
	if (IsEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	else if (front == rear)
		front = rear = -1;
	else
		front = (front + 1) % n;
}

void Print(void)
{
	int count = (rear + n - front) % n + 1;

	printf("Queue : [ ");

	for (int i = 0; i < count; i++)
	{
		int index = (front + i) % n;
		printf("%d ", A[index]);
	}

	printf("]\n");
}

int main(void)
{
	Enqueue(2); Print();
	Enqueue(4); Print();
	Enqueue(6); Print();
	Enqueue(8); Print();
	Dequeue(); Print();
	Enqueue(10); Print();

	printf("Front : %d\n", Front());

	return 0;
}
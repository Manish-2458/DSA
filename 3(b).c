#include <stdio.h>
#include <stdlib.h>

int *a;
int n, data;
int front = -1, rear = -1;

void enqueue()
{
    printf("Enter the value to be inserted: ");
    scanf("%d", &data);
    if ((rear + 1) % n == front)
    {
        printf("Queue Overflow.\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == n - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % n;
        }
        a[rear] = data;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow.\n");
    }
    int val = a[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == n - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("The queue is empty.\n");
        return;
    }
    printf("The queue is: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", a[i]);
        i = (i + 1) % n;
    }
    printf("%d\n", a[rear]);
}
void minElement()
{
    if (front == -1)
    {
        printf("The queue is empty.\n");
        return;
    }
    int min = a[front];
    int i = front;
    while (i != rear)
    {
        if (a[(i + 1) % n] < a[i])
        {
            min = a[(i + 1) % n];
        }
        i = (i + 1) % n;
    }
    display();
    printf("The minimum element of the queue is:- %d\n", min);
}
int main()
{
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));

    int choice, num = 1;
    while (num != 0)
    {
        printf("MENU\n");
        printf("Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for finding minimum element\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            minElement();
            break;
        }
        printf("Enter 1 to continue or 0 to stop: ");
        scanf("%d", &num);
    }

    free(a);
    printf("Program completed successfully!\n");
    return 0;
}

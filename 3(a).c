#include <stdio.h>
#include <stdlib.h>

int *a;
int *b;
int *c;
int n, data;
int front = -1, rear = -1;
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

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

void splitq()
{
    if (front == -1)
    {
        printf("The queue is empty.\n");
        return;
    }
    int i = front;
    while (i != rear)
    {
        if (i % 2 == 0)
        {
            if (front1 == -1 && rear1 == -1)
            {
                front1 = 0;
                rear1 = 0;
            }
            else if (rear1 == n - 1 && front1 != 0)
            {
                rear1 = 0;
            }
            else
            {
                rear1 = (rear1 + 1) % n;
            }
            b[rear1] = a[i];
        }
        else
        {
            if (front2 == -1 && rear2 == -1)
            {
                front2 = 0;
                rear2 = 0;
            }
            else if (rear2 == n - 1 && front2 != 0)
            {
                rear2 = 0;
            }
            else
            {
                rear2 = (rear2 + 1) % n;
            }
            c[rear2] = a[i];
        }
        i = (i + 1) % n;
    }
    if (rear % 2 != 0)
    {
        rear2 = (rear2 + 1) % n;
        c[rear2] = a[rear];
    }
    else
    {
        rear1 = (rear1 + 1) % n;
        b[rear1] = a[rear];
    }

    printf("The first queue is: ");
    if (front1 == -1)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        int i = front1;
        while (i != rear1)
        {
            printf("%d ", b[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", b[rear1]);
    }

    printf("The second queue is: ");
    if (front2 == -1)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        int i = front2;
        while (i != rear2)
        {
            printf("%d ", c[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", c[rear2]);
    }
}

int main()
{
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    c = (int *)malloc(n * sizeof(int));

    int choice, num = 1;
    while (num != 0)
    {
        printf("MENU\n");
        printf("Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for split queue\n");
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
            splitq();
            break;
        }
        printf("Enter 1 to continue or 0 to stop: ");
        scanf("%d", &num);
    }

    free(a);
    free(b);
    free(c);
    printf("Program completed successfully!\n");
    return 0;
}

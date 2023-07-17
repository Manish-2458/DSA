#include <stdio.h>
#include <stdlib.h>

int *a;
int *front = NULL;
int *rear = NULL;
int data, n;
int f = 0, r = 0;

void enqueue()
{
    if (r == n)
    {
        printf("The queue is full.\n");
    }
    else
    {
        printf("Enter the value to be inserted in the queue: ");
        scanf("%d", &data);
        a[r++] = data;
    }
}

void display()
{
    if (r == n)
    {
        printf("The queue is full.\n");
    }
    if (r == 0 && f == 0)
    {
        printf("The queue is empty.\n");
    }
    if (f == r)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The queue is: ");
        for (int i = f; i < r; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

void dequeue()
{
    if (f == r)
    {
        printf("Nothing to delete.\n");
    }
    if (f < n)
    {
        int temp = a[f];
        f = f + 1;
        printf("Deleted element: %d\n", temp);
    }
    else
    {
        printf("Nothing to delete.\n");
    }
}

int main()
{
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    front = &f;
    rear = &r;
    int choice, num = 1;
    while (num != 0)
    {
        printf("MENU\n");
        printf("Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\n");
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
        }
        printf("Enter 1 to continue or 0 to stop:- ");
        scanf("%d", &num);
    }
    free(a);
    printf("Program completed successfully!\n");
    return 0;
}

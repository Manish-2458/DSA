#include <stdio.h>
int top = -1;
void push(int *a, int n, int num)
{
    if (top == n - 1)
    {
        printf("queue overflow");
    }
    else
    {
        top++;
        a[top] = num;
    }
}
void pop(int *a, int n)
{
    int b[n], dtop = -1;
    while (top != -1)
    {
        dtop++;
        b[dtop] = a[top];
        top--;
    }
    dtop--;
    top = -1;
    while (dtop != -1)
    {
        top++;
        a[top] = b[dtop];
        dtop--;
    }
}

int main()
{
    int n;
    printf("Enter size of the stack:- ");
    scanf("%d", &n);
    int a[n],i;
    int z, num = 1;
    while (num != 0)
    {
        printf("\nEnter 1 for push\nEnter 2 for pop\n");
        scanf("%d", &z);
        switch (z)
        {
        case 1:
            printf("Enter to insert");
            int num;
            scanf("%d", &num);
            push(a, n, num);
            break;
        case 2:
        {
            pop(a, n);
            break;
        }
        default:
        {
            printf("Enter valid option");
        }
        }
        printf("Enter 1 to continue or 0 to stop:- ");
        scanf("%d", &num);
    }
    printf("The Queue is:- \n");
    for (i = 0; i <= top; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
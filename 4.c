#include<stdio.h>
#include<stdlib.h>

int *a;
int n, data;
int front = -1, rear = -1;

int isEmpty() {
    if (front == -1 && rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull() {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        return 1;
    } else {
        return 0;
    }
}

void insertFront() {
    printf("Enter the value to be inserted from the front end: ");
    scanf("%d", &data);
    if (isFull()) {
        printf("The DEqueue is full.\n");
        return;
    } else {
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = n - 1;
        } else {
            front = front - 1;
        }
        a[front] = data;
    }
}

void insertLast() {
    printf("Enter the data to be inserted from the rear end: ");
    scanf("%d", &data);
    if (isFull()) {
        printf("The DEqueue is full.\n");
        return;
    } else {
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else if (rear == n - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        a[rear] = data;
    }
}

void deleteFront() {
    if (isEmpty()) {
        printf("Nothing to delete from the DEqueue.\n");
        return;
    } else {
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == n - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }
}

void deleteLast() {
    if (isEmpty()) {
        printf("Nothing to delete.\n");
        return;
    } else {
        if (rear == front) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = n - 1;
        } else {
            rear = rear - 1;
        }
    }
}

void getFront() {
    if (isEmpty()) {
        printf("The DEqueue is empty.\n");
        return;
    } else {
        printf("The value of the front element is: %d.\n", a[front]);
    }
}

void getRear() {
    if (isEmpty()) {
        printf("The DEqueue is empty.\n");
        return;
    } else {
        printf("The value of the rear element is: %d.\n", a[rear]);
    }
}

void display() {
    if (isEmpty()) {
        printf("The DEqueue is empty.\n");
    } else if (isFull()) {
        printf("The DEqueue is full.\n");
    } else {
        printf("\nThe DEqueue is:\n");
        int i = front;
        while (i != rear) {
            printf("%d ", a[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", a[rear]);
    }
}

int main() {
    printf("Enter the max size of the double-ended queue: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    int num = 1, choice;
    while (num != 0) {
        printf("\nMENU\n");
        printf("Enter 1 to insertFront\nEnter 2 insertLast\nEnter 3 to deleteFront.\nEnter 4 to deleteLast.\nEnter 5 to getFront.\nEnter 6 to getRear.\nEnter 7 to display.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertFront();
                break;
            case 2:
                insertLast();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                getFront();
                break;
            case 6:
                getRear();
                break;
            case 7:
                display();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\nEnter 1 to continue or 0 to stop: ");
        scanf("%d", &num);
    }
    free(a);
    printf("Program completed successfully!\n");
    return 0;
}

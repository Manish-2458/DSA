#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

// CREATING NODE

void create(struct node **head, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    if (*head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        newnode->data = data;
        *head = newnode;
    }
    else
    {
        struct node *ptr;
        ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode->prev = ptr;
        newnode->data = data;
        newnode->next = NULL;
        ptr->next = newnode;
    }
}

// DISPLAYING NODE

void display(struct node **head)
{
    struct node *ptr = *head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// INSERT AT END

struct node *insert_at_end(struct node *head, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    if (head == NULL)
    {
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        return head;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode->next = NULL;
        newnode->data = data;
        newnode->prev = ptr;
        ptr->next = newnode;
        return head;
    }
}

// INSERT AT BEGINNING

struct node *insert_at_beg(struct node *head, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    if (head == NULL)
    {
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        return head;
    }
    else
    {
        newnode->next = head;
        newnode->prev = NULL;
        newnode->data = data;
        head = newnode;
        return head;
    }
}

// DELETE AT BEGINNING

struct node *del_at_beg(struct node *head)
{
    if (head == NULL)
    {
        printf("Nothing to delete.\n");
        return head;
    }
    else
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        return head;
    }
}

// DELETE AT END

struct node *del_at_end(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr = ptr->prev;
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

// LENGTH OF THE LIST

void length_list(struct node *head)
{
    struct node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    printf("The length of the list is: %d\n", count);
}

// INSERT AT A SPECIFIC POSITION

struct node *insert_at_pos(struct node *head, int pos, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = data;
    if (head == NULL && pos > 0)
    {
        printf("Invalid\n");
        return head;
    }
    else
    {
        struct node *ptr = head;
        pos--;
        while (pos > 1)
        {
            ptr = ptr->next;
            pos--;
        }
        newnode->next = ptr->next;
        newnode->prev = ptr;
        if (ptr->next != NULL)
        {
            ptr->next->prev = newnode;
        }
        ptr->next = newnode;
        return head;
    }
}

// DELETE AT A SPECIFIC POSITION

void deleteAtPosition(struct node **head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *currentnode = *head;
    int count = 1;

    if (pos == 1)
    {
        *head = currentnode->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(currentnode);
        printf("Node deleted successfully.\n");
        return;
    }

    while (currentnode != NULL && count < pos)
    {
        currentnode = currentnode->next;
        count++;
    }

    if (currentnode == NULL)
    {
        printf("Invalid position. Node not found.\n");
        return;
    }

    currentnode->prev->next = currentnode->next;
    if (currentnode->next != NULL)
    {
        currentnode->next->prev = currentnode->prev;
    }
    free(currentnode);
    printf("Node deleted successfully.\n");
}

// REVERSING

void reverse(struct node **head)
{
    struct node *current = *head;
    struct node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

int main()
{
    struct node *head = NULL;
    printf("Enter the number of nodes to be inserted: ");
    int n;
    scanf("%d", &n);
    int data;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        create(&head, data);
    }
    printf("The created linked list is:\n");
    display(&head);
    printf("\n");

    int num = 1;
    int d;
    while (num != 0)
    {
        int n;
        printf("Enter a number from the menu to perform the respective tasks:\n");
        printf("Menu:\n");
        printf("Press 1: Insert at the beginning.\n");
        printf("Press 2: Insert at the end.\n");
        printf("Press 3: Insert at a specific position.\n");
        printf("Press 4: Delete from the beginning.\n");
        printf("Press 5: Delete from the end.\n");
        printf("Press 6: Delete from a specific position.\n");
        printf("Press 7: Length of the linked list.\n");
        printf("Press 8: Reverse the linked list.\n");
        scanf("%d", &n);
        int pos;
        switch (n)
        {
        case 1:
            printf("Enter the value to be inserted at the beginning: ");
            scanf("%d", &d);
            head = insert_at_beg(head, d);
            display(&head);
            break;
        case 2:
            printf("Enter the value of the node to be inserted at the end: ");
            scanf("%d", &d);
            head = insert_at_end(head, d);
            display(&head);
            break;
        case 3:
            printf("Enter the position at which you want to insert the node: ");
            scanf("%d", &pos);
            printf("Enter the data value of the new node: ");
            scanf("%d", &d);
            head = insert_at_pos(head, pos, d);
            display(&head);
            break;
        case 4:
            head = del_at_beg(head);
            display(&head);
            break;
        case 5:
            head = del_at_end(head);
            display(&head);
            break;
        case 6:
            printf("Enter the position of the node you want to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(&head, pos);
            display(&head);
            break;
        case 7:
            length_list(head);
            display(&head);
            break;
        case 8:
            reverse(&head);
            display(&head);
            break;
        }
        printf("Enter 1 to continue or 0 to stop the program: ");
        scanf("%d", &num);
    }
    printf("The program is successfully completed!\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node **head, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    if (*head == NULL)
    {
        newnode->data = data;
        newnode->next = newnode;
        *head = newnode;
    }
    else
    {
        struct node *ptr = *head;
        while (ptr->next != *head)
        {
            ptr = ptr->next;
        }
        newnode->next = *head;
        newnode->data = data;
        ptr->next = newnode;
    }
}

void display(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

// INSERT AT BEGINNING

struct node *add_at_beg(struct node *head, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    if (head == NULL)
    {
        newnode->data = data;
        newnode->next = newnode;
        return newnode;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = head;
        newnode->data = data;
        return newnode;
    }
}

// INSERT AT END

struct node *add_at_end(struct node *head, int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    if (head == NULL)
    {
        newnode->data = data;
        newnode->next = newnode;
        return newnode;
    }
    else
    {
        newnode->data = data;
        struct node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = head;
        return head;
    }
}

// INSERT AT POSITION

struct node *add_at_pos(struct node *head, int data, int pos)
{
    struct node *newnode = malloc(sizeof(struct node));
    if (head == NULL)
    {
        newnode->data = data;
        newnode->next = newnode;
        return newnode;
    }
    if (pos == 1)
    {
        return add_at_beg(head, data);
    }
    struct node *curr = head;
    if (curr->next == head)
    {
        return add_at_end(head, data);
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
        newnode->data = data;
        newnode->next = ptr->next;
        ptr->next = newnode;
        return head;
    }
}

// DELETION FROM BEGINNING

struct node *del_from_beg(struct node *head)
{
    if (head == NULL)
    {
        printf("Nothing to delete.\n");
        return head;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

// DELETION FROM END

struct node *del_from_end(struct node *head)
{
    if (head == NULL)
    {
        printf("Nothing to delete.\n");
        return head;
    }
    else
    {
        struct node *ptr = head;
        struct node *prev_ptr = NULL;
        while (ptr->next != head)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = ptr->next;
        free(ptr);
        return head;
    }
}

// DELETION AT POSITION

struct node *del_from_pos(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("Nothing to delete.\n");
        return head;
    }
    if (pos == 1)
    {
        return del_from_beg(head);
    }
    else
    {
        struct node *ptr = head;
        struct node *f = NULL;
        pos--;
        while (pos > 1)
        {
            ptr = ptr->next;
            pos--;
        }
        f = ptr->next;
        ptr->next = ptr->next->next;
        free(f);
        return head;
    }
}

// LENGTH OF THE LINKED-LIST

void length(struct node *head)
{
    int count = 0;
    struct node *ptr = head;
    do
    {
        ptr = ptr->next;
        count++;
    } while (ptr != head);
    printf("The number of nodes in the linked list is: %d\n", count);
}

// REVERSING LINKED LIST

void reverse(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;

    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    (*head)->next = prev;
    *head = prev;
}

int main()
{
    struct node *head = NULL;
    int n;
    printf("Enter the number of nodes to be created: ");
    scanf("%d", &n);
    int data;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        create(&head, data);
    }
    display(head);
    int num = 1;
    int d;
    int pos;
    while (num != 0)
    {
        int n;
        printf("Enter a number from the menu to perform the respective tasks: ");
        printf("\nMenu:\n");
        printf("Press 1: Insert at the beginning.\n");
        printf("Press 2: Insert at the end.\n");
        printf("Press 3: Insert at a specific position.\n");
        printf("Press 4: Delete from the beginning.\n");
        printf("Press 5: Delete from the end.\n");
        printf("Press 6: Delete from a specific position.\n");
        printf("Press 7: Length of the linked list.\n");
        printf("Press 8: Reverse the linked list.\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter a value to be inserted at the beginning: ");
            scanf("%d", &d);
            head = add_at_beg(head, d);
            display(head);
            break;
        case 2:
            printf("Enter the value to be inserted at the end: ");
            scanf("%d", &d);
            head = add_at_end(head, d);
            display(head);
            break;
        case 3:
            printf("Enter the value to be inserted: ");
            scanf("%d", &d);
            printf("Enter the position at which you want to insert the data: ");
            scanf("%d", &pos);
            head = add_at_pos(head, d, pos);
            display(head);
            break;
        case 4:
            head = del_from_beg(head);
            display(head);
            break;
        case 5:
            head = del_from_end(head);
            display(head);
            break;
        case 6:
            printf("Enter the position of the node you want to delete: ");
            scanf("%d", &pos);
            head = del_from_pos(head, pos);
            display(head);
            break;
        case 7:
            length(head);
            break;
        case 8:
            reverse(&head);
            display(head);
            break;
        }
        printf("Enter 0 to stop the program or any other number to continue: ");
        scanf("%d", &num);
    }
    printf("Program executed successfully.\n");
    return 0;
}

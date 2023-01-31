#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev, *next;
    int info;
};
void InsAtBeginning();
void InsAtEnd();
void InsAtPos();
void DelAtBeginning();
void DelAtEnd();
void DelAtPos();
void display();
struct node *head = NULL;

void main()
{
    while (1)
    {
        printf("1. Insert a beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsAtBeginning();
            break;
        case 2:
            InsAtEnd();
            break;
        case 6:
            DelAtPos();
            break;
        case 7:
            display();
            break;
        }
    }
}
void InsAtBeginning()
{
    struct node *newnode;
    int data;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newnode->info = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        system("clear");
        printf("Inserted %d\n", data);
        return;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        system("clear");
        printf("Inserted %d\n", data);
    }
}
void InsAtEnd()
{
    struct node *newnode, *ptr;
    int data;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newnode->info = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        system("clear");
        printf("Inserted %d\n", data);
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
        newnode->next = NULL;
        printf("Inserted %d\n", data);
    }
}
void InsAtPos()
{
    int i, pos, data;
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("Enter the position to insert node: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        InsAtBeginning();
    }
    else
    {
        printf("enter the data :");
        scanf("%d", &data);
        newnode->info = data;
        for(i=0;i<pos-1;i++){
            ptr=ptr->next;
        }
       



    }
}
void DelAtPos()
{
    struct node *ptr;
    int pos, i;
    printf("Enter the position to delete node from: ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        ptr = head;
        head->next->prev = NULL;
        head = head->next;
        printf("Deleted %d\n", ptr->info);
        free(ptr);
        return;
    }
    else
    {
        ptr = head;
        for (i = 0; i < pos; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                system("clear");
                printf("invalid position\n");
                return;
            }
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        printf("Deleted %d\n", ptr->info);
        free(ptr);
        return;
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    system("clear");
    printf("elements in the list are:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}
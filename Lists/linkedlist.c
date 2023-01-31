#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int info;
};
struct node *head = NULL;

void InsAtBeginning();
void InsAtEnd();
void InsAtPos();
void Display();
void DelAtEnd();
void DelAtBeginning();
void DelAtPos();
void prompt();

int main()
{   
  prompt();  
}
void prompt(){
    int choice;
    while (1)
    {
        printf("\n*********MENU*********\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsAtBeginning();
            break;
        case 2:

            InsAtEnd();
            break;
        case 3:
            InsAtPos();
            break;
        case 4:
            DelAtBeginning();
            break;
        case 5:
            DelAtEnd();
            break;
        case 6:
            DelAtPos();
            break;
        case 7:
            Display();
            break;
        case 8:
            exit(0);
        default:

            printf("Invalid choice");
            break;
        }
    }
}
void InsAtBeginning()
{
    int data;
    printf("Enter the data value to insert into the node : ");
    scanf("%d", &data);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    // if (head == NULL)
    // {
    //     head = newnode;
    // }
    newnode->info = data;
    newnode->next = head;
    head = newnode;
}
void InsAtEnd()
{
    int data;
    printf("Enter the data value to insert into the node :");
    scanf("%d", &data);
    struct node *ptr;
    ptr = head;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = NULL;
}
void InsAtPos()
{
    struct node *ptr;
    ptr = head;
    int data, pos, i;
    printf("Enter the data  value and position to insert into the node :");
    scanf("%d%d", &data, &pos);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;

    for (i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            system("clear");
            printf("Invalid position\n");
            prompt();
        
        }
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
}

void DelAtBeginning()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
            system("clear");
            printf("Invalid Deletion\n");
            prompt();
        
    }
    printf("%d deleted\n", ptr->info);
    ptr = head;
    head = ptr->next;
    free(ptr);
}
void DelAtEnd()
{

    struct node *ptr, *temp;
    ptr = head;
    if (head == NULL)
    {
       system("clear");
            printf("Invalid Deletion\n");
            prompt();
        
    }
    if (head->next == NULL)
    {
        head = NULL;
        printf("%d deleted \n", ptr->info);
        free(ptr);
    }
    else
    {
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("%d deleted \n", ptr->info);
        free(ptr);
    }
}
void DelAtPos()
{
    int pos, i;
    printf("Enter the position to delete :");
    scanf("%d", &pos);
    struct node *ptr, *temp;
    ptr = head;
    if (head == NULL)
    {
         system("clear");
        printf("EMpty list");
       prompt();
    }
    if (pos == 0)
    {
        head = head->next;
        printf("%d deleted ", ptr->info);
        free(ptr);
    }
    else
    {
        for (i = 0; i < pos; i++)
        {
            temp = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                system("clear");
                printf("Invalid deletion\n");
                prompt();
            }
        }
        printf("%d deleted \n", ptr->info);
        temp->next = ptr->next;
        free(ptr);
    }
}

void Display()
{
    struct node *ptr;
    ptr = head;
    int i = 0;
    printf("The elements in the list are :\nposition  Item\n");
    while (ptr != NULL)
    {
        printf("%d \t %d \n", i++, ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}
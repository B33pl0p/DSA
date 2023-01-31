#include <stdio.h>
#define SIZE 5
#include <stdlib.h>
int top = -1;
int stack[SIZE], data;
int Push(int data);
void Pop();
int Top();
int IsEmptyStack();
int IsFullStack();
void Display();
int main()
{
    int data,i,choice;
prompt:
    printf("Enter your choice :\n");
    printf("1. Push Data\n");
    printf("2. Pop Data\n");
    printf("3. Display Data\n");
    printf("4. Exit\n");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter element to push :");
     
            scanf("%d", &data);
            Push(data);
            system("cls");
        printf("Push succesful\n");
        goto prompt;
    case 2:
        system("cls");
        Pop();
        goto prompt;
    case 3:
        system("cls");
        Display();
        goto prompt;
    case 4:
        exit(0);
    default:
        printf("Invalid input \n");
        exit(0);
    }
}
int Push(int x)
{
    if (IsFullStack() == 0)
    {
        top = top + 1;
        stack[top] = x;
    }
    else
    {
        printf("Stack is full\n");
        exit(0);
    }
}
int IsFullStack()
{

    if (top == SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsEmptyStack()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Top()
{
    if (IsEmptyStack() == 0)
    {
        printf("The top element is : %d \n", stack[top]);
    }
    else
    {
        printf("Stack underflow \n");
        exit(0);
    }
}
void Pop()
{
    int temp;
    if (IsEmptyStack() == 1)
    {
        printf("Stack underflow \n");
        exit(0);
    }
    else
    {
        temp = stack[top];
        top = top - 1;
        printf("The popped element is %d \n ", temp);
    }
}
void Display()
{
    int i;
    if (IsEmptyStack() == 1)
    {
        printf("Stack underflow \n");
        exit(0);
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
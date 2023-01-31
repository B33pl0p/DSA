#include <stdio.h>
#define SIZE 5
#include <stdlib.h>
int top = -1;
int stack[SIZE], data;
int Push(int data);
int Pop();
int Top();
int IsEmptyStack();
int IsFullStack();
void Display();
int main()
{
Push(10);
Push(12);
Push(15);
Push(25);
Display();
Top();
Pop();
Display();
Pop();
Display();
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
int Pop()
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
        printf("\nelements in stack : \n");
        for (i = top; i >=0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
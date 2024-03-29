#include <stdio.h>
#include <ctype.h>
char stack[300];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
   return stack[top--];
}
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}
int main()
{
    char expression[100];
    char *e, x;
    printf("Enter the expression: ");
    scanf("%s", expression);
    e = expression;

    while (*e != '\0')
    {
        if isalnum (*e)
        {
            printf("%c ", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')

        {
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1)
        printf("%c ", pop());
}

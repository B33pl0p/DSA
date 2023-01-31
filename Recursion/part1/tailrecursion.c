#include<stdio.h>
void fun(int n)
{
    if (n > 0)
    {
        printf("%d \n", n);
        fun(n-1);
    }
}

int main ()
{
    int n;
    printf("enter a number");
    scanf("%d",&n);
    fun(n);
    return 0;
}
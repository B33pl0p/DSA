//FIBONACCI UPTO N TERMS
#include<stdio.h>
int fib(n){
    if(n==0){
        return 0;
    }
    else if(n==1 || n==2 ){
        return 1;
    }
    else {
        return fib(n-2)+fib(n-1);
    }
}

int main(){
    int n,i;
    printf("Enter the value of n :");
    scanf("%d",&n);
    printf("The fibonacci series upto %d terms are :\n");
    for(i=0;i<n;i++){
        printf("%d ",fib(i));
    }
    }
    
#include<stdio.h>
int fact(int n,int a){
    if(n==0 || n==1){
        return a;
    }
    else {
        return fact(n-1,a*n);
    }
}
int main(){
    int num;
    printf("Enter a number :");
    scanf("%d",&num);
    printf("The factorial is %d",fact(num,1));
}
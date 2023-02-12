#include<stdio.h>
int hcf(int n1,int n2){
    if(n2 != 0){
        return hcf(n2,n1%n2);
    }
    else {
        return n1;
    }
   
}
int main(){
    int num1,num2;
    printf("Enter two  numbers :");
    scanf("%d%d",&num1,&num2);
    printf("The HCF is %d",hcf(num1,num2));
}
//REVERSE A NUMBER USING RECURSION
#include<stdio.h>
int sum=0;
int rev(int n){
  if(n){
    sum = (sum*10) + (n%10) ;
    rev(n/10);  
 }
 else {
    return sum;
 }
   
}
int main(){
    int n;
    printf("Enter a number :");
    scanf("%d",&n);
    printf("The reverse is %d ",rev(n));
}
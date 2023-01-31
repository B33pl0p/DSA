#include<stdio.h>
int reverse(int n,int temp){
 if(n ==0){
    return temp;
 }
 else {
    temp= (temp*10) + (n%10);
    return reverse(n/10,temp);
    
 }
}
int main(){
    int n;
    printf("Enter a number :");
    scanf("%d",&n);
    int temp = reverse(n,0);
    n == temp?printf("palindrome"):printf("not palindrome");

}
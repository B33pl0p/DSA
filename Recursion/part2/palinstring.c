#include<stdio.h>
#include<string.h>
int ispalindrome(char str[100] , int start, int end){
 if(start>=end){
    return 1;
 }
   else {
        if(str[start]!=str[end])
            return 0;
       else 
            return ispalindrome(str,start+1,end-1); 
    }
}
int main(){
 char str[100];
 printf("Enter a string : ");
 scanf("%s",str);
 if(ispalindrome(str,0,strlen(str)-1)){
    printf("The string is palindrome ");
 }
 else {
    printf ("the string is not palindrome");
 }
}
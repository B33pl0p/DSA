#include<stdio.h>
#include<string.h>
int ispalindrome(char *,int,int);
int main(){
    char str[100];
    printf("Enter a string: ");
    gets(str);
    int len=strlen(str);
    if(ispalindrome(str,0,len-1))
        printf("The string is a palindrome");
    else
        printf("The string is not a palindrome");
    return 0;
}
int ispalindrome(char *str,int start,int end){
    if(start>=end)
        return 1;
    else {
        if(str[start]!=str[end])
            return 0;
       else 
            return ispalindrome(str,start+1,end-1); 
    }
}


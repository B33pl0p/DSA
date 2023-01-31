#include<stdio.h>
void TOH(int,char,char,char);
int main(){
    char A='A',B='B',C='C';
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    TOH(n,A,B,C);

}
void TOH(int n,char A,char B,char C){
if(n<=0)
    return;
else {
    TOH(n-1,A,C,B);
    printf("Moved disk %d from %c to %c\n",n,A,C);
    TOH(n-1,B,A,C);
}

}
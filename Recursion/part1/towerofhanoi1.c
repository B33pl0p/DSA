
#include<stdio.h>
int count = 0;
void towerofhanoi(int n,char A,char B,char C)
{
    if(n==0){
        return;
    }
    else {
        towerofhanoi(n-1,A,C,B);
        printf("Move disk %d from %c to %c\n",n,A,C);
        count++;
        towerofhanoi(n-1,B,A,C);
    }
}
int main(){
int n =3;
printf("The sequence for solving the tower is :\n");
towerofhanoi(n,'A','B','C');
printf("The number of steps is : %d",count);
return 0;
}
#include<stdio.h>
int xpowern(int x, int n){
 if(n ==0){
    return 1;
 }
 if(x==0){
    return 0;
 }
 else {
    return x*xpowern(x,n-1);
 }
}
int main(){
    printf("Enter x and n :");
    int x,n;
    scanf("%d%d",&x,&n);
    printf("%d to the power %d is :%d",x,n,xpowern(x,n));
}
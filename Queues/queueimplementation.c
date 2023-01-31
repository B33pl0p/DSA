#include<stdio.h>
#define MAX_SIZE 4
char queue[MAX_SIZE];
int front = -1;
int rear = -1;
void enqueue(char a){
    //if empty
    if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = a;
    }
    else if (rear == MAX_SIZE-1){
        printf("queue full");
    }
    else {
        queue[rear++] = a;
    }

}
char dequeue(){
    if (front == -1 && rear == -1){
        return -1;
        //queue empty
    }
   
    else {
        char temp = queue[front++];
        return temp;
    }
}

int main(){

enqueue('a');
enqueue('b');
enqueue('c');
enqueue('d');
dequeue();
dequeue();  
enqueue('e');

}
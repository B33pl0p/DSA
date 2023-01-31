#include <stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int enqueue(int a)
{
    //queue full conditions
    if (front == (rear + 1) % MAX_SIZE)
    {
        printf("queue full");
    }
    else
    {
        //queue empty condition
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[rear] = a;
        }
        //at-least one element
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            queue[rear] = a;
        }
    }
    printf("\n %d enqueued\n", a);
    return 0;
}
void dequeue()
{

    int temp;
    if (front == -1)
    {
        printf("queue empty");
    }
    else
    {
        temp = queue[front];

        if (front == rear)
        {
            //if queue is emptied after dequeing
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }
    printf("\nelement dequeued is %d\n", temp);
}
void display()
{
    int i;
    printf("\nthe elements in queue are :");
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
    {
        printf("%d ", queue[i]);
        //loop stops when i = 3 and last element is not printed
    }

    printf("%d ",queue[rear]);

}
int main()
{
    enqueue(1);
    enqueue(2);
    display();
    dequeue();
    display();
    enqueue(6);
    display();
}
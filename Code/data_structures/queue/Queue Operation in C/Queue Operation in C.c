//enqueue and dequeue
#include <stdio.h>
int queue[30];
int front=-1,rear=-1;
void enqueue(int elem)
{
    if(rear==29)
    {
        printf("Queue Overflow ");
    }
    else
    {
        rear++;
        queue[rear]=elem;
        printf("Enqueued %d\n",elem);
        if(front==-1)
        {
            front=0;
        }
    }
}

void dequeue()
{
    if(front==-1)
    {
        printf("Queue Underflow\n");
    }
    else
    { 
        printf("Dequeued %d\n",queue[front]);
        front++;
    }
}
void display()
{
    while(front!=rear)
    {
        printf("%d",queue[front]);
        front++;
    }
    printf("%d",queue[front]);
}
void main()
{
    int c=1,choice,temp;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the element to enqueue\n");
            scanf("%d",&temp);
            enqueue(temp);
            break;
            
            case 2:
            dequeue();
            break;
            
            case 3:
            display();
            break;
            
            default:
            printf("Invalid Choice\n");
        }
        printf("Do you want to continue? 1.Yes 2.No\n");
        scanf("%d",&c);
    }
    while(c==1);
}


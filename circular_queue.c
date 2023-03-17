#include<stdio.h>
#include<stdlib.h>
int isEmpty(int* q,int size,int* top,int* rear)
{
    if(*top==-1 && *rear==-1) return 1;
    else return 0;
}
int isFull(int* q,int size,int* top,int* rear)
{
    if((*rear+1)%size==*top) return 1;
    return 0;
}
void enqueue(int* q,int size,int* top,int* rear,int val)
{
    if(isEmpty(q,size,top,rear))
    {
        *top = (*top+1)%size;
        *rear = (*rear+1)%size;
        q[*rear] = val;
    }
    else if(isFull(q,size,top,rear))
    {
        printf("OVERFLOW!!");
    }
    else
    {
        *rear = (*rear+1)%size;
        q[*rear] = val;
    }
}
int dequeue(int* q,int size, int* top, int* rear)
{
    if(isEmpty(q,size,top,rear)) return -1;

    int value = q[*top];
    if(*top==*rear && *top ==0)
    {
        *top = -1;
        *rear = -1;
        return value;
    }
    else
    {
        *top = (*top+1)%size;
        return value;
    }
}
void peek(int* q,int* top,int* rear)
{
    printf("%d",q[*top]);
}
void main()
{
    int top,rear;
    top = -1;
    rear = -1;
    int size;
    printf("Enter the size");
    scanf("%d",&size);
    int* q = (int*)(malloc(sizeof(int)*size));
    enqueue(q,size,&top,&rear,10);
    enqueue(q,size,&top,&rear,55);
    enqueue(q,size,&top,&rear,65);
    int val = dequeue(q,size,&top,&rear);
    peek(q,&top,&rear);    
}
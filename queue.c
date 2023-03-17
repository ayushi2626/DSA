#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int size;
    int f;
    int r;
    int *arr;
}queue;

int isFull(queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(queue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(queue *q,int val)
{
    if(isFull(q))
    {
        printf("This queue is full. OVERFLOW");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(queue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("No element to dequeue");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    
    }
    return a;
}

int main()
{
    queue q;
    q.size = 100;
    q.f=q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    enqueue(&q,12);
    enqueue(&q,13);
    enqueue(&q,15);
    int a = dequeue(&q);
    printf("%d",a);
    
    return 0;
}
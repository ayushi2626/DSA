#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
}stack;

int isFull(stack *q)
{
    if(q->top==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(stack *q)
{
    if(q->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack *q,int val)
{
    if(isFull(q))
    {
        printf("This queue is full. OVERFLOW");
        exit(0);
    }
    else{
        q->top++;
        q->arr[q->top] = val;   
    }
}

int pop(stack *q)
{
    if(isEmpty(q))
    {
        printf("No element to dequeue");
        return -1;
    }
    else{
        int a = q->arr[q->top];
        q->top--;
        return a;    
    }
}
void print_stack(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        printf("%d",arr[i]);
    }
}
void main()
{
    stack st;
    st.size = 4;
    st.top = -1;
    st.arr = (int*)malloc(st.size*sizeof(int));
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    print_stack(st.arr,st.size);
    int a = pop(&st);
    a = pop(&st);
    a = pop(&st);
    a = pop(&st);
}
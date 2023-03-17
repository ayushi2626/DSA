#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int* arr;
    int size;
}stack;

void push(stack* s1,stack* s2,int size,int val)
{
    /* push element into s1 if the no of elements doesnt exceed the sizeof the net array arr(n)*/
    if(s1->size+s2->size<size)
    {
        s1->arr[s1->size++] = val;
    }
    else
    {
        printf("Overflow");
    }
}
void print(stack* s1)
{
    for(int i=0;i<s1->size;i++)
    {
        printf("%d-",s1->arr[i]);
    }
}
void main()
{
    int n,arr[n];
    printf("Enter the size of the two array");
    scanf("%d",&n);
    stack* s1 = (stack*)(malloc(sizeof(stack)));
    stack* s2 = (stack*)(malloc(sizeof(stack)));
    s1->arr = &arr[0];
    s2->arr = &arr[n-1];
    s1->size=0;
    s2->size = 0;
    push(s1,s2,n,2);
    push(s1,s2,n,6);
    push(s2,s1,n,4);
}
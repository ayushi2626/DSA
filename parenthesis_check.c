#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
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

void push(stack *q,char val)
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

char pop(stack *q)
{
    if(isEmpty(q))
    {
        return '*';
    }
    else{
        char a = q->arr[q->top];
        q->top--;
        return a;    
    }
}
void print_stack(char arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        printf("%c",arr[i]);
    }
}
int check(stack *st,char exp[])
{   
    int flag=1;
    for(int i=0;i<=st->size-1;i++)
    {   
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='(') push(st,exp[i]);
        if(exp[i]=='}' || exp[i]==']' || exp[i]==')')
        {   
            if(st->top==-1) return 0;
            char x = pop(st);
            if(exp[i]=='}' && x!='{')
            {   
                flag=0;
                return flag;
            }
            if(exp[i]==']' && x!='[')
            {   
                flag = 0;
                return flag;
            }
            if(exp[i]==')' && x!='(')
            {   
                flag=0;
                return flag;
            }
        }
    }
    return flag;
    
}
void main()
{   
    char exp[] = "()";
    int size = sizeof(exp)/sizeof(char);
    stack st;
    st.size = size+1;
    st.top = -1;
    st.arr = (char*)malloc(st.size*sizeof(char));
    int j = check(&st,exp);
    printf("%d",j);

}
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;

node* create_node(int num, node *next)
{
    node *n = (node*)malloc(sizeof(node));
    if(n==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    n->value = num;
    n->next = next;

    return n;
}

void print_list(node *ptr)
{
    node *tmp=ptr;
    while(tmp!=NULL)
    {
        printf("%d->",tmp->value);
        tmp=tmp->next;
    }
}

node* insert_start(node *ptr,int value)
{
    node *tmp = (node*)malloc(sizeof(node));
    tmp->value = value;
    tmp->next = ptr;
    ptr = tmp;
    return ptr;    
}

void insert_end(node *ptr,int value)
{
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    node *n = (node*)malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    ptr->next  = n;
}

node* reverse(node* list, int i)
{   
    int n=0;
    node* curr;
    node* prev = NULL;
    curr = list;
    while(curr!=NULL && n<i)
    {
        node* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
        n++;
    }
    return prev;
}



void main()
{
    node *list=NULL;  
    list = create_node(1,NULL);
    insert_end(list,2);
    insert_end(list,3);
    insert_end(list,4);
    
    node* list2= create_node(5,NULL);
    insert_end(list2,6);
    insert_end(list2,7);
    insert_end(list2,8);

    list = reverse(list,2);
    print_list(list);
    
}
# include<stdio.h>
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

void insert_pos(node *ptr,int value,int pos)
{   
    node *n = (node*)malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    int i=1;
    node *tmp = ptr;
    while(tmp!=NULL && i!=pos-1)
    {
        tmp=tmp->next;
        i+=1;
    }
    node *tmp2;
    tmp2 = tmp->next;
    tmp->next = n;
    n->next = tmp2;
}

void delete_end(node *ptr)
{
    node *tmp,*tmp2;
    tmp=ptr;
    while(tmp->next->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp2 = tmp->next;
    tmp->next = NULL;
    free(tmp2);
}

node* delete_start(node *ptr)
{
    node *tmp =ptr;
    ptr = ptr->next;
    free(tmp);
    return ptr;
     
}

node* delete_pos(node *ptr,int pos)
{
    node *tmp=ptr;
    int i=1;
    while(tmp!=NULL && i!=pos-1)
    {
        tmp=tmp->next;
        i+=1;
    }
    node *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
    return ptr;     
}

int number_pos(node *ptr, int pos)
{
    int i=1;
    node *tmp= ptr;
    while(tmp!=NULL && i!=pos)
    {
        tmp=tmp->next;
        i+=1;
    }
    return tmp->value;
}

void main()
{   node *list=NULL;  
    node *n = create_node(1,NULL);
    list = n;
    node *n_2 = create_node(2,NULL);
    list->next = n_2;
    list = insert_start(list,3);
    insert_end(list,4);
    insert_end(list,6);
    insert_pos(list,5,2);
    insert_pos(list,8,4);
    delete_end(list);
    list = delete_start(list);
    list = delete_pos(list,3);
    insert_end(list,10);
    insert_end(list,9);
    list = insert_start(list,16);
    print_list(list);
    int num = number_pos(list,2);
    printf("\n%d",num);
    free(list);
    free(n_2);
}
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}node;
typedef struct hash_table
{
    struct node** hashtable;
    int size;
}hash;
node* create(int val)
{
    node* x = (node*)(malloc(sizeof(node)));
    x->next = NULL;
    x->value = val;
    return x;
}
void set_table(hash* h)
{   
    for(int i=0;i<h->size;i++)
    {
        node* x = create(i);
        h->hashtable[i] = x;
    }
}
int hash_func(hash* h,int key)
{
    int size = h->size;
    int index = key%size;
    return index;
}
void insert(hash* h,int key,int val)
{
    int index = hash_func(h,key);
    node* x = create(val);
    node* tmp = h->hashtable[key];
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next = x;
}
void delete(hash* h,int key,int val)
{
    int index = hash_func(h,key);
    node* tmp = h->hashtable[index]->next;
    while(tmp!=NULL && tmp->next->value!=val)
    {
        tmp=tmp->next;
    }
    node* x = tmp->next;
    tmp->next = x->next;
    free(x);
}
void main()
{
    hash* h1 = (hash*)(malloc(sizeof(hash)));
    h1->size = 10;
    h1->hashtable = (node**)(malloc(sizeof(node*)*h1->size));
    set_table(h1);
    insert(h1,1,45);
    insert(h1,4,66);
    insert(h1,0,9);
    printf("%d ",h1->hashtable[1]->next->value);
}
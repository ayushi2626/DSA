#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;

node* create_node(int num)
{
    node *n = (node*)malloc(sizeof(node));
    if(n==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    n->value = num;
    n->next = NULL;

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
void insert_end(node *root,int value)
{   
    node* ptr = root;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    node *n = (node*)malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    ptr->next  = n;
}
int length(node* root)
{   
    int i=0;
    while(root!=NULL)
    {
        i++;
        root=root->next;
    }
    return i;
}
node* merge(node* tmp,node* tmp2)
{   
    if(tmp==NULL) return tmp2;
    if(tmp2==NULL) return tmp;

    node* list=NULL;
    node* l=list;
    node* root2 = tmp2;
    while(tmp!=NULL && tmp2!=NULL && tmp!=root2)
    {
        if(tmp->value<=tmp2->value)
        {   
            list  = tmp;
            list->next= NULL;
            list=list->next;
            tmp=tmp->next;
        }
        else
        {
            list=tmp2;
            list->next = NULL;
            list=list->next;
            tmp2=tmp2->next;
        }
    }
    while(tmp!=NULL && tmp!=root2)
    {
        list=tmp;
        list->next = NULL;
        list=list->next;
        tmp=tmp->next;
    }
    while(tmp2!=NULL)
    {
        list=tmp2;
        list->next=NULL;
        list=list->next;
        tmp2=tmp2->next;
    }
    return l;
}
void split(node* root,node* a,node* b)
{
    node* now = root;
    int n = length(root);
    int i =0;
    while(i<n/2)
    {
        i++;
        now = now->next;
    }
    b = now;
    a = root;
    node* tmpptr = a;
    while(tmpptr->value!=b->value)
    {
        tmpptr=tmpptr->next;
    }
    tmpptr = NULL;
    print_list(b);
    printf("\n");
    print_list(a);
} 
void merge_sort(node* root)
{   
    if(length(root)==0 || length(root)==1) return; 
    node* a=NULL;
    node* b = NULL;
    split(root,a,b);        
    merge_sort(a);
    merge_sort(b);
    root = merge(a,b); 
}
void main()
{
    node *list=NULL;  
    node *n = create_node(2);
    list = n;
    insert_end(list,4);
    insert_end(list,3);
    insert_end(list,1);
    insert_end(list,5);
    merge_sort(list);
     
}
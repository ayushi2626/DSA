#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int value;
    int coeff;
    struct node* next;
}node;
node* create_node(int num,int c)
{
    node *n = (node*)malloc(sizeof(node));
    if(n==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    n->value = num;
    n->coeff = c;
    n->next = NULL;

    return n;
}
void print_list(node *ptr)
{
    node *tmp=ptr;
    while(tmp!=NULL)
    {
        printf("%dx^%d+ ",tmp->value,tmp->coeff);
        tmp=tmp->next;
    }
}
void insert_end(node *root,int value,int c)
{   
    node* ptr = root;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    node *n = (node*)malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    n->coeff = c;
    ptr->next  = n;
}
void add(node* eq1,node* eq2)
{
    node* tmp = eq1;
    node* tmp2 = eq2;
    while(tmp!=NULL && tmp2!=NULL)
    {   
        if(tmp->coeff<tmp2->coeff)
        {
            printf("%dx^%d+ ",tmp2->value,tmp2->coeff);
            tmp2=tmp2->next;
        }
        else if(tmp->coeff == tmp2->coeff)
        {
            printf("%dx^%d+ ",tmp->value+tmp2->value,tmp->coeff);
            tmp=tmp->next;
            tmp2=tmp2->next;
        }
        else{
            printf("%dx^%d+ ",tmp->value,tmp->coeff);
            tmp=tmp->next;
        }
    }
}
void main()
{
    node* eq1=NULL;
    node* n = create_node(4,1);
    eq1=n;
    insert_end(eq1,2,0);
    node* eq2 = NULL;
    node*n2 = create_node(5,2);
    eq2 = n2;
    insert_end(eq2,-3,1);
    insert_end(eq2,10,0);
    add(eq1,eq2);
}
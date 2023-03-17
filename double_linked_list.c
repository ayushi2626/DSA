#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *prev;
    struct node *next;
}
node;


node* make_node(int x)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->number = x;
    temp->prev = NULL;
    temp->next = NULL;
    
    return temp;
}
node* insert_at_head(node *head,int x)
{   

    node* tmp = make_node(x);
    if(head==NULL)
    {
        head = tmp;
        return head;
        
    }
    head->prev = tmp;
    tmp->next = head;
    head = tmp;
    return head;    
}

void print_list(node *head)
{
    node *tmp = head;
    if(tmp==NULL)
    {
        printf("Empty list");
        return;
    }
    printf("\nForward pass\n");
    while(tmp!=NULL)
    {
        printf("%d->",tmp->number);
        tmp=tmp->next;
    }
}

void print_reverse(node *head)
{
    node *tmp = head;
    printf("\nBackward pass\n");
    while(tmp->next!=NULL)
    {
        tmp = tmp->next;
    }
    while(tmp!=NULL)
    {
        printf("%d->",tmp->number);
        tmp=tmp->prev;
    }   
    
}

node* insert_at_end(node *head,int x)
{
    node *tmp = head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    node *tmp2= (node*)malloc(sizeof(node));
    tmp2->number = x;
    tmp2->prev = tmp;
    tmp->next = tmp2;
    tmp2->next = NULL;
    return head;
    
}

node* del_start(node *head)
{
    node *tmp = head;
    head = head->next;
    head->prev = NULL;
    free(tmp);
    return head;    

}

node* del_end(node *head)
{
    node *ptr = head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    node *tmp = ptr;
    ptr = ptr->prev;
    ptr->next = NULL;
    free(tmp);
    return head;
    
}

node* insert_at_pos(node *head,int num,int pos)
{   
    node *tmp2 = (node*)malloc(sizeof(node));
    tmp2->number = num;
    node *tmp = head;
    int i = 1;
    while(tmp!=NULL && i!=pos -1)
    {
        tmp = tmp->next;
        i++;
    }
    tmp2->prev = tmp;
    tmp2->next = tmp->next;
    tmp->next->prev = tmp2;
    tmp->next = tmp2;
    return head;
    
}

node* del_at_pos(node *head,int pos)
{
    int i=1;
    node *tmp = head;
    while(tmp!=NULL && i!=pos-1){
        tmp=tmp->next;
        i+=1;
    }
    node *tmp2= tmp->next;
    tmp->next->next->prev  = tmp; 
    tmp->next = tmp->next->next;
    free(tmp2);
    return head;    
}

int search(node *ptr,int num)
{
    int i=0;
    node *tmp = ptr;
    while(tmp!=NULL)
    {   
        if(tmp->number!=num)
        {
            tmp = tmp->next;
            i++;
        }
        else
        {return i+1;}
    
    }
    return -1;
}
node* rotate(node* r,int k)
{
    int i=0;
    node* tmp;
    node* root=r;
    while(root!=NULL)
    {
        if(i==k-1)
        {
            tmp=root;
            break;  
        }
        root=root->next;
        i++;
    }
    node* x=tmp->next;
    while(x->next!=NULL)
    {
        x=x->next;
    }
    x->next = r;
    x->prev=NULL;
    r->prev=x;
    node* y=tmp->next;
    tmp->next= NULL;
    return y;
}
node* reverse_block(node* head,int k)
{
    node* tmp=head;
    node* new = NULL;
    node* n =new;
    new->prev = NULL;
    while(tmp!=NULL)
    {
        int i=0;
        node* next;
        while(i<k)
        {
            tmp=tmp->next;
            i++;
        }
        next = tmp->next;
        while(i>=0)
        {
            new=tmp;
            tmp=tmp->prev;
            new->next = NULL;
            new=new->next;
            i--;
        }
        tmp = next;
    }
    return n;
}
node* reverse(node* root)
{
    node* tmp=NULL;
    node* t=tmp;
    node* dummy = NULL;
    while(root->next!=NULL)
    {
        root=root->next;
    }
    while(root!=NULL)
    {
        tmp = root;
        tmp->next = NULL;
        root = root->prev;
        tmp->prev = dummy;
        dummy = tmp;
        tmp=tmp->next;
    }
    return t; 
}
void main()
{
    node *head=NULL;
    node *n = make_node(1);
    head = n;
    head = insert_at_head(head,3);
    head = insert_at_end(head,6);
    head = insert_at_end(head,9);
    head = insert_at_end(head,7);
    head = insert_at_end(head,3);
    head = insert_at_end(head,6);
    head = insert_at_end(head,99);
    head = insert_at_end(head,25);
    head = reverse(head);
    print_list(head);    
}
 
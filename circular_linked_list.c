#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node* next;
}node;

node* create(int value)
{
    node* x =(node*)malloc(sizeof(node));
    x->next=x;
    x->val=value;
    return x;
}
node* insert_end(node* root,int value)
{   
    node* x=create(value);
    if(root==NULL)
    {
        root = x;
        return NULL;
    }
    node* y = root->next;
    root->next = x;
    x->next = y;
    return x;
}
node* insert_front(node* root,int val)
{
    node* x = create(val);
    node* tmp=root->next;
    root->next = x;
    x->next = tmp;
    return root;
}
void print_list(node* root)
{
    node* tmp = root->next;
    if(root==NULL)
    {
        printf("%d",-1);
        return;
    }
    do
    {   
        printf("%d->",tmp->val);
        tmp = tmp->next;

    }while(tmp!=root->next);
}
void insert_pos(node* root,int val,int pos)
{   
    if(root==NULL)
    {
        root = create(val);
    }
    if(pos!=1 && root!=NULL)
    {
        int p=0;
        node* tmp = root->next;
        while(tmp!=root && p<pos-2)
        {
            tmp=tmp->next;
            p++;
        }
        node* x = create(val);
        node* t2 = tmp->next;
        tmp->next = x;
        x->next = t2; 
    }
    else{
        node* x = root->next;
        root->next = create(val);
        root->next->next = x;
    }   
}
node* delete_pos(node* root, int pos)
{  
    if(pos==-1){
        node* tmp= root;
        do
        {
            tmp=tmp->next;
        } while (tmp->next!=root);
        node* x = tmp->next;
        tmp->next = x->next;
        free(x);
        root = tmp;
        return root;
    } 
    int i=-1;
    node* tmp=root;
    do{
        tmp=tmp->next;
        i++;
    }while(i<pos && tmp!=root);
    if(tmp->next==root)
    {
        node* x = tmp->next;
        tmp->next = x->next;
        free(x);
        return tmp;
    }
    node* x = tmp->next;
    tmp->next = x->next;
    free(x);
    return root;
    
}
int length(node* root)
{
    int i=1;
    node* tmp;
    do
    {
        i++;
        tmp = tmp->next;
    } while(tmp!=root);
    return i;
    
}
int check(node* root1,node* root2)
{
    int n1=length(root1);
    int n2 = length(root2);
    for(int i=0;i<n1;i++)
    {
        while(root2!=NULL)
        {
            if(root1->val!=root2->val)
            {
                root2=root2->next;
                continue;
            }
            else{
                root2=root2->next;
                root1=root1->next;
            }
        }
    }
}
void main()
{   /**dequeue**/
    node* circular = create(5);
    circular = insert_end(circular,4);
    circular = insert_end(circular,9);
    circular = insert_end(circular,26);
    circular = insert_end(circular,45);
    circular = insert_end(circular,199);
    circular = insert_front(circular,0);
    print_list(circular);
}
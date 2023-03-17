#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}node;
node* create_node(int val)
{
    node* n = (node*)malloc(sizeof(node));
    n->next = NULL;
    n->value = val;
    return n;
}

void insert_at_end(node* n, int val)
{
    node* tmp = n;
    while(tmp->next!=NULL)
    {
        tmp = tmp->next;
    }
    node* new = create_node(val);
    tmp->next = new;
    tmp->next->next = NULL;
}
void print_list(node* root)
{
    node* tmp = root;
    while(tmp!=NULL)
    {
        printf("%d->",tmp->value);
        tmp=tmp->next;
    }
}
int length(node* root)
{
    int i=0;
    while(root!=NULL)
    {
        i++;
        root = root->next;
    }
    return i;
}
int pallindrome(node* root)
{      
    int arr[length(root)];
    node* tmp = root;
    int i=0;
    while(tmp!=NULL)
    {
        arr[i] = tmp->value;
        i++;
        tmp = tmp->next;
    }   
    tmp = root;
    int count = 0;
    for(int i=0;i<length(root)/2;i++)
    {
        if(arr[i]!=arr[length(root)-1-i])
        {
            count++;
        }
    }
    if(count==0) return 1;
    else return 0;
    
}
node* dup_sort(node* root)
{
    node* new = root;
    node* tmp;
    while(new->next!=NULL)
    {
        if(new->value==new->next->value)
        {
            tmp = new->next->next;
            free(new->next);
            new->next = tmp;
        }
        else 
        {
            new=new->next;
        }
    }
    return root;
}
node* del_nodes(node* root,int m, int n)
{
    int i=0;
    int j=0;
    node* tmp=root;
    while(tmp!=NULL)
    {
        while((i+1)%m==0 && j<n && tmp->next!=NULL)
        {
            node* t1 = tmp->next->next;
            free(tmp->next);
            tmp->next = t1;
            j++;
        }
        i++;
        tmp =tmp->next;
        j=0;
    }
    return root;
}

node* del_all_occ(node* root)
{
    node* tmp  = root;
    while(tmp->next!=NULL)
    {
        while(tmp->next->value == tmp->value)
        {
            node* t1 = tmp->next;
            tmp->next = t1->next;
            free(t1);
        }
        tmp =tmp->next;
    }
    return root;
}
void main()
{
    node* root = NULL;
    node* n = create_node(1);
    root=n;
    insert_at_end(root,2);
    insert_at_end(root,3);
    insert_at_end(root,4);
    insert_at_end(root,2);
    insert_at_end(root,6);
    insert_at_end(root,7);
    insert_at_end(root,9);
    insert_at_end(root,9);
    node* new = del_all_occ(root);
    print_list(new);
}
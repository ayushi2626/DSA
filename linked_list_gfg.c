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
void mid_element(node* root)
{
    int i=0;
    node* tmp =root;
    while(tmp!=NULL)
    {
        i++;
        tmp=tmp->next;
    } 
    int mid= i/2;
    i=0;
    tmp=root;
    while(tmp!=NULL)
    {
        if(i==mid)
        {
            printf("%d",tmp->value);
            break;
        }
        i++;
        tmp=tmp->next;
    }
}
node* reverse(node* root)
{
    node* prev=NULL;
    node* curr = root;
    while(curr!=NULL)
    {
        node* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr= tmp;
    }
    return prev;
}


node* reverse_index(node* root,int index)
{
    int i=1;
    node* tmp = root;
    while(tmp!=NULL)
    {
        if(i==index-1)
        {
            node* tmp2 = reverse(tmp->next);
            tmp->next = tmp2;
            break;
        }
        i++;
        tmp = tmp->next;
    }
    return root;
}
node* reverse_1(node* root,int start)
{
    int i=0;
    node* tmp =root;
    node* prev=NULL;
    node* curr = NULL;
    while(tmp!=NULL)
    {
        if(i==start-2)
        {   
            prev= tmp;
            curr = tmp->next;
            node* t2 = curr->next;
            node* t1 = t2->next;

            prev->next =  t2;
            curr->next = t1;
            t2->next = curr;                  
            break;
        }
        i++;
        tmp=tmp->next;
    }
    return root;
}
node* reverse_2(node* root,int k)
{
    if(root==NULL) return NULL;
    else
    {
        node* prev = NULL;
        node* curr = root;
        node* next = NULL;
        int i=0;

        while(curr!=NULL && i<k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        node* tmp = next;
        int j=0;
        while(next!=NULL && j<k)
        {   
            next=next->next;
            j++;
        }
        if(next!=NULL) tmp->next = reverse_2(next,k);

        return prev;
    }
}

node* merge(node* root1,node* root2)
{
    node* m_list=NULL;
    node* ptr = m_list;

    while(root1!=NULL && root2!=NULL)
    {
        if(root1->value<=root2->value)
        {   
            ptr->value = root1->value;
            ptr->next = NULL;
            ptr = ptr->next;
            root1=root1->next;
        }
        else
        {
            ptr->value = root2->value;
            ptr->next = NULL;
            ptr = ptr->next;
            root2=root2->next;
        }
    }
    
    while(root1!=NULL)
    {
        node* y= create_node(root1->value);
        ptr = y;
        ptr = ptr->next;
        root1=root1->next;
    }
    while(root2!=NULL)
    {
        node* y = create_node(root2->value);
        ptr = y;
        ptr = ptr->next;
        root2=root2->next;
    }
    return m_list;
}
void main()
{
    node* root = NULL;
    node* n = create_node(1);
    root=n;
    insert_at_end(root,2);
    insert_at_end(root,3);
    insert_at_end(root,4);
    insert_at_end(root,5);
    insert_at_end(root,6);
    insert_at_end(root,47);

    node* root1 = NULL;
    node* n1 = create_node(11);
    root1=n1;
    insert_at_end(root1,12);
    insert_at_end(root1,13);
    insert_at_end(root1,14);
    insert_at_end(root1,15);
    insert_at_end(root1,56);
    insert_at_end(root1,97);

    node* merged = merge(root,root1);

    print_list(merged);
}

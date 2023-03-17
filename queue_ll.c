#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* next;
    int val;
}node;

node* new_node(int value)
{
    node* n = (node*)(malloc(sizeof(node)));
    n->next = NULL;
    n->val = value;
    return n;
}
node* enqueue(node* head,node* tail,int value)
{
    if(head==NULL)
    {
        node* x = new_node(value);
        head = x;
        tail=head;
    }
    else
    {
        node* x = new_node(value);
        tail->next = x;
        tail = tail->next;
    }
    return tail;
} 
node* dequeue(node* head,node* out)
{   
    if(head!=NULL)
    {
        node* tmp = head;
        out = tmp;
        head = head->next;
        return head;
    }
}
int isEmpty(node* head,node* tail)
{
    if(tail==NULL && head==NULL) return 1;
    else return 0;
}
void print_queue(node* head)
{
    while(head!=NULL)
    {
        printf("%d->",head->val);
        head=head->next;
    }
}
node* reverse(node* head,node* tail,node* newTail,node* newHead)
{   
    while(isEmpty(head,tail))
    {
        node* x;
        node* head = dequeue(head,x);
        newHead = x;
        newHead->next = NULL;
        newhead=newHead->next;
    }
    newTail = newhead
    return newHead;
}
void main()
{
    node* head = new_node(54);
    node* tail = head;
    tail = enqueue(head,tail,56);
    tail = enqueue(head,tail,45);
    tail = enqueue(head,tail,4);
    tail = enqueue(head,tail,65);
    tail = enqueue(head,tail,74);
    tail = enqueue(head,tail,25);
    node* out;
    head = dequeue(head,out);
    print_queue(head);
}
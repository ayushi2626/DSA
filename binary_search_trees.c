#include<stdio.h>
#include<stdlib.h>

/*Struct definitions*/
typedef struct node
{
    struct node* right;
    struct node* left;
    int val;
}node;
typedef struct queue
{
    int size;
    int top;
    int rear;
    node** arr;
}queue;
typedef struct stack
{
    int size;
    int top;
    node** arr;
}stack; 
typedef struct ll
{
    int val;
    struct ll* next;
}ll;
/*Queue functions*/

int isFull(queue *q)
{
    if(q->rear==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(queue *q)
{
    if(q->top==q->rear)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(queue *q,node* val)
{
    if(isFull(q))
    {
        return;
    }
    else if(val!=NULL){
        q->rear++;
        q->arr[q->rear] = val;
    }
    else{
        return;
    }
}

node* dequeue(queue *q)
{
    node* a=NULL;
    if(isEmpty(q))
    {
        return NULL;
    }
    else{
        q->top++;
        a = q->arr[q->top];
        return a;
    
    }
}

/*Stack functions*/

int isFulls(stack *q)
{
    if(q->top==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmptys(stack *q)
{
    if(q->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack *q,node* val)
{
    if(isFulls(q))
    {
        return;
    }
    else{
        q->top++;
        q->arr[q->top] = val;   
    }
}

node* pop(stack *q)
{
    if(isEmptys(q))
    {
        return NULL;
    }
    else{
        node* a = q->arr[q->top];
        q->top--;
        return a;    
    }
}

/*BST functions*/

node* get_node(int value)
{
    node* x = (node*)(malloc(sizeof(node)));
    x->right=NULL;
    x->left = NULL;
    x->val = value;
    return x;
}
node* add_node(node* r,int val)
{  
    node* root = r; 
    if(root==NULL)
    {
        node* y = get_node(val);
        root=y;
    }
    else
    {
        if(root->val<val)
        {
            root->right = add_node(root->right,val);
        }
        else
        {
            root->left = add_node(root->left,val);
        }
    }
    return root;
}
void vadd_node(node* r,int val)
{  
    node* root = r; 
    if(root==NULL)
    {
        node* y = get_node(val);
        root=y;
    }
    else
    {
        if(root->val<val)
        {
            add_node(root->right,val);
        }
        else
        {
            add_node(root->left,val);
        }
    }
}
void print_tree(node* root)
{   
    if(root!=NULL)
    {
        printf("%d ",root->val);
        print_tree(root->left);
        print_tree(root->right);
    }
}
void inorder_traversal(node* root)
{
    if(root!=NULL)
    {
        inorder_traversal(root->left);
        printf("%d,",root->val);
        inorder_traversal(root->right);
    }
}
void preorder_traversal(node* root)
{
    if(root!=NULL)
    {   
        printf("%d,",root->val);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}
void postorder_traversal(node* root)
{
    if(root!=NULL)
    {   
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d,",root->val);
    }
}
node* search(node* root,int value)
{   
    if(root!=NULL)
    {    
        node* tmp = root;
        if(root->left->val==value || root->right->val==value) return root;
        else if(root->val<value) return search(root->right,value);
        else return search(root->left,value);
    }
    else return NULL;
}
/*
node* delete(node* root,int val)
{        
    node* x = search(root,val);
    if(x->left==NULL && x->right==NULL)
    {
        free(x);
        return NULL;
    }
    else if(x->left && !x->right)
    {
        node* tmp = x;
        x = tmp->left;
        x->left = NULL;
        free(tmp);
    }
    else if(x->right && !x->left)
    {
        node* tmp = x;
        x = tmp->left;
        x->right = NULL;
        free(tmp);
    }
    else{
        node* x = root;
        while()
    }
}*/
int height(node* root)
{   
    if(root!=NULL)
    {
        int i=height(root->left);
        int j=height(root->right);
        if(i>j) return i+1;
        else return j+1;
    }
    else return 0;
}
int balanced(node* root)
{
    if(root!=NULL)
    {
        int h1 = height(root->left);
        int h2 = height(root->right);
        if(h1!=h2) return 0;
        else return 1;
    }
}
int size(node* root)
{
    if(root==NULL) return 0;
    else return size(root->left)+ size(root->right) + 1;
}
node* max(node* root)
{   
    if(root==NULL) return root;
    if(root->right!=NULL)
    return max(root->right);
    else return root;
}
node* min(node* root)
{   
    if(root==NULL) return root;
    if(root->left!=NULL) return min(root->left);
    else return root;
}
void level_print(node* n,int k)
{   
    if(n==NULL)
    {
        return;
    }
    else if(k==1)
    {
        printf("%d ",n->val);
    }
    else{
        level_print(n->left,k-1);
        level_print(n->right,k-1);
    }
}
void level_travel(node* root,queue* q)
{   
    while(!isEmpty(q))
    {
        node* x = dequeue(q);
        printf("%d ",x->val);   
        enqueue(q,x->left);
        enqueue(q,x->right);
    }
}
void left_view(node* root,queue* q)
{   
    while(!isEmpty(q))
    {
        node* x = dequeue(q);
        node* tmp;
        printf("%d ",x->val);
        while(!isEmpty(q)) tmp = dequeue(q);
        enqueue(q,x->left);
        enqueue(q,x->right);
    }
    return;

}
void enter_left(node* root,int* arr,int level)
{   
    if(root!=NULL)
    {
        if(arr[level]==0)
        {   
            arr[level] = root->val;
        }
        enter_left(root->right,arr,level+1);/*change the relative order of the left and right tree traversal*/
        enter_left(root->left,arr,level+1);
    }

}
/*Right view*/
 
void right(node* root)
{
    int* arr = calloc(height(root),sizeof(int));
    enter_left(root,arr,0); 
    for(int i=0;i<height(root);i++)
    {
        printf("%d ",arr[i]);
    }
}
/*void bst_dll(node* root,dll* front)
{   
    dll* prev;
    if(root==NULL) return NULL;
    else{

    }
     
}*/
int length(ll* root)
{
    ll* tmp = root;
    int i=0;
    while(tmp!=NULL)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}
 
void main()
{   
    node* y = get_node(50);
    y = add_node(y,45);
    y = add_node(y,60);
    y=add_node(y,45);

    ll* x1 = (ll*)(malloc(sizeof(ll)));
    ll* x2 = (ll*)(malloc(sizeof(ll)));
    ll* x3 = (ll*)(malloc(sizeof(ll)));
    ll* x4 = (ll*)(malloc(sizeof(ll)));
    ll* x5 = (ll*)(malloc(sizeof(ll)));
    ll* x6 = (ll*)(malloc(sizeof(ll)));
    ll* x7 = (ll*)(malloc(sizeof(ll)));
    x1->val = 1;
    x2->val = 2;
    x3->val = 3;
    x4->val = 4;
    x5->val = 5;
    x6->val = 6;
    x7->val = 7;
    x1->next= x2;
    x2->next = x3;
    x3->next = x4;
    x4->next = x5;
    x5->next = x6;
    x6->next = x7;
    x7->next = NULL;

    /*
    queue* q = (queue*)(malloc(sizeof(queue)));
    q->size = size(y);
    q->arr = (node**)(malloc(sizeof(node*)*q->size));
    q->top = -1;
    q->rear = -1;
    enqueue(q,y);
    node* x = q->arr[q->rear];

    stack* st = (stack*)(malloc(sizeof(stack)));
    st->top = -1;
    st->size = size(y);
    push(st,y);*/
    node* root = list_tree(x1);
    printf("%d",root->val);

}
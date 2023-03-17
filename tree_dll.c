#include<stdio.h>
#include<stdlib.h>

typedef struct dll{
    struct dll* left;
    struct dll* right;
    int value;
}dll;
typedef struct node
{
    struct node* right;
    struct node* left;
    int val;
}node;

dll* create(int val)
{
    dll* x = (dll*)(malloc(sizeof(dll)));
    x->left=NULL;
    x->right=NULL;
    x->value= val;
    return x;
}
/*dll* insertion(dll* front,int val){
    if(front==NULL) return create(val);
    else{
        front->right = creste(val);
        front->right->left = front;
        front = front->right;
        return front;
    }
}*/
void print_list(dll* front)
{
    dll* tmp = front;
    while(tmp!=NULL)
    {
        printf("%d<->",tmp->value);
        tmp=tmp->right;
    }
}
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
void insertion(dll* front,int val)
{
    if(front==NULL) front =create(val);
    else
    {
        dll* x  = create(val);
        front->right = x;
        x->left = front;
        front = x;
    }
}
void tree_dll(node* root,int* arr,int* i)
{
    if(root==NULL) return;
    else
    {
        tree_dll(root->left,arr,i);
        arr[*(i)]=root->val;
        *i=*(i)+1;
        tree_dll(root->right,arr,i);
    }
}
int size(node* root)
{
    if(root==NULL) return 0;
    else return size(root->left)+ size(root->right) + 1;
}
void main()
{
    node* root=get_node(55);
    root = add_node(root,45);
    root= add_node(root,69);
    root = add_node(root,99);
    root=add_node(root,11);
    int s = size(root);
    int* arr=(int*)(malloc(sizeof(int)*s));
    int i=0;
    tree_dll(root,arr,&i);
    dll* front = create(0);
    dll* tmp = front;
    for(int i=0;i<s;i++)
    {
        front->right = create(arr[i]);
        front=front->right;
    }
    tmp=tmp->right;
    print_list(tmp);
}
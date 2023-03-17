#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* right;
    struct node* left;
    int val;
}node;

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
int dia(node* root)
{
    if(root!=NULL)
    {
       
        int h_l = height(root->left);
         
        int h_r = height(root->right);
        return h_l+h_r+1;
    }
    else return 0;
}
void main()
{
    node* root = get_node(40);
    root = add_node(root,55);
    root = add_node(root,30);
    root = add_node(root,66);
    root = add_node(root,99);
    root = add_node(root,0);
    root = add_node(root,100);
    root= add_node(root,35);
    root= add_node(root,39);
    float i = 24.9;
    int j =i;
    printf("%d",j);
     
}
#include<stdio.h>
#include<stdlib.h>

/*Struct definitions*/
typedef struct node
{
    struct node* right;
    struct node* left;
    int dist;
    int val;
}node;

typedef struct hash_table
{
    int* hashtable;
    int size;
}hash;

 
void insert(hash* h,int key,int val)
{
    h->hashtable[key]=val;
}

node* get_node(int val)
{
    node* x = (node*)(malloc(sizeof(node*)));
    x->val = val;
    x->left = NULL;
    x->right = NULL;
    x->dist=0;
    return x;
}
node* add_node(node* r,int val,int d)
{  
    node* root = r; 
    if(root==NULL)
    {
        node* y = get_node(val);
        root=y;
        root->dist = d;
    }
    else
    {
        if(root->val<val)
        {
            root->right = add_node(root->right,val,++d);
        }
        else
        {
            root->left = add_node(root->left,val,--d);
        }
    }
    return root;
}
void vadd_node(node* r,int val,int d)
{  
    node* root = r; 
    if(root==NULL)
    {
        node* y = get_node(val);
        root=y;
        root->dist=d;
    }
    else
    {
        if(root->val<val)
        {
            vadd_node(root->right,val,++d);
        }
        else
        {
            vadd_node(root->left,val,--d);
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
int size(node* root)
{
    if(root==NULL) return 0;
    else return size(root->left)+ size(root->right) + 1;
}
void level_print(node* n,int k,hash* h,int size)
{   
    if(n==NULL || k<=0)
    {
        return;
    }
    else if(k==1 && h->hashtable[(n->dist)+size-1]==0)
    {
        h->hashtable[n->dist+size-1] = n->val;
    }
    else{
        level_print(n->left,k-1,h,size);
        level_print(n->right,k-1,h,size);
    }
}
void bottom_print(node* n,int k,hash* h,int size)
{   
    if(n==NULL || k<=0)
    {
        return;
    }
    else if(k==1)
    {
         h->hashtable[n->dist+size-1] = n->val;
    }
     
    else{
        bottom_print(n->left,k-1,h,size);
        bottom_print(n->right,k-1,h,size);
    }
}

 
void main()
{
    node* y = get_node(50);
    y=add_node(y,95,0);
    y=add_node(y,195,0);
    y=add_node(y,956,0);
    y=add_node(y,77,0);
    y=add_node(y,40,0);
    y= add_node(y,55,0);
    y=add_node(y,79,0);
    hash* h=(hash*)(malloc(sizeof(hash)));
    h->hashtable=(int*)(calloc(size(y)+20,sizeof(int)));
    
    for(int i=1;i<=height(y);i++)
    {
        bottom_print(y,i,h,size(y));
    }

    for(int i=0;i<size(y)+20;i++)
    {   
         if(h->hashtable[i]!=0)
        printf("%d-",h->hashtable[i]);
    }    
}
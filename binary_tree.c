#include<stdio.h>
#include<stdlib.h>

int s=0;

typedef struct node
{
    struct node* left;
    struct node* right;
    int val;
}node;



node* create_node(int val)
{
    node* n = (node*)malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    return n;
}

node* insert_node(node* root,int value)
{
    if(root==NULL)
    return create_node(value);
     
    if(root->val<value)
    root->right = insert_node(root->right,value);
    else
    root->left = insert_node(root->left,value);
    return root;
    
}

void print_tree(node* root)
{   
    if(root!=NULL)
    {
        print_tree(root->left);
        printf("%d\n",root->val);
        print_tree(root->right);
    }
}

int search(node* root,int value)
{
    if(root==NULL)
    return 0;

    if(root!=NULL)
    {
        if(root->val<value)
        return search(root->right,value);

        else if(root->val>value)
        return search(root->left,value);

        else
        return 1;
    }    
}

int DFS_search(node* root,int value)
{   
    if(root!=NULL)
    {
        if(root->val>value)
        {   
            printf("%d->",root->val);
            return DFS_search(root->left,value);
        }
        else if(root->val<value)
        {   
            printf("%d->",root->val);
            return DFS_search(root->right,value);
        }
        else
        {
            return 1;
        }
   }
   return 0;
}

void DFS(node* root)
{   
    node* root2=root;
       
    if(root->left!=NULL)
        {
        printf("%d\n",root->left->val);
        root= root->left;
        DFS(root);
        }
    if(root2->right!=NULL)
        {
        printf("%d\n",root2->right->val);
        root2=root2->right;
        DFS(root2);
        }
}

void BFS(node* root)
{   if(root!=NULL)
    {
        node* root1 = root->left;
        node* root2 = root->right;        
        if(root1!=NULL)
        printf("%d\n",root1->val);
        if(root2!=NULL)
        printf("%d\n",root2->val);
        BFS(root1);
        BFS(root2);
    }
}

void sum(node* root)
{
    node* root2=root;
       
    if(root->left!=NULL)
        {
            s+=root->left->val;
            root= root->left;
            sum(root);
        }
    if(root2->right!=NULL)
        {
            s+=root2->right->val;
            root2=root2->right;
            sum(root2);
        }
}

void min(node* root)
{
    node* root2=root;
       
    if(root->left!=NULL)
        {
            if(s>=root->left->val)
            s=root->left->val;
            root= root->left;
            min(root);
        }
    if(root2->right!=NULL)
        {
            if(s>root2->right->val)
            s=root2->right->val;
            root2=root2->right;
            min(root2);
        }
}

void max(node* root)
{
    node* root2=root;
       
    if(root->left!=NULL)
        {
            if(s<=root->left->val)
            s=root->left->val;
            root= root->left;
            max(root);
        }
    if(root2->right!=NULL)
        {
            if(s<=root2->right->val)
            s=root2->right->val;
            root2=root2->right;
            max(root2);
        }
}

void main()
{
    node* tree=NULL;
    tree = insert_node(tree,10);  /* 10 is root node */
    tree = insert_node(tree,16);
    tree = insert_node(tree,6);
    tree = insert_node(tree,1);
    tree = insert_node(tree,12);
    tree = insert_node(tree,20);
    tree = insert_node(tree,0);
    tree = insert_node(tree,2);
    tree = insert_node(tree,7);
    tree = insert_node(tree,18);
    tree = insert_node(tree,100);

    max(tree);
    printf("%d",s);    
}
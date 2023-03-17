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
void print_tree(node* root)
{   
    if(root!=NULL)
    {   
        
        print_tree(root->left);
        printf("%d->",root->val);
        print_tree(root->right);
    }
}
node* find(node* root)
{
    node* tmp = root;
    while(tmp!=NULL)
    {
        if(tmp->right==NULL && tmp->left==NULL)
        {   
             
            return tmp;
        }
        else
        {   
            tmp=tmp->left;
        }
    }
    return root;
}
node* delete(node* root,int val)
{   
    node* tmp = root;
    if(tmp!=NULL)
    {
        if(tmp->val>val)
        {
            tmp->left = delete(tmp->left,val);
        }
        else if(tmp->val<val)
        {
            tmp->right = delete(tmp->right,val);
        }
        else
        {
            if(tmp->left==NULL && tmp->right==NULL)
            {
                tmp = NULL;
                return tmp;
            }
            else if(tmp->right==NULL && tmp->left!=NULL)
            {
                tmp->val = tmp->left->val;
                tmp->left = NULL;
                return tmp;
            }
            else if(tmp->right!=NULL && tmp->left==NULL)
            {
                tmp->val = tmp->right->val;
                tmp->right = NULL;
                free(tmp->right);
                return tmp;
            }
            else
            {
                node* v  = find(tmp->right);
                node* t = tmp;
                tmp = v;
                tmp->left = t->left;
                free(t);
                return tmp;
            }
        }
    }
    return tmp;
}
node* insert(node* root,int val)
{   
    node* tmp = root;   
    if(tmp==NULL)
    {
        node* x = get_node(val);
        tmp=x;
        return tmp;
    }
    if(tmp!=NULL)
    {   
         
        if(tmp->val>val)
        {
            tmp->left = insert(tmp->left,val);
        }
        else 
        {
            tmp->right = insert(tmp->right,val);
        }
    }
    return root;
}
node* make_tree(int arr[],int size)
{
    node* root = get_node(arr[0]);
    int a[size-1];
    int i=0;
    for(int j=1;j<size;j++)
    {
        if(arr[j]<arr[0])
        {
            a[i++] = arr[j];
        }
    }
    int rear = i;
    for(int j=0;j<size;j++)
    {
        if(arr[j]>arr[0])
        {
            a[i++] = arr[j];
        }
    }
    for(int i=0;i<=rear-1;i++)
    {
        root = insert(root,a[i]);
    }
    for(int i=rear;i<size-1;i++)
    {
        root = insert(root,a[i]);
    }
    return root;
}
int pred(node* r,int val)
{   
    node* root = r;
    if(root!=NULL)
    {
         
        if(root->val<val)
        {
            return pred(root->right,val);
        }
        else if(root->val>val)
        {
            return pred(root->left,val);
        }
        else
        {
            node* x = find(root->left);
            return x->val;
        }
    }
    return 0;
}
int successor(node* r,int val ,int pre)
{   
    node* root = r;
    if(root!=NULL)
    {
        if(r->val<val)
        {
            return successor(root->right,val,root->val);
        }
        else if(r->val>val)
        {
            return successor(root->left,val,root->val);
        }
        else 
        return pre;
    }
    return 0;
}
void merge(int arr[],int s,int mid, int e)
{
    int left[mid-s+1],right[e-mid];
    for(int a=0;a<mid-s;a++)
    {
        left[a] = arr[s+a];
    }
    
     for(int a=0;a<e-mid+1;a++)
    {
        right[a] = arr[mid+1+a];

    }
    int i=0,j=0,k=s;

     while((i<mid-s+1) && (j<e-mid))
    {
        if(left[i]<right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<mid-s)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j<e-mid)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
     
}
void merge_sort(int arr[],int s, int e)
{   
    if(s<e){
        int mid = (e+s)/2;
        merge_sort(arr,s,mid);
        merge_sort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
} 

void main()
{   

    node* root = get_node(40);
    root->left = get_node(55);
    root->right = get_node(6);
    root->left->left = get_node(60);
    root->right->right = get_node(99);
    
}
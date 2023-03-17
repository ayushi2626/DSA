#include<stdio.h>
#include<stdlib.h>

int f=0;
int r=6;

typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
}node;

void print_heap(int heap[])
{
    for(int i=0;i<=r;i++)
    {
        printf("%d->",heap[i]);
    }
}
void insert_heap(int heap[], int key)
{   
    int tmp_r = r;
    heap[++r] = key;
    while(heap[(r-1)/2]>key)
    {         
        int tmp = heap[(r-1)/2];
        heap[(r-1)/2] = key; 
        heap[r] = tmp; 
        r = (r-1)/2;
        
    }
    r = tmp_r+1;
}

void shift_up(int heap[],int i)
{   
    int key = heap[i];
    while(heap[(i-1)/2]>=key && heap[f]!=key && i>=0)
    {
        if(heap[(i-1)/2]>=key)
        {
            int tmp = heap[(i-1)/2];
            heap[(i-1)/2] = key;
            heap[i] = tmp;
            i = (i-1)/2;
        }
    }
}

void shift_down(int heap[],int i)
{
    int key = heap[i];
    int left = heap[2*i + 1];
    int right = heap[2*i + 2];

    while((heap[i]>heap[2*i+1] || heap[i]>heap[2*i+2]) && i<r/2)
    {
        if(heap[2*i+1]<heap[2*i+2])
        {   
            int tmp = heap[2*i+1];
            heap[2*i +1] = heap[i];
            heap[i] = tmp;
            i = 2*i + 1;
        }
        else
        {   
            int tmp = heap[2*i+2];
            heap[2*i+2] = heap[i];
            heap[i] = tmp;
            i = 2*i + 2;
        }
    }
}
void del_min(int heap[])
{
    int tmp = heap[r];
    heap[r] = heap[f];
    heap[f] = tmp;
    r-=1;
    shift_down(heap,f);
}

void del(int heap[], int i)
{
    int tmp = heap[r];
    heap[r] = heap[i];
    heap[i] = tmp;
    r--;

    if(heap[i]>heap[2*i+1] || heap[i]>heap[2*i+2])
    shift_down(heap,i);

    if(heap[i]<heap[(i-1)/2])
    shift_up(heap,i);
}

node* create_node(int val)
{
    node* n = (node*)malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->key = val;
    return n;
}

node* create_tree(int arr[],int n, int i)
{   
    node* tree=NULL;
    if(i<n)
    {
        tree = create_node(arr[i]);
        tree->left = create_tree(arr,n,2*i+1);
        tree->right = create_tree(arr,n,2*i+2);
    }
    return tree;
}

void print_tree(node* root)
{   
    if(root!=NULL)
    {
        print_tree(root->left);
        printf("%d\n",root->key);
        print_tree(root->right);
    }
}

void heapify(node* tree,int i,int arr[],int size)
{
    int n = (size-1)/2 +1;
    int largest = arr[n];
    if(arr[2*i+1]>largest)
    {
        largest = arr[2*i+1];
        int tmp = arr[n];
        arr[n] = largest;
        arr[2*i+1] = tmp;
    }
    if(arr[2*i+2]>largest)
    {
        largest = arr[2*i+2];
        int tmp = arr[n];
        arr[n] = largest;
        arr[2*i+2] = tmp;
    }
}
void heapify_2(node* tree)
{   
    node* root = tree;  
    if(root!=NULL)
    {
        int largest = root->key;
        if(root->left->key > largest)
        {
            int tmp = largest;
            largest = root->left->key;
            root->left->key = tmp;
        }
        if(root->right->key>largest)
        {
            int tmp = largest;
            largest = root->right->key;
            root->right->key = tmp;
        }
        heapify_2(root->left);
        heapify_2(root->right);
    }
}

void main()
{   
    int size=6;
    node* tree;
    int arr[] = {3,9,2,1,4,5};
    tree = create_tree(arr,size,0);
    heapify_2(tree);
    print_tree(tree);
}


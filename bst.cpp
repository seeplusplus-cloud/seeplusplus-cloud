#include<iostream>
using namespace std;

struct search{int data;search *left,*right;search(){left=NULL;right=NULL;}};

void insert(search **root,int a)
{
   search *t=new search;
   if(*root==NULL){t->data=a;*root=t;}
   else
   {
       if((*root)->data>a){insert(&((*root)->left),a);}
       else{insert(&((*root)->right),a);}
   }
   
   return;
   
}

void inorder(search *root)
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void printTree(search *root,int l)
{
    if(root==NULL){return;}
    l+=10;
    printTree(root->right,l);
    cout<<endl;
    for(int i=10;i<l;i++){cout<<" ";}
    cout<<root->data<<'\n';
    printTree(root->left,l);
}

int main()
{
    search *root=NULL;
    int a[20],n;
    cout<<"enter size ";cin>>n;
    cout<<"enter elements to enter in bst ";
    for(int i=0;i<n;i++){cin>>a[i];}
    for(int i=0;i<n;i++)
    {
        insert(&root,a[i]);
    }
    //inorder(root);
    printTree(root,0);
    cout<<"\r\n";
    return 0;
}

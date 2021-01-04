#include<iostream>
using namespace std;

struct avl{int d,b=0;avl *l=NULL,*r=NULL;};

int height(avl *root){int h=1;if(root==NULL)return 0;h+=(height(root->l)>height(root->r))?height(root->l):height(root->r);return h;}

void updatebal(avl **root)
{
    (*root)->b=height((*root)->l)-height((*root)->r);
}

void ll(avl **root)
{
    avl *a=*root,*b=a->l,*c=a->l->l,*temp=b->r;
    a->l=temp;
    b->r=a;
    *root=b;
}

void rr(avl **root)
{
    avl *a=*root,*b=a->r,*c=a->r->r,*temp=b->l;
    a->r=temp;
    b->l=a;
    *root=b;
}

void lr(avl **root)
{
    avl *a=*root,*b=a->l,*c=a->l->r,*temp=c->l;
    b->r=c->l;
    a->l=c;
    c->l=b;
    *root=a;
    ll(root);
}

void rl(avl **root)
{
    avl *a=*root,*b=a->r,*c=a->r->l,*temp=c->r;
    b->l=c->r;
    a->r=c;
    c->r=b;
    *root=a;
    rr(root);   
}

void insert(avl **root,int a)
{
    avl *t=new avl;
    if((*root)==NULL){t->d=a;*root=t;return;}
    if((*root)->d>a){insert(&((*root)->l),a);}
    else{insert(&((*root)->r),a);}
    updatebal(root);
    if((*root)->b==2)
    {
        if((*root)->l->b==1){ll(root);}
        else if((*root)->l->b==-1){lr(root);}
    }
    else if((*root)->b==-2)
    {
        if((*root)->r->b==-1){rr(root);}
        else if((*root)->r->b==1){rl(root);}
    }
    updatebal(root);
}

void printTree(avl *root,int l)
{
    if(root==NULL){return;}
    l+=10;
    printTree(root->r,l);
    cout<<endl;
    for(int i=10;i<l;i++){cout<<" ";}
    cout<<root->d<<'\n';
    printTree(root->l,l);
}

int main()
{
    avl *root=NULL;
    int a,n;
    cout<<"enter the no of elements : ";cin>>n;
    cout<<"enter the elements : ";for(int i=0;i<n;i++){cin>>a;insert(&root,a);}
    printTree(root,0);
    return 0;
}


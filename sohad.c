#include<stdio.h>
#include<stdlib.h>
struct AVL
{
    int data;
    struct AVL*right;
    struct AVL *left;
    int height;
};

int height(struct AVL*root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

int max(int a,int b)
{
    return (a>b)? a:b;
}

int getbalance(struct AVL*root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return height(root->left)-height(root->right);
    }
}

struct AVL* createNode(int x)
{
    struct AVL* newnode=(struct AVL*)malloc(sizeof(struct AVL));
    newnode->data=x;
    newnode->left=newnode->right=NULL;
    newnode->height=1;
    return newnode;
}

struct AVL*rightRotate(struct AVL*y)
{
    struct AVL *x=y->left;
    struct AVL *t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=max(height(y->left), height(y->right) )+1;
    x->height=max(height(x->left),height(x->right) )+1;


    return x;
}

struct AVL*leftRotate(struct AVL*x)
{
    struct AVL *y=x->right;
    struct AVL *t2=y->left;

    y->right=x;
    x->left=t2;

    x->height=max(height(x->left), height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;

}


struct AVL*insert(struct AVL*root,int x)
{

    if(root==NULL)
    {
        return createNode(x);
    }
    else if(x < root->data)
    {
        root->left=insert(root->left,x );
    }
    else if(x> root->data)
    {
        root->right=insert(root->right,x);
    }
    else
    {
        return root;
    }

    int balance=getbalance(root);
    if(balance > 1 && x < root->left->data)
    {
        return rightRotate(root);
    }
    if(balance <-1 && x > root->right->data)
    {
        return leftRotate(root);
    }

    if(balance > 1 && x > root->left->data)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);

    }
    if(balance < -1 && x< root->right->data)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);

    }


    return root;



}

void inorder(struct AVL*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

}

int main ()
{

    struct AVL *root=NULL;

    root=insert(root,20);
    root=insert(root,50);
    root=insert(root,54);
    root=insert(root,53);
    root=insert(root,34);
    root=insert(root,10);
    printf("inorder :");
    inorder(root);
    printf("\n");

}
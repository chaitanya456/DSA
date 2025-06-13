#include<bits/stdc++.h>
using namespace std;
struct tree *ins(int data);
void inorder(struct tree* x);
void preorder(struct tree* x);
void postorder(struct tree* x);
int size(struct tree* root);
struct tree
{
    int data;
    struct tree *left,*right;
};
struct tree *ins(int data)
{
    struct tree *temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(struct tree* x)
{
    if(!x)
    return;
    inorder(x->left);
    cout<<x->data<<" ";
    inorder(x->right);
}
void preorder(struct tree* x)
{
    if(!x)
    return;
    cout<<x->data<<" ";
    preorder(x->left);
    preorder(x->right);
}
void postorder(struct tree* x)
{
    if(!x)
    return;
    postorder(x->left);
    postorder(x->right);
    cout<<x->data<<" ";
}
int size(struct tree* root)
{
    if(!root)
    return 0;
    return 1+size(root->left)+size(root->right);
}
int main()
{
    struct tree *root=ins(1);
    root->left=ins(2);
    root->right=ins(3);
    root->left->left=ins(4);
    root->left->right=ins(5);
    root->right->right=ins(6);
    cout<<"InOrder Traversal:\t";
    inorder(root);
    cout<<endl;
    cout<<"PreOrder Traversal:\t";
    preorder(root);
    cout<<endl;
    cout<<"PostOrder Traversal:\t";
    postorder(root);
    cout<<endl;
    cout<<"Size of the tree:\t";
    cout<<size(root);
    return 0;
}
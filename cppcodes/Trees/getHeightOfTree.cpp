#include<bits/stdc++.h>
using namespace std;
struct tree *ins(int data);
void inorder(struct tree* x);
int getHeight(struct tree * root);
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
int getHeight(struct tree * root)
{
    if(!root)
    return 0;
    return 1+max(getHeight(root->left),getHeight(root->right));
}
int main()
{
    struct tree *root=ins(1);
    root->left=ins(2);
    root->right=ins(3);
    root->left->left=ins(4);
    root->left->left->left=ins(6);
    root->left->right=ins(5);
    cout<<"InOrder Traversal:\t";
    inorder(root);
    cout<<endl;
    cout<<"Height Of the tree:\t"<<getHeight(root);//If height starts from 0 then return this value-1
    return 0;
}
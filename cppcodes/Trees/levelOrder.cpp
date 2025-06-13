#include<bits/stdc++.h>
using namespace std;
struct tree *ins(int data);
void inorder(struct tree* x);
void levelOrder(struct tree * root);
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
void levelOrder(struct tree * root)
{
    queue<struct tree*> q;
    q.push(root);
    while(!q.empty())
    {
        struct tree *front=q.front();
        q.pop();
        cout<<front->data<<" ";
        if(front->left)
        q.push(front->left);
        if(front->right)
        q.push(front->right);
    }
}
int main()
{
    struct tree *root=ins(1);
    root->left=ins(2);
    root->right=ins(3);
    root->left->left=ins(4);
    root->left->right=ins(5);
    cout<<"InOrder Traversal:\t";
    inorder(root);
    cout<<endl;
    cout<<"Level Order Traversal:\t";
    levelOrder(root);
    return 0;
}
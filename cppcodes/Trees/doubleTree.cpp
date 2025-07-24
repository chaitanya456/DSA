#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left,*right;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};
void doubleTree(Node* root)
{
    Node *old;
    if(!root)
    return;
    doubleTree(root->left);
    doubleTree(root->right);
    old=root->left;
    root->left=new Node(root->data);
    root->left->left=old;   
}
void inorder(Node* root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    cout<<"Original Inorder:\t";
    inorder(root);
    cout<<endl;
    doubleTree(root);
    cout<<"Double Tree Inorder:\t";
    inorder(root);
    return 0;
}
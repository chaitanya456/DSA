#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*left,*right;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};
void inorder(Node* root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int calculateMinNode(Node* root)
{
    if(!root)
    return -1;
    while(root->left)
    root=root->left;
    return root->data;
}
int main()
{
    Node* root=new Node(8);
    root->left=new Node(5);
    root->right=new Node(12);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->left=new Node(10);
    inorder(root);
    cout<<"\nMinimum Node in BST is :\t"<<calculateMinNode(root);
    return 0;
}
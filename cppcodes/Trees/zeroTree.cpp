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
void inorder(Node* root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
int zeroTree(Node* root)
{
    if(!root)
    return 0;
    int originalData=root->data;
    root->data=zeroTree(root->left)+zeroTree(root->right);
    return root->data+originalData;
}
int main()
{
    Node* root = new Node(10); 
    root->left = new Node(-2); 
    root->right = new Node(6); 
    root->left->left = new Node(8); 
    root->left->right = new Node(-4); 
    root->right->left = new Node(7); 
    root->right->right = new Node(5); 
    cout<<"InOrder:\t";
    inorder(root);
    zeroTree(root);
    cout<<"\nInorder:\t";
    inorder(root);
    return 0;
}
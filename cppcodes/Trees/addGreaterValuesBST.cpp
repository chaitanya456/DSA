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
void func(Node* root,int &sum)
{
    if(!root)
    return;
    func(root->right,sum);
    sum+=root->data;
    root->data=sum;
    func(root->left,sum);
}
void addgreatervalues(Node* root)
{
    int sum=0;
    return func(root,sum);
}
int main()
{
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    inorder(root);
    cout<<"\nMinimum Node in BST is :\t"<<calculateMinNode(root);
    addgreatervalues(root);
    cout<<"\nAfter Adding everything, we get:\t";
    inorder(root);
    return 0;
}
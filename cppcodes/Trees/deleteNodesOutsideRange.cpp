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
void inorder(Node* a)
{
    if(!a)
    return;
    inorder(a->left);
    cout<<a->data<<" ";
    inorder(a->right);
}
Node* deleteNodes(Node* root, int min, int max)
{
    if(!root)
    return NULL;
    root->left=deleteNodes(root->left,min,max);
    root->right=deleteNodes(root->right,min,max);
    if(root->data<min)
    return root->right;
    else if(root->data>max)
    return root->left;
    return root;
}
int main()
{
    Node* root = new Node(6);
    root->left = new Node(-13);
    root->right = new Node(14);
    root->left->right = new Node(-8);
    root->right->left=new Node(13);
    root->right->left->left=new Node(7);
    root->right->right=new Node(15);
    int n1=-10,n2=13;
    cout<<"Original Tree:\t";
    inorder(root);
    root=deleteNodes(root,n1,n2);
    cout<<"\nAfter deleting Nodes of this range -10 and 13:\t";
    inorder(root);
    return 0;
}
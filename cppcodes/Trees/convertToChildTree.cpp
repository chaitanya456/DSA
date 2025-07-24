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
void increment(Node* root, int diff)
{
    if(root->left)
    {
        root->left->data+=diff;
        increment(root->left,diff);
    }
    else if(root->right)
    {
        root->right->data+=diff;
        increment(root->right,diff);
    }
}
void inorder(Node* root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void convert(Node* root)
{
    if(!root)
    return;
    else if(!root->left && !root->right)
    return ;
    convert(root->left);
    convert(root->right);
    int diff=(((root->left)?root->left->data:0)+((root->right)?root->right->data:0))-root->data;
    if(diff>0)
    root->data+=diff;
    else if(diff<0)
    increment(root,-diff);
}
int main()
{
    Node *root = new Node(50); 
    root->left = new Node(7); 
    root->right = new Node(2); 
    root->left->left = new Node(3); 
    root->left->right = new Node(5); 
    root->right->left = new Node(1); 
    root->right->right = new Node(30); 
    cout<<"Original Tree:\t";
    inorder(root);
    cout<<endl<<"After Conversion:\t";
    convert(root);
    inorder(root);
    return 0;
}
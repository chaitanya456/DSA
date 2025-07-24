#include<bits/stdc++.h>
using namespace std;
vector<int>res;
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
int getSize(Node* root)
{
    if(!root)
    return 0;
    return 1+getSize(root->left)+getSize(root->right);
}
bool isLeaf(Node* a)
{
    return (!a->left && !a->right);
}
void printLeft(Node * root)
{
    if(!root || isLeaf(root))
    return;
    res.push_back(root->data);
    if(root->left)
    printLeft(root->left);
    else if(root->right)
    printLeft(root->right);
}
void printLeaves(Node* root)
{
    if(!root)
    return;
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}
void printRight(Node * root)
{
    if(!root || isLeaf(root))
    return;
    if(root->right)
    printRight(root->right);
    else if(root->left)
    printRight(root->left);
    res.push_back(root->data);
}
void boundaryTraversal(Node* root)
{
    if(!root)
    return ;
    if(!isLeaf(root))
    res.push_back(root->data);
    printLeft(root->left);
    printLeaves(root);
    printRight(root->right);
}
void inorder(Node* root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void mirror(Node* root)
{
    if(!root)
    return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    
    // cout<<"Size of the Tree:\t"<<getSize(root);
    // boundaryTraversal(root);
    // cout<<"Boundary Traversal:\t";
    // for(auto x:res)
    // cout<<x<<" ";
    cout<<"Original Inorder:\t";
    inorder(root);
    cout<<"\nAfter Mirroring:\t";
    mirror(root);
    inorder(root);
    return 0;
}
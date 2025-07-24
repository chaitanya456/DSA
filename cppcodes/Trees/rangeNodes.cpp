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
void appendNodes(Node* root, int n1,int n2, vector<int>&res)
{
    if(!root)
    return;
    if(root->data>=n1 && root->data<=n2)
    {
        res.push_back(root->data);
        appendNodes(root->left,n1,n2,res);
        appendNodes(root->right,n1,n2,res);
    }
    else if(root->data<n1)
    appendNodes(root->left,n1,n2,res);
    else appendNodes(root->left,n1,n2,res);
}
int main()
{
    Node* root = new Node(22);
    root->left = new Node(12);
    root->right = new Node(30);
    root->left->left = new Node(8);
    root->left->right = new Node(20);
    int n1=10,n2=22;
    vector<int>res;
    appendNodes(root,n1,n2,res);
    cout<<"Nodes of this range:\t";
    for(auto x: res)
    cout<<x<<" ";
    return 0;
}
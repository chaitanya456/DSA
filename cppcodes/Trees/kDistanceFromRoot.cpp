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
void printKDistance(Node* root, int k)
{
    if(k<0 ||!root)
    return;
    if(k==0)
    res.push_back(root->data);
    printKDistance(root->left,k-1);
    printKDistance(root->right,k-1);
}
int main()
{
    
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->right->left=new Node(8);
    root->left->right->right=new Node(9);
    root->left->left=new Node(4);
    root->left->left->left=new Node(7);
    root->left->left->left->right=new Node(11);
    root->left->left->left->right->left=new Node(13);
    root->right->right=new Node(6);
    root->right->right->right=new Node(10);
    root->right->right->right->left=new Node(12);
    int k=3;
    printKDistance(root,k);
    cout<<"Nodes that are K distance from root are:\t";
    for(auto x:res)
    cout<<x<<" ";
    // cout<<"Size of the Tree:\t"<<getSize(root);
    return 0;
}
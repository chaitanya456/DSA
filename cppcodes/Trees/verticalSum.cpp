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
void verticalSumUtil(Node* root, int i, map<int,int> &m)
{
    if(!root)
    return ;
    verticalSumUtil(root->left,i-1,m);
    m[i]+=root->data;
    verticalSumUtil(root->right,i+1,m);
}
void verticalSum(Node* root)
{
    map<int,int> m;
    verticalSumUtil(root,0,m);
    cout<<"Vertical Sums:\t";
    for(auto x: m)
    cout<<x.second<<" ";
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    verticalSum(root);
    return 0;
}
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
int getHeight(Node* root)
{
    if(!root)
    return -1;
    return 1+max(getHeight(root->left),getHeight(root->right));
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    cout<<"Height Of a Tree:\t"<<getHeight(root)<<endl;
    return 0;
}
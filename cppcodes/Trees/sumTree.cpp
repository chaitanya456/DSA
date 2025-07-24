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
bool isLeaf(Node *a)
{
    return (!a->left && !a->right);
}
bool isSumTree(Node* root)
{
    if(!root || isLeaf(root))
    return 1;
    if(isSumTree(root->left) && isSumTree(root->right))
    {
        int ls,rs;
        if(!root->left)
        ls=0;
        else if(isLeaf(root->left))
        ls=root->left->data;
        else ls=2*(root->left->data);

        if(!root->right)
        rs=0;
        else if(isLeaf(root->right))
        rs=root->right->data;
        else rs=2*(root->right->data);//Instead of computing, we can use this variable.
        return (ls+rs==root->data);
    }
    return 0;
}
int main()
{
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    if(isSumTree(root))
    cout<<"Yes, It is a sum tree!";
    else cout<<"No, It is not a sum tree!";
    return 0;
}
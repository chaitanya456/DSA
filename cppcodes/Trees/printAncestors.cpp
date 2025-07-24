#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};
bool printAncestors(Node* root, int key)
{
    if(!root)
    return 0;
    if(root->data==key)
    return 1;
    if(printAncestors(root->left,key) || printAncestors(root->right,key))
    {
        cout<<root->data<<" ";
        return 1;
    }
    return 0;
}
int main()
{
    Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left  = new Node(7);
    printAncestors(root,7);
    return 0;
}
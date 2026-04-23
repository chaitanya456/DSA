#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left,*right;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};

void print(Node* root)
{
    while(root)
    {
        cout<<root->data<<"->";
        root=root->right;
    }
}
void convert(Node* root, Node* &prev)
{
    if(!root)
    return;
    convert(root->right,prev);
    convert(root->left,prev);
    root->right=prev;
    root->left=NULL;
    prev=root;
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->right=new Node(5);
    cout<<"Before Conversion:\t";
    print(root);
    Node* prev=NULL;
    convert(root, prev);
    cout<<"\nAfter Converting BT to LL:\t";
    print(root);
    return 0;
}
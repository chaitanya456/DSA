#include<bits/stdc++.h>
using namespace std;
pair<int,int>res;
class Node
{
    public:
    int data;
    Node* left,*right,*next;
    Node(int x)
    {
        data=x;
        left=right=next=NULL;
    }
};
void inOrderSuccessors(Node* root)
{
    static Node* prev=NULL;
    if(!root)
    return;
    inOrderSuccessors(root->left);
    if(prev)
    prev->next=root;
    prev=root;
    inOrderSuccessors(root->right);
}
void print(Node*root)
{
    if(!root)
    return;
    print(root->left);
    cout<<"In Order Successor of "<<root->data<<"->";
    if(root->next)
    cout<<root->next->data<<endl;
    else cout<<"-1"<<endl;
    print(root->right);
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(8);
    root->right=new Node(12);
    root->left->left=new Node(3);
    inOrderSuccessors(root);
    print(root);
    return 0;
}
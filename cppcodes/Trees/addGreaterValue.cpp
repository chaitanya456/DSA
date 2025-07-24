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
void addGreater(Node* root, int *sum)
{
    if(!root)
    return;
    addGreater(root->right,sum);
    *sum+=root->data;
    root->data=*sum;
    addGreater(root->left,sum);
}
void inorder(Node* root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    Node* root=new Node(5);
    root->left=new Node(2);
    root->right=new Node(13);
    cout<<"Inorder:\t";
    inorder(root);
    cout<<"\nAfter Adding greater values:\t";
    int s=0;
    addGreater(root,&s);
    inorder(root);
    return 0;
}
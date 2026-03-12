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
    left=NULL;
    right=NULL;
  }  
};
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
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->right=new Node(6);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    inorder(root);
    return 0;
}
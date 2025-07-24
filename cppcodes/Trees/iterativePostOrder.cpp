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
void printPostOrder(Node* root)
{
    cout<<"PostOrder Traversal Iterative:\t";
    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty())
    {
        Node* top=st1.top();
        st1.pop();
        st2.push(top);
        if(top->left)
        st1.push(top->left);
        if(top->right)
        st1.push(top->right);
    }
    while(!st2.empty())
    {
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    printPostOrder(root);
    return 0;
}
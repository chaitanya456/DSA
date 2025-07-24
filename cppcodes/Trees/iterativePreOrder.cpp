//single stack is enough root push, pop and print, insert right and then left.

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
void printPreOrder(Node* root)
{
    cout<<"PreOrder Traversal Iterative:\t";
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node*  k=st.top();
        st.pop();
        cout<<k->data<<" ";
        if(k->right)
        st.push(k->right);
        if(k->left)
        st.push(k->left);
    }
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    printPreOrder(root);
    return 0;
}
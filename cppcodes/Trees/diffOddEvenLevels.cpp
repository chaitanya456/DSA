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
int getSize(Node* root)
{
    if(!root)
    return 0;
    return 1+getSize(root->left)+getSize(root->right);
}
void diff(Node * root)
{
    queue<Node*>q;
    q.push(root);
    bool flag=1;
    int oddSum=0,evenSum=0;
    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            Node* k=q.front();
            q.pop();
            if(flag)
            oddSum+=k->data;
            else
            evenSum+=k->data;
            if(k->left)
            q.push(k->left);
            if(k->right)
            q.push(k->right);
        }
        flag=!flag;
    }
    cout<<"Difference of even and odd levels is:\t"<<(oddSum-evenSum);
}
int main()
{
    Node* root=new Node(10);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    // cout<<"Size of the Tree:\t"<<getSize(root);
    diff(root);
    return 0;
}
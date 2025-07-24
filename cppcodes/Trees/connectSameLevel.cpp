#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left,*right,*nextRight;
    Node(int x)
    {
        data=x;
        left=right=nextRight=NULL;
    }
};
void connectNodes(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int i=0,size=q.size();
        Node* prev=NULL;
        while(i<size)
        {
            Node* cur=q.front();
            q.pop();
            if(prev)
            prev->nextRight=cur;
            prev=cur;
            if(cur->left)
            q.push(cur->left);
            if(cur->right)
            q.push(cur->right);
            i++;
        }
        prev->nextRight=NULL;
    }
}
void printNextRight(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size(),i=0;
        cout<<q.front()->data<<"->";
        while(i<size)
        {
            Node* k=q.front();
            q.pop();
            if(!k->nextRight)
            cout<<"NULL";
            else cout<<k->nextRight->data<<"->";
            if(k->left)
            q.push(k->left);
            if(k->right)
            q.push(k->right);
            i++;
        }
        cout<<endl;
    }
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);
    connectNodes(root);
    printNextRight(root);
    return 0;
}
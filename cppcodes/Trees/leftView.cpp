#include<bits/stdc++.h>
using namespace std;
vector<int>res;
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
bool isLeaf(Node* a)
{
    return (!a->left && !a->right);
}
void printLeft(Node * root)
{
    if(!root || isLeaf(root))
    return;
    res.push_back(root->data);
    if(root->left)
    printLeft(root->left);
    else if(root->right)
    printLeft(root->right);
}
void printLeaves(Node* root)
{
    if(!root)
    return;
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}
void printRight(Node * root)
{
    if(!root || isLeaf(root))
    return;
    if(root->right)
    printRight(root->right);
    else if(root->left)
    printRight(root->left);
    res.push_back(root->data);
}
void boundaryTraversal(Node* root)
{
    if(!root)
    return ;
    if(!isLeaf(root))
    res.push_back(root->data);
    printLeft(root->left);
    printLeaves(root);
    printRight(root->right);
}
void printLeftView(Node* root)
{
    queue<Node*>q;
    int i;
    vector<int>res;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(i=0;i<n;i++)
        {
            Node* k=q.front();
            q.pop();
            if(i==0)
            res.push_back(k->data);
            if(k->left)
            q.push(k->left);
            if(k->right)
            q.push(k->right);
        }
    }
    cout<<"Left View of Binary Tree:\t";
    for(auto x: res)
    cout<<x<<" ";

}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->right->left=new Node(8);
    root->left->right->right=new Node(9);
    root->left->left=new Node(4);
    root->left->left->left=new Node(7);
    root->left->left->left->right=new Node(11);
    root->left->left->left->right->left=new Node(13);
    root->right->right=new Node(6);
    root->right->right->right=new Node(10);
    root->right->right->right->left=new Node(12);
    printLeftView(root);
    return 0;
}
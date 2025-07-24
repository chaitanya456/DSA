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
bool isIsomorphic(Node* a, Node* b)
{
    if(!a && !b)
    return 1;
    if(!a || !b)
    return 0;
    if(a->data!=b->data)
    return 0;
    return (isIsomorphic(a->left,b->left) && isIsomorphic(a->right,b->right)) || (isIsomorphic(a->left,b->right) && isIsomorphic(a->right,b->left));
}
int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left=new Node(6);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(7);
    root1->left->right->right = new Node(8);
    // cout<<"Size of the Tree:\t"<<getSize(root);
    // boundaryTraversal(root);
    // cout<<"Boundary Traversal:\t";
    // for(auto x:res)
    // cout<<x<<" ";
    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->left->right = new Node(6);
    root2->right->left = new Node(4);
    root2->right->right = new Node(5);
    root2->right->right->left = new Node(8);
    root2->right->right->right = new Node(7);
    if(isIsomorphic(root1,root2))
    cout<<"Yes, Trees are isomorphic";
    else cout<<"No, The trees are not isomorphic";
    return 0;
}
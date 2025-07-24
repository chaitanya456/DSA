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
bool foundPath(Node* root, int k, vector<Node*>&path)
{
    if(!root)
    return 0;
    path.push_back(root);
    if(root->data==k || foundPath(root->left,k,path)||foundPath(root->right,k,path))
    return 1;
    path.pop_back();
    return 0;
}
Node* lca(Node* root, int n1, int n2)
{
    vector<Node*> path1,path2;
    if(!foundPath(root,n1,path1)|| !foundPath(root,n2,path2))
    return NULL;
    int i;
    for(i=0;i<path1.size()&& i<path2.size();i++)
    if(path1[i]!=path2[i])
    return path1[i-1];
    return path1[i-1];
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
    Node* l=lca(root,8,9);
    if(l)
    cout<<"Ancestor Found:\t"<<l->data;
    else cout<<"Ancestor Not Found";
    return 0;
}
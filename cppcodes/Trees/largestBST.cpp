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
bool isLeaf(Node* root)
{
    return (!root->left && !root->right);
}
vector<int> func(Node* root)
{
    if(!root)
    return {INT_MAX,INT_MIN,0};
    if(isLeaf(root))
    return {root->data, root->data,1};
    vector<int> left=func(root->left);
    vector<int> right=func(root->right);
    vector<int>ans(3);
    if(left[1]<root->data && right[0]>root->data) //BST Condition
    {
        ans[0]=min(root->data,left[0]);
        ans[1]=max(right[1],root->data);
        ans[2]=left[2]+1+right[2];
        return ans;
    }
    ans[0]=INT_MIN;
    ans[1]=INT_MAX;
    ans[2]=max(left[2],right[2]);
    return ans;
}
int largestBST(Node* root)
{
    return func(root)[2];
}
int main()
{
    Node* root=new Node(50);
    root->left=new Node(75);
    root->right=new Node(45);
    root->left->left=new Node(40);
    cout<<"Largest BST in given Binary tree:\t"<<largestBST(root);
    return 0;
}
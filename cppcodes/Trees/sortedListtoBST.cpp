#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
       next=NULL;
    }
};
class TreeNode
{
    public:
    int data;
    TreeNode* left,*right;
    TreeNode(int x)
    {
        data=x;
        left=right=NULL;
    }
};
TreeNode* func(vector<int>&a, int start, int end)
{
    if(start>end) return NULL;
    int mid=(start)+(end-start)/2;
    if((end-start)%2) mid++;
    TreeNode* root=new TreeNode(a[mid]);
    root->left=func(a,start,mid-1);
    root->right=func(a,mid+1,end);
    return root;
}
void preorder(TreeNode* root)
{
    if(!root)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=new Node(7);
    vector<int> temp;
    while(head)
    {
        temp.push_back(head->data);
        head=head->next;
    }
    TreeNode* root=func(temp,0,temp.size()-1);
    preorder(root);
    return 0;
}
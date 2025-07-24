#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
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
void printAllPaths(Node* root)
{
    if(!root)
    return;
    res.push_back(root->data);
    if(!root->left && !root->right)
    ans.push_back(res);
    printAllPaths(root->left);
    printAllPaths(root->right);
    res.pop_back();
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    printAllPaths(root);
    cout<<"All root to leaf Paths:\n";
    for(auto x: ans)
    {
        for(auto y: x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
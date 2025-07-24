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
vector<int> zigzag(Node* root)
{
    vector<int>res;
    deque<Node*> q;
    q.push_back(root);
    bool flag=true;
    while(!q.empty())
    {
        int s=q.size();
        while(s--)
        {
            if(flag)
            {
                Node* k=q.back();
                q.pop_back();
                res.push_back(k->data);
                if(k->right)
                q.push_front(k->right);
                if(k->left)
                q.push_front(k->left);
            }
            else
            {
                Node* k=q.front();
                q.pop_front();
                res.push_back(k->data);
                if(k->left)
                q.push_back(k->left);
                if(k->right)
                q.push_back(k->right);
            }
        }
        flag=!flag;
    }
    return res;
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);
    vector<int>res=zigzag(root);
    cout<<"ZigZag traversal:\t";
    for(auto x: res)
    cout<<x<<" ";
    return 0;
}
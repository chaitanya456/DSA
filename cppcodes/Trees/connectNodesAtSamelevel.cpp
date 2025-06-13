#include<bits/stdc++.h>
using namespace std;
struct tree* ins(int data);
void levelOrder(struct tree* root);
void connectNodesAtSameLevel(struct tree* root);
struct tree
{
    int data;
    struct tree *left,*right,*nextRight;
};
struct tree* ins(int data)
{
    struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->nextRight=NULL;
    return temp;
}
void levelOrder(struct tree* root)
{
    if(!root)
    return;
    queue<struct tree*> q;
    q.push(root);
    cout<<root->data<<"->";
    cout<<"NULL"<<endl;
    while(!q.empty())
    {
        struct tree* k=q.front();
        if(k->nextRight!=NULL)
        cout<<k->nextRight->data<<" ";
        else cout<<"NULL"<<endl;
        if(k->left)
        q.push(k->left);
        if(k->right)
        q.push(k->right);
        q.pop();
    }
}
void connectNodesAtSameLevel(struct tree* root)
{
    if(!root)
    return;
    queue<struct tree*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        struct tree*k=q.front();
        q.pop();
        if(k==q.front())
        break;
        if(k!=NULL)
        {
            // cout<<k->data<<" ";
            if(k->left)
            q.push(k->left);
            if(k->right)
            q.push(k->right);
            k->nextRight=q.front();
        }
        else
        q.push(NULL);
    }
}
int main()
{
    struct tree* root=ins(1);
    root->left=ins(2);
    root->right=ins(3);
    root->left->left=ins(4);
    root->left->right=ins(5);
    root->right->left=ins(6);
    //levelOrder(root);
    connectNodesAtSameLevel(root);
    levelOrder(root);
    return 0;
}
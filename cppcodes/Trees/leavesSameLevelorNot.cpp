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
bool checkLeafAtSameLevel(Node* root, int level, int *leafLevel)
{
    if(!root)
    return 1;
    if(!(root->left) && !(root->right))
    {
        if(*leafLevel==0)
        {
            *leafLevel=level;
            return 1; //only one element is present in the tree.
        }
        return (*leafLevel==level);
    }
    return checkLeafAtSameLevel(root->left,level+1,leafLevel) && checkLeafAtSameLevel(root->right,level+1,leafLevel);
}
bool func(Node* root)
{
   int level=0,leafLevel=0;
   return checkLeafAtSameLevel(root,level,&leafLevel);
}  

int main()
{
    Node* root=new Node(12);
    root->left=new Node(5);
    root->right=new Node(7);
    root->left->left=new Node(3);
    root->right->right=new Node(1);
    if(func(root))
    cout<<"Leaves are at same level!";
    else cout<<"Leaves are not at same level!";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next,*bottom;
    Node(int x)
    {
        data=x;
        next=NULL;
        bottom=NULL;
    }
};
void print(Node *x)
{
    while(x)
    {
        cout<<x->data<<"->";
        x=x->bottom;
    }
}
class comp
{
    public:
    bool operator()(Node*a, Node* b)
    {
        return a->data>b->data;
    }
};
Node* flatten(Node *head)
{
    Node * cur=head,*tail=NULL,*newHead=NULL;
    priority_queue<Node*,vector<Node*>,comp> minHeap;
    while(cur)
    {
        minHeap.push(cur);
        cur=cur->next;
    }
    while(!minHeap.empty())
    {
        Node* node=minHeap.top();
        minHeap.pop();
        if(!newHead)
        {
            newHead=node;
            tail=node;
        }
        else
        {
            tail->bottom=node;
            tail=tail->bottom;
        }
        if(node->bottom)
        {
            minHeap.push(node->bottom);
            node->bottom=NULL;
        }
    }
    return newHead;
}
int main()
{
    Node* head=new Node(5);
    head->bottom=new Node(7);
    head->bottom->bottom=new Node(8);
    head->bottom->bottom->bottom=new Node(30);

    head->next=new Node(10);
    head->next->bottom=new Node(20);

    head->next->next=new Node(19);
    head->next->next->bottom=new Node(22);
    head->next->next->bottom->bottom=new Node(50);

    head->next->next->next=new Node(28);
    head=flatten(head);
    print(head);
    return 0;
}
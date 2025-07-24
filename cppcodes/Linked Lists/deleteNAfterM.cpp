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
void print(Node* x)
{
    while(x)
    {
        cout<<x->data<<"->";
        x=x->next;
    }
}
Node* func(Node * head,int n,int m)
{
    Node * cur=head;
    int i;
    Node* t;
    while(cur)
    {
        for(i=1;cur && i<n;i++)
        cur=cur->next;
        if(!cur)
        return head;
        t=cur->next;
        for(i=1;i<=m && t;i++)
        { 
            Node* k=t;
            t=t->next;
            delete(k);
        }
        cur->next=t;
        cur=t;
    }
    return head;
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
    head->next->next->next->next->next->next->next=new Node(8);
    head->next->next->next->next->next->next->next->next=new Node(9);
    head->next->next->next->next->next->next->next->next->next=new Node(10);
    int n=2,m=2;
    cout<<"Original Linked List:\t";
    print(head);
    head=func(head,n,m);
    cout<<endl<<"After Removing M nodes after skipping N nodes:\t";
    print(head);
    return 0;
}
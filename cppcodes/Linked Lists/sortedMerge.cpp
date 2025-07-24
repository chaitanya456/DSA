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
void print(Node* head)
{
    while(head)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
Node* sortedMerge(Node*a, Node *b)
{
    Node* dummy=new Node(-1);
    Node* cur=dummy;
    while(a && b)
    {
        if(a->data<=b->data)
        {
            cur->next=a;
            a=a->next;
        }
        else
        {
            cur->next=b;
            b=b->next;
        }
        cur=cur->next;
    }
    if(!a)
    cur->next=b;
    if(!b)
    cur->next=a;
    return dummy->next;
}
int main()
{
    Node* head1=new Node(5);
    head1->next=new Node(10);
    head1->next->next=new Node(15);
    head1->next->next->next=new Node(40);
    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);
    // print(head2);
    Node* res=sortedMerge(head1,head2);
    print(res);
    return 0;
}
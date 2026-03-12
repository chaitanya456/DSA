#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        this->data=val;
        this->next=NULL;
    }
};
void print(Node* h)
{
    while(h)
    {
        cout<<h->data<<"->";
        h=h->next;
    }
}
bool isPresent(Node* a, int data)
{
    while(a)
    {
        if(a->data==data)
        return 1;
        a=a->next;
    }
    return 0;
}
Node* intersection(Node* a, Node *b)
{
    Node* dummy=new Node(-1);
    Node* cur=dummy;
    Node* res=a;
    while(b)
    {
        if(isPresent(res,b->data))
        {
            cur->next=new Node(b->data);
            cur=cur->next;
        }
        b=b->next;
    }
    return dummy->next;
}
Node* rotate(Node*a, int k)
{
    int i=1;
    Node* cur1=a;
    for(;i<k && cur1 ;i++)
    cur1=cur1->next;
    Node* cur2=cur1;
    while(cur2->next)
    cur2=cur2->next;
    cur2->next=a;
    a=cur1->next;
    cur1->next=NULL;
    return a;
}
Node* reverseNodes(Node* head, int k)
{
    Node* cur=head;
    Node* prev=NULL;
    while(cur&& k)
    {
        Node* temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
        k--;
    }
    return prev;
}
Node* reverse(Node*head, int k)
{
    if(!head)
    return NULL;
    int i=0;
    Node*res=NULL;
    Node* cur=head;
    while(i<k && cur)
    {
        cur=cur->next;
        i++;
    }
    Node* groupHead=reverseNodes(head,k);
    if(!res)
    res=groupHead;
    head->next=reverse(cur,k);
    return res;
}
int main()
{
    Node *a =new Node(1);
    a->next=new Node(2);
    a->next->next=new Node(3);
    a->next->next->next=new Node(4);
    a->next->next->next->next=new Node(5);
    
   
    int k=3;
    a=reverse(a,k);
    cout<<"After reversing by "<<k<<" nodes:\t";
    print(a);
    
    
    return 0;
}
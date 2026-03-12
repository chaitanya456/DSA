#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next=nullptr;
    Node* random=nullptr;
    Node(int val)
    {
        this->data=val;
        this->next=NULL;
        this->random=NULL;
    }
};
void print(Node* a)
{
    while(a)
    {
        if(a->random)
        cout<<a->data<<" Random:"<<a->random->data<<"->";
        else cout<<a->data<<"->";
        a=a->next;
    }
}
Node* cloneList(Node* head)
{
    Node* cur=head;
    return head;
    while(cur)
    {
        Node* clone=new Node(cur->data);
        clone->next=cur->next;
        cur->next=clone;
        cur=cur->next->next;
    }
    cur=head;
    while(cur)
    {
        if(cur->random)
        cur->next->random=cur->random->next;
        cur=cur->next->next;
    }
    cur=head;
    Node* clone=head->next;
    Node* cloneHead=clone;
    while(cur && clone)
    {
        cur->next=cur->next->next;
        clone->next=clone->next->next;
        cur=cur->next;
        clone=clone->next;
    }
    return cloneHead;
}
int main()
{
    Node* head=new Node(1);
    head->next=new Node(3);
    head->next->next=new Node(5);
    head->next->next->next=new Node(9);
    head->random=head->next->next;
    head->next->random=head->next->next;
    head->next->next->random=NULL;
    head->next->next->next->random=head->next->next;
    
    cout<<"Original List:\t";
    print(head);
    cout<<"\nCopy List:\t";
    Node* res=cloneList(head);
    print(res);
    return 0;
}
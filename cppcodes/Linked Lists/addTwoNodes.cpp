#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*next=nullptr;
    Node(int val)
    {
        this->data=val;
        this->next=nullptr;
    }
};
void print(Node* a)
{
    while(a)
    {
        cout<<a->data<<"->";
        a=a->next;
    }
}
Node* reverse(Node* a)
{
    Node* cur=a,*prev=NULL;
    while(cur)
    {
        Node* temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}
void sum(Node*a, Node* b)
{
    a=reverse(a);
    b=reverse(b);
    Node* dummy=new Node(-1);
    Node* cur=dummy;
    int carry=0;
    while(a || b || carry)
    {
        int x=a?a->data:0;
        int y=b?b->data:0;
        int sum=x+y+carry;
        carry=sum/10;
        cur->next=new Node(sum%10);
        cur=cur->next;
        a=a?a->next:NULL;
        b=b?b->next:NULL;
    }
    Node* ans=reverse(dummy->next);
    cout<<"Sum of above Lists:\t";
    print(ans);
}
int main()
{
    Node* a=new Node(4);
    a->next=new Node(5);
    
    Node* b=new Node(3);
    b->next=new Node(4);
    b->next->next=new Node(5);
    
    cout<<"First List:\t";
    print(a);
    cout<<endl;
    cout<<"Second List:\t";
    print(b);
    cout<<endl;
    sum(a,b);
    
    return 0;
}
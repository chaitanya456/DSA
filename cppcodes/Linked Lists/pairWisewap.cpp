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
void pairWiseSwap(Node* head)
{
    while(head && head->next)
    {
        swap(head->data, head->next->data);
        head=head->next->next;
    }
}
void print(Node *x)
{
    while(x)
    {
        cout<<x->data<<"->";
        x=x->next;
    }
}
int main()
{
    Node * head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=new Node(7);
    pairWiseSwap(head);
    print(head);
    return 0;
}
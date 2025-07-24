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
vector<Node*> alternateMerge(Node* a, Node *b)
{
    Node * cur1=a,*cur2=b;
    while(cur1 && cur2)
    {
        Node* p1=cur1->next;
        Node* p2=cur2->next;
        cur2->next=p1;
        cur1->next=cur2;
        cur1=p1;
        cur2=p2;
    }
    return {a,cur2};
}
int main()
{
    Node* head1=new Node(1);
    head1->next=new Node(2);
    head1->next->next=new Node(3);
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(7);
    head2->next->next->next->next= new Node(8);
    vector<Node*> res=alternateMerge(head1,head2);
    for(int i=0;i<res.size();i++)
    print(res[i]),cout<<endl;
    return 0;
}
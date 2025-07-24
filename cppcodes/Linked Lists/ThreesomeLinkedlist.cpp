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
void func(Node*a, Node*b, Node*c, int s)
{
    while(a)
    {
        while(b && c)
        {
            int nodeSum=a->data+b->data+c->data;
            if(nodeSum==s)
            cout<<"Triplet Found ";
            else if(nodeSum<s)
            b=b->next;
            else c=c->next;
        }
        a=a->next;
    }
    cout<<"No Triplet found";
}
int main()
{
    Node * head1=new Node(10);
    head1->next=new Node(15);
    head1->next->next=new Node(5);
    head1->next->next->next=new Node(20);

    Node * head2=new Node(2);
    head2->next=new Node(4);
    head2->next->next=new Node(9);
    head2->next->next->next=new Node(10);

    Node * head3=new Node(8);
    head3->next=new Node(4);
    head3->next->next=new Node(2);
    head3->next->next->next=new Node(1);
    
    int target=25;
    func(head1,head2,head3,target);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct node *push(int data);
void print(struct node*x);
int getLength(struct node* x);
int getIntersection(struct node *head1,struct node *head2);
struct node *traverse(struct node* x, int k);
struct node
{
    int data;
    struct node *next;
};
struct node *push(int data)
{
    struct node *temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void print(struct node*x)
{
    while(x)
    cout<<x->data<<"->",x=x->next;
}
int getLength(struct node* x)
{
    int c=0;
    while(x)
    {
        x=x->next;
        c++;
    }
    return c;
}
int getIntersection(struct node *head1,struct node *head2)
{
    int n1=getLength(head1);
    int n2=getLength(head2);
    if(n1>n2)
    head1=traverse(head1,n1-n2);
    else head2=traverse(head1,n2-n1);
    while(head1 && head2)
    {
        if(head1==head2)
        break;
        head1=head1->next;
        head2=head2->next;
    }
    return head1->data;
}
struct node *traverse(struct node* x, int k)
{
    int i=0;
    while(x && i<k)
    i++,x=x->next;
    return x;
}
int main()
{
    struct node *head1=push(3);
    head1->next=push(6);
    head1->next->next=push(9);
    head1->next->next->next=push(15);
    head1->next->next->next->next=push(30);
    struct node *head2=push(10);
    head2->next=head1->next->next->next;//introducing intersection point
    cout<<"Linked List1:\t";
    print(head1);
    cout<<"\nLinked List2:\t";
    print(head2);
    cout<<"\nIntersection Point:\t"<<getIntersection(head1,head2);
    return 0;
}
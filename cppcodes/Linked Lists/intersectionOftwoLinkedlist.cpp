#include<bits/stdc++.h>
using namespace std;
void print(struct node*x);
struct node* push(int data);
struct node
{
    int data;
    struct node* next;
};
struct node* push(int data)
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
void getIntersection(struct node*a,struct node *b)
{
    vector<int>res;
    while(a&&b)
    {
        if(a->data==b->data)
        res.push_back(a->data),a=a->next,b=b->next;
        else if(a->data<b->data)
        a=a->next;
        else b=b->next;
    }
    cout<<"\nIntersection of two lists:\t";
    for(auto x:res)
    cout<<x<<"->";
}
int main()
{
    struct node *head1=push(1);
    head1->next=push(2);
    head1->next->next=push(3);
    head1->next->next->next=push(4);
    head1->next->next->next->next=push(6);
    struct node * head2=push(2);
    head2->next=push(4);
    head2->next->next=push(6);
    head2->next->next->next=push(8);
    cout<<"Linked list 1:\t";
    print(head1);
    cout<<"\nLinked list 2:\t";
    print(head2);
    getIntersection(head1,head2);
    return 0;
}
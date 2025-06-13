#include<bits/stdc++.h>
using namespace std;
void print(struct node *head);
struct node* merge(struct node* a, struct node* b);
struct node* ins(int data);
struct node
{
    int data;
    struct node* next;
};
struct node* ins(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void print(struct node *head)
{
    while(head)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
struct node* merge(struct node* a, struct node* b)
{
    struct node* res=NULL;
    if(!a && !b)
    return NULL;
    else if(a && !b)
    return a;
    else if(!a && b)
    return b;
    else
    {
        if(a->data<b->data)
        {
            res=a;
            res->next=merge(a->next, b);
        }
        else
        {
            res=b;
            res->next=merge(a,b->next);
        }    
    }
    return res;
}
int main()
{
    struct node* head1=ins(1);
    head1->next=ins(2);
    head1->next->next=ins(3);
    head1->next->next->next=ins(4);
    struct node* head2=ins(6);
    head2->next=ins(9);
    head2->next->next=ins(12);
    head2->next->next->next=ins(15);
    cout<<"Lists are:\n";
    print(head1);
    cout<<endl;
    print(head2);
    head1=merge(head1,head2);
    cout<<"\nAfter Merging:\t";
    print(head1);
    return 0;
}
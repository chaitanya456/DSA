#include<bits/stdc++.h>
using namespace std;
void print(struct node *x);
struct node * push(int data);
void reverse(struct node * head);
struct node
{
    int data;
    struct node*next;
};
struct node * push(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void print(struct node *x)
{
    while(x)
    {
        cout<<x->data<<"->";
        x=x->next;
    }
}
void  reverse(struct node * head)
{
    if(!head)
    return;
    reverse(head->next);
    cout<<head->data<<"->";
}
int main()
{
    struct node* head=push(1);
    head->next=push(2);
    head->next->next=push(3);
    head->next->next->next=push(4);
    cout<<"Linked List:\t";
    print(head);
    cout<<"\nAfter reversing: Linked list:\t";
    reverse(head);
    return 0;
}
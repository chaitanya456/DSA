#include<bits/stdc++.h>
using namespace std;
struct node * push(int data);
struct node * deleteAlt(struct node* head);
void print(struct node *x);
struct node{
    int data;
    struct node *next;
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
struct node * deleteAlt(struct node* head)
{
    struct node* cur=head;
    while(cur&& cur->next)
    {
        struct node* del=cur->next;
        cur->next=del->next;
        cur=del->next;
        free(del);
    }
    return head;
}
int main()
{
    struct node* head=push(1);
    head->next=push(2);
    head->next->next=push(3);
    head->next->next->next=push(4);
    head->next->next->next->next=push(5);
    head->next->next->next->next->next=push(6);
    cout<<"Linked list:\t";
    print(head);
    head=deleteAlt(head);
    cout<<"\nAfter deleting alternate nodes:\t";
    print(head);
    return 0;
}
//Not completed.
#include<bits/stdc++.h>
using namespace std;
struct node* deleteAlternateNodesOfK(struct node* head,int k);
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
struct node* deleteAlternateNodesOfK(struct node* head,int k)
{
    struct node*
    return NULL;
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
    int k;
    cout<<"\nEnter K value:\t";
    cin>>k;
    head=deleteAlternateNodesOfK(head,k);
    print(head);
    return 0;
}
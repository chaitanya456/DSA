#include<bits/stdc++.h>
using namespace std;
struct node* reverseAltNodesOfGroupK(struct node *head,int k);
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
struct node* reverseAltNodesOfGroupK(struct node *head,int k)
{
    if(!head)
    return NULL;
    int i=0;
    struct node* prev=NULL,*cur=head,*nxt;
    while(cur && i<k)
    {
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;   
        i++;
    }
    if(head)
    head->next=cur;
    i=0;
    while(cur && i<k)
    {
        cur=cur->next;
        i++;
    }
    if(cur)
    cur->next=reverseAltNodesOfGroupK(cur->next,k);
    return prev;
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
    cout<<"\nEnter Value of K:\t";
    int k;
    cin>>k;
    head=reverseAltNodesOfGroupK(head,k);
    cout<<"\nAfter reversing:\t";
    print(head);
    return 0;
}
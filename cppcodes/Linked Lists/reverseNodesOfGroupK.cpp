#include<bits/stdc++.h>
using namespace std;
struct node* reverseGroupK(struct node*head, int k);
struct node*ins(int data);
void print(struct node* head);
struct node* reverseLL(struct node* head,int k);
struct node
{
    int data;
    struct node* next;
};
struct node*ins(int data)
{
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void print(struct node* head)
{
    while(head)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
struct node* reverseLL(struct node* head,int k)
{
    struct node* prev=NULL,*cur=head;
    struct node* temp;
    while(cur&&k)
    {
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
        k--;
    }
    return prev;
}
struct node* reverseGroupK(struct node*head, int k)
{
    if(!head)
    return NULL;
    int i=0;
    struct node* newHead=NULL;
    struct node*cur=head;
    while(cur && i<k)
    {
        cur=cur->next;
        i++;
    }
    struct node* groupHead=reverseLL(head,k);
    if(!newHead)
    newHead=groupHead;
    head->next=reverseGroupK(cur,k);
    return newHead;
}
int main()
{
    struct node*head=ins(1);
    head->next=ins(2);
    head->next->next=ins(3);
    head->next->next->next=ins(4);
    head->next->next->next->next=ins(5);
    head->next->next->next->next->next=ins(6);
    head->next->next->next->next->next->next=ins(7);
    head->next->next->next->next->next->next->next=ins(8);
    int k=2;
    // print(head);
    head=reverseGroupK(head,k);
    print(head);
    return 0;
}
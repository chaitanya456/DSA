//Not correct completely
#include<bits/stdc++.h>
using namespace std;
void print(struct node *x);
struct node * push(int data);
int printNthNode(struct node * head, int x);
int getLength(struct node* x);
void detectLoop(struct node * head);
void removeLoop(struct node*s,struct node *head);
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
int printNthNode(struct node * head, int x)
{
    int n=getLength(head);
    int i=n-x,j=0;
    while(head && j<i)
    head=head->next,j++;
    return head->data;
}
void detectLoop(struct node * head)
{
    struct node *s,*f;
    s=f=head;
    while(s&&f->next&&f)
    {
        s=s->next;
        f=f->next->next;
        if(s==f)
        break;
    }
    
    if(s==head && f==head)
    {
        while(s->next!=f)
        s=s->next;
        s->next=NULL;
        print(head);
        return;
    }
    else
    {
        removeLoop(s,head);
        print(head);
    }
}
void removeLoop(struct node*s,struct node *head)
{
    struct node* k=s,*l=head;
    while(l->next!=k->next)
    l=l->next,k=k->next;
    k->next=NULL;
    return;
}
int main()
{
    struct node* head=push(1);
    head->next=push(2);
    head->next->next=push(3);
    head->next->next->next=push(4);
    head->next->next->next->next=head;//introducing the cycle
    detectLoop(head);
    return 0;
}
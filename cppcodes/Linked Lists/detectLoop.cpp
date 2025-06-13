#include<bits/stdc++.h>
using namespace std;
void print(struct node *x);
struct node * push(int data);
int printNthNode(struct node * head, int x);
int getLength(struct node* x);
bool detectLoop(struct node * head);
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
bool detectLoop(struct node * head)
{
    struct node *s,*f;
    s=f=head;
    while(s&&f->next&&f)
    {
        s=s->next;
        f=f->next->next;
        if(s==f)
        return 1;
    }
    return 0;
}
int main()
{
    struct node* head=push(1);
    head->next=push(2);
    head->next->next=push(3);
    head->next->next->next=push(4);
   head->next->next->next=head->next;//introducing the cycle
   bool b=detectLoop(head);
   if(b)
   cout<<"Cycle exists";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void print(struct node *x);
struct node * push(int data);
int printNthNode(struct node * head, int x);
int getLength(struct node* x);
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
struct node* deleteLL(struct node *head)
{
    struct node *cur=head;
    while(cur)
    {
        struct node* temp=cur;
        cout<<"\ncurrently deleting:\t"<<temp->data<<endl;
        cur=cur->next;
        free(temp);
    }
    return cur;
}
int main()
{
    struct node* head=push(1);
    head->next=push(2);
    head->next->next=push(3);
    head->next->next->next=push(4);
    cout<<"Linked List:\t";
    print(head);
    head=deleteLL(head);
    cout<<"\nAfter Deleting Linked List:\t";
    print(head);
    return 0;
}
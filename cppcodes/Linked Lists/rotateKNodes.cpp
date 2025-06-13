#include<bits/stdc++.h>
using namespace std;
int getLength(struct node *x);
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
int getLength(struct node *x)
{
    int c=0;
    while(x)
    {
        c++;
        x=x->next;
    }
    return c;
}
struct node * rotateKNodes(struct node *head,int k)
{
    int n=getLength(head);
    k=k%n;
    if(k==0)
    return head;
    struct node* cur=head;
    struct node *prev,*kNode;
    int i=0;
    while(cur && i<k)
    {
        prev=cur;
        cur=cur->next;
        i++;
    }
    kNode=cur;
    while(cur->next)
    cur=cur->next;
    cur->next=head;
    head=kNode;
    prev->next=NULL;
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
    int k;
    cout<<"\nEnter K Value:\t";
    cin>>k;
    head=rotateKNodes(head,k);
    cout<<"\nAfter rotating list by K nodes:\t";
    print(head);
    return 0;
}
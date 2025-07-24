#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
struct Node * ins(int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void print(struct Node* x)
{
    while(x)
    {
        cout<<x->data<<"->";
        x=x->next;
    }
}
int getLen(struct Node * x)
{
    int c=0;
    while(x)
    {
        c++;
        x=x->next;
    }
    return c;
}
void printKthNodeFromLast(struct Node* x, int k, int n)
{
    int fromBegin=(n-k);
    int i=1;
    while(x && i<=fromBegin)
    {
        x=x->next;
        i++;
    }
    if(x)
    cout<<k<<" th node from end:\t"<<x->data<<endl;
    else cout<<"Not found";
}
struct Node * reverseLL(struct Node *head)
{
    struct Node*prev=NULL,*temp;
    struct Node* cur=head;
    while(cur)
    {
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}
int main()
{
    struct Node* head=ins(1);
    head->next=ins(2);
    head->next->next=ins(3);
    head->next->next->next=ins(-1);
    head->next->next->next->next=ins(4);
    cout<<"Linked List:\t";
    print(head);
    int len=getLen(head);
    cout<<"\nLength of Linked List:\t"<<len<<endl;
    int k=2;
    printKthNodeFromLast(head,k,len);
    struct Node* reverseHead=reverseLL(head);
    cout<<"LinkedList After reverse:\t";
    print(reverseHead);
    return 0;
}
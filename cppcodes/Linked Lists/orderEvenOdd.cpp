#include<bits/stdc++.h>
using namespace std;
void orderEvenOdd(struct node *head);
struct node
{
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
void orderEvenOdd(struct node *head)
{
    struct node* even=NULL,*odd=NULL;
    struct node*evenEnd=NULL,*oddEnd=NULL;
    struct node* cur=head;
    while(cur)
    {
        if(cur->data%2==0)
        {
            if(!even)
            {
                even=cur;
                evenEnd=even;
            }
            else
            {
                evenEnd->next=cur;
                evenEnd=evenEnd->next;
            }
        }
        else
        {
            if(!odd)
            {
                odd=cur;
                oddEnd=odd;
            }
            else
            {
                oddEnd->next=cur;
                oddEnd=oddEnd->next;
            }
        }
        cur=cur->next;
    }
   if(evenEnd)
   evenEnd->next=odd;
   if(oddEnd)
   oddEnd->next=NULL;
   print(even);
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
    cout<<"\nAfter:\t";
    orderEvenOdd(head);
    return 0;
}
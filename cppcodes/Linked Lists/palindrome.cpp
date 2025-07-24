#include<bits/stdc++.h>
using namespace std;
bool comp(struct node* a, struct node *b);
struct node* ins(int data);
bool isPalindrome(struct node* head);
struct node* reverse(struct node* a);
struct node
{
    int data;
    struct node* next;
};
struct node* ins(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
bool isPalindrome(struct node* head)
{
    struct node* slow=head,*fast=head;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    struct node* sn=slow->next;
    struct node* sh=reverse(sn);
    slow->next=NULL;
    return comp(sh,head);
}
bool comp(struct node* a, struct node *b)
{
    while(a&&b)
    {
        if(a->data!=b->data)
        return 0;
        a=a->next,b=b->next;
    }
    return 1;
}
struct node* reverse(struct node* a)
{
    struct node* cur=a,*prev=NULL;
    while(cur)
    {
        struct node* temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}
int main()
{
    struct node* head=ins(1);
    head->next=ins(2);
    head->next->next=ins(3);
    head->next->next->next=ins(2);
    head->next->next->next=ins(1);
    if(isPalindrome(head))
    cout<<"Palindrome";
    else cout<<"Not Palindrome";
    return 0;
}
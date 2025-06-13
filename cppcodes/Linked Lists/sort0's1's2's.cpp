#include<bits/stdc++.h>
using namespace std;
void print(struct node *head);
struct node* ins(int data);
void sortList(struct node* head);
struct node
{
    int data;
    struct node* next;
};
struct node* ins(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void print(struct node *head)
{
    while(head)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
void sortList(struct node* head)
{
    vector<int>c(3,0);
    int i=0;
    struct node *cur=head;
    while(cur)
    {
        c[cur->data]++;
        cur=cur->next;
    }
    cur=head;
    int index=0;
    while(cur)
    {
        if(c[i]==0)
        {
            index++;
            i++;
        }
        else
        {
            cur->data=index;
            c[i]--;
            cur=cur->next;
        }     
    }
    cout<<"\nAfter:\t";
    print(head);
}
int main()
{
    struct node *head=ins(0);
    head->next=ins(1);
    head->next->next=ins(0);
    head->next->next->next=ins(2);
    head->next->next->next->next=ins(1);
    head->next->next->next->next->next=ins(2);
    head->next->next->next->next->next->next=ins(0);
    head->next->next->next->next->next->next->next=ins(0);
    cout<<"Linked List:\t";
    print(head);
    cout<<endl;
    sortList(head);
    return 0;
}
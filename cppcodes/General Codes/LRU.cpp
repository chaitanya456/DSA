#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int key,value;
    Node* prev,*next;
    Node(int k, int v)
    {
        this->key=k;
        this->value=v;
        prev=next=nullptr;
    }
};
class LRU
{
    public:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int capacity;
    unordered_map<int, Node*>m;
    LRU(int c)
    {
        this->capacity=c;
        head->next=tail;
        tail->prev=head;
    }
    void remove(Node* node)
    {
        Node* prevNode=node->prev;
        Node* nxtNode=node->next;
        prevNode->next=nxtNode;
        nxtNode->prev=prevNode;
    }
    void add(Node* node)
    {
        Node* nxtNode=head->next;
        head->next=node;
        node->prev=head;
        node->next=nxtNode;
        nxtNode->prev=node;
    }
    int get(int key)
    {
        if(m.contains(key))
        {
            Node* node=m[key];
            remove(node);
            add(node);
            return node->value;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if(m.contains(key))
        {
            Node* node=m[key];
            m.erase(key);
            remove(node);
            delete node;//avoid memory leak
        }
        Node* newNode=new Node(key,value);
        add(newNode);
        m[key]=newNode;
        if(m.size()>capacity)
        {
            Node* rmvNode=tail->prev;
            remove(rmvNode);
            m.erase(rmvNode->key);
            delete rmvNode; //avoid memory leak
        }
    }
    
};
int main()
{
    LRU lru(3);
    lru.put(1,101);
    lru.put(2,102);
    lru.put(3,103);
    cout<<lru.get(1)<<endl;
    lru.put(4,104);
    cout<<lru.get(2)<<endl;
    cout<<lru.get(4)<<endl;
    return 0;
}
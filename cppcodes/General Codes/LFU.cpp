#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key, value, freq;
    Node* prev, *next;
    Node(int k, int v)
    {
        this->key = k;
        this->value = v;
        this->freq = 1;  // Start with frequency 1
        prev = next = nullptr;
    }
};

class DoublyLinkedList
{
    public:
    Node* head;
    Node* tail;
    int size;
    
    DoublyLinkedList()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void add(Node* node)
    {
        Node* nxtNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nxtNode;
        nxtNode->prev = node;
        size++;
    }
    
    void remove(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nxtNode = node->next;
        prevNode->next = nxtNode;
        nxtNode->prev = prevNode;
        size--;
    }
    
    Node* removeLast()
    {
        if(size > 0)
        {
            Node* lastNode = tail->prev;
            remove(lastNode);
            return lastNode;
        }
        return nullptr;
    }
};

class LFU
{
    public:
    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyNodeMap;
    unordered_map<int, DoublyLinkedList*> freqListMap;
    
    LFU(int c)
    {
        this->capacity = c;
        this->minFreq = 0;
    }
    
    void updateNode(Node* node)
    {
        // Remove from current frequency list
        int oldFreq = node->freq;
        freqListMap[oldFreq]->remove(node);
        
        if(oldFreq == minFreq && freqListMap[oldFreq]->size == 0)
        minFreq++;

        // Increase frequency
        node->freq++;
        
        // Add to new frequency list
        if(!freqListMap.count(node->freq))
        freqListMap[node->freq] = new DoublyLinkedList();
        freqListMap[node->freq]->add(node);
    }
    
    int get(int key)
    {
        if(keyNodeMap.contains(key))
        {
            Node* node = keyNodeMap[key];
            updateNode(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        if(capacity == 0) return;
        
        if(keyNodeMap.contains(key))
        {
            Node* node = keyNodeMap[key];
            node->value = value;
            updateNode(node);
        }
        else
        {
            // If at capacity, remove LFU item
            if(keyNodeMap.size() >= capacity)
            {
                DoublyLinkedList* minFreqList = freqListMap[minFreq];
                Node* nodeToRemove = minFreqList->removeLast();
                keyNodeMap.erase(nodeToRemove->key);
                delete nodeToRemove;  // Avoid memory leak
            }
            
            // Add new node
            Node* newNode = new Node(key, value);
            keyNodeMap[key] = newNode;
            
            // Add to frequency 1 list
            if(!freqListMap.count(1))
            freqListMap[1] = new DoublyLinkedList();
            freqListMap[1]->add(newNode);
            
            minFreq = 1;
        }
    }
};

int main()
{
    LFU lfu(3);
    lfu.put(1, 101);
    lfu.put(2, 102);
    lfu.put(3, 103);
    cout << lfu.get(1) << endl;  // Returns 101
    lfu.put(4, 104);              // Evicts LFU item (key 2 or 3)
    cout << lfu.get(2) << endl;  // Returns -1 if evicted
    cout << lfu.get(4) << endl;  // Returns 104
    cout << lfu.get(1) << endl;  // Returns 101
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a={5,3,4,1,2};
    priority_queue<int> q(a.begin(),a.end());
    cout<<"Max Heap:\t";
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    priority_queue<int,vector<int> ,greater<int> > minHeap(a.begin(),a.end());
    cout<<"Min Heap:\t";
    while(!minHeap.empty())
    {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    return 0;
}
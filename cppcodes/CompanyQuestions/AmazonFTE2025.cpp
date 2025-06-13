#include<bits/stdc++.h>
using namespace std;
int func(int n, vector<int>&a, vector<int>&stype, int m);
int main()
{
    int n=4;
    vector<int> health={4,5,5,6};
    vector<int> serverType={1,2,1,2};
    int m=1;
    cout<<"Servers:\t"<<func(n,health,serverType,m);
    return 0;
}
int func(int n, vector<int>&a, vector<int>&stype, int m)
{
    unordered_map<int,priority_queue<int> > ma;
    int i;
    for(i=0;i<n;i++)
    ma[stype[i]].push(a[i]);
    priority_queue<long> mHeap;
    for(auto x: ma)
    {
        int sum=0;
        priority_queue<int> temp=x.second;
        while(!temp.empty())
        {
            sum+=temp.top();
            temp.pop();
        }
        mHeap.push(sum);
    }
    int res=0;
    for(i=0;i<m && !mHeap.empty();i++)
    {
        res+=mHeap.top();
        mHeap.pop();
    }
    return res; 
}
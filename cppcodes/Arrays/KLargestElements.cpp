//Time Complexity: T(n)= O(k+(n-k)logk)
#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n,int k);
int main()
{
    vector<int>a={1, 23, 12, 9, 30, 2, 50};
    int n=a.size();
    int k=3;
    func(a,n,k);
    return 0;
}
void func(vector<int>&a, int n,int k)
{
    priority_queue<int,vector<int>, greater<int>> h;
    int i;
    for(i=0;i<k;i++)
    h.push(a[i]);
    while(!h.empty() && i<n)
    {
        int t=h.top();
        if(t<a[i])
        {
            h.push(a[i]);
            h.pop();
        }
        i++;
    }
    cout<<"K Largest Elements are:\t";
    while(!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }
}
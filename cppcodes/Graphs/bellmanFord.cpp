#include<bits/stdc++.h>
using namespace std;
vector<int>bellmanFord(int n,vector<vector<int>>&edges, int src);
int main()
{
    int n=5;
    vector<vector<int>>edges={
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };
    int src=0;
    vector<int> ans=bellmanFord(n,edges,src);
    cout<<"After updating shortest path from "<<src<<":\t";
    for(auto x: ans)
    cout<<x<<" ";
    return 0;
}
vector<int>bellmanFord(int n,vector<vector<int>>&edges, int src)
{
    vector<int> a(n,INT_MAX);
    a[src]=0;
    int i;
    for(i=0;i<n;i++)
    {
        bool updated=0;
        for(auto x: edges)
        {
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            if(a[u]!=INT_MAX && a[u]+wt<a[v])
            {
                if(i==n-1)
                return {-1};
                a[v]=a[u]+wt;
                updated=1;
            }
        }
        if(!updated) break;//No change in iterations.
    }
    return a;
}
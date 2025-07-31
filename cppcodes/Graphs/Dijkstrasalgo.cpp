#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> constructAdjacency(vector<vector<int>>& edges,int n)
{
    vector<vector<vector<int>>> adj(n);
    for(auto x: edges)
    {
        int u=x[0];
        int v=x[1];
        int wt=x[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    return adj;
}
vector<int> dijkstras(vector<vector<int>>& edges, int n, int src)
{
    vector<vector<vector<int>>> adj=constructAdjacency(edges,n);
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>pq;
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int u=pq.top()[1];
        int current_wt=pq.top()[0];
        pq.pop();
        for(auto x: adj[u])
        {
            int v=x[0];
            int wt=x[1];
            if(dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>> edges=
    {{0, 1, 4},
    {0, 2, 8},
    {1, 4, 6}, 
    {2, 3, 2},
    {3, 4, 10}};
    vector<int> res=dijkstras(edges,5,0);
    cout<<"After applying Dijkstras algo:\t";
    for(auto x: res)
    cout<<x<<" ";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int n;
    vector<bool> vis;
    vector<vector<int>>adj;
    Graph(int n)
    {
        this->n=n;
        adj.resize(n);
        vis.resize(n,false);
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);//For undirected Graph
    }
    void print()
    {
        int i,j;
        for(i=0;i<adj.size();i++)
        {
            cout<<i<<":==>";
            for(j=0;j<adj[i].size();j++)
            cout<<adj[i][j]<<"->";
            cout<<endl;
        }
    }
    void dfs(int src)
    {
        vis[src]=1;
        cout<<src<<" ";
        for(auto x: adj[src])
        if(!vis[x])
        dfs(x);
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(4,1);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    cout<<"Adjacency Matrix:\n";
    g.print();
    int start=0;
    cout<<"DFS from "<<start<<" is:\t";
    g.dfs(start);
    return 0;
}
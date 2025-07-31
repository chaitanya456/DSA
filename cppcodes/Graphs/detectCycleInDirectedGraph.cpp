#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int n;
    vector<vector<int>>adj;
    vector<bool>vis,rec;
    Graph(int n)
    {
        this->n=n;
        adj.resize(n);
        vis.resize(n,false);
        rec.resize(n,false);
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    bool dfs(int start)
    {
        if(rec[start])
        return true;
        if(vis[start])
        return false;
        vis[start]=true;
        rec[start]=true;
        for(auto x: adj[start])
        if(dfs(x))
        return true;
        rec[start]=false;
        return false;
    }
    bool detectCycle()
    {
        int i;
        for(i=0;i<adj.size();i++)
        return dfs(i) && !vis[i];
        return 0;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    if(g.detectCycle())
    cout<<"Cycle Exists";
    else cout<<"Cycle Doesn't Exists";
    return 0;
}
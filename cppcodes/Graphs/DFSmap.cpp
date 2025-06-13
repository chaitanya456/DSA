#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    unordered_map<int,list<int> >graph;
    void addEdge(int u,int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    void print()
    {
        for(auto x: graph)
        {
            cout<<x.first<<"->";
            for(auto y:x.second)
            cout<<y<<"->";
            cout<<endl;
        }
    }
};
void DFS(Graph g, vector<bool> vis,int s)
{
    if(!vis[s])
    {
        cout<<s<<" ";
        vis[s]=true;
    }
    for(auto x:g.graph[s])
    {
        if(!vis[x])
        DFS(g,vis,x);
    }
}
int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,2);
    cout<<"Adjacency List of the graph:\n";
    g.print();
    cout<<endl;
    vector<bool> visited;
    int i;
    for(i=0;i<5;i++)
    visited[i]=false;
    // cout<<"DFS:\t";
    // DFS(g,visited,0);
    return 0;
}
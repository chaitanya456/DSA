#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int n;
    vector<vector<int>>adj;
    vector<bool>vis;
    Graph(int n)
    {
        this->n=n;
        adj.resize(n);
        vis.resize(n,false);
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
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
    void bfs(int src)
    {
        queue<int>q;
        vis[src]=true;
        q.push(src);
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            cout<<k<<" ";
            for(auto x: adj[k])
            {
                if(!vis[x])
                {
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(4,1);
    g.addEdge(3,4);
    g.addEdge(0,2);
    cout<<"Adjacency List:\n";
    g.print();
    int start=0;
    cout<<"BFS from "<<start<<":\t";
    g.bfs(start);
    return 0;
}
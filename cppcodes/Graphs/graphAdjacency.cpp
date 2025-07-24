#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int n;
    vector<vector<int>>adj;
    Graph(int nodes)
    {   
        this->n=nodes;
        adj.resize(n);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print()
    {
      int i,j;
      for(i=0;i<adj.size();i++)
      {
        cout<<i<<"<-->";
        for(j=0;j<adj[i].size();j++)
        cout<<adj[i][j]<<"-->";
        cout<<endl;
      }
    }
};
int main()
{
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.print();
    return 0;
}
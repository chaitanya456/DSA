#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
class Graph
{
    public:
    int n;
    Graph(int n)
    {
        this->n=n;
        adj.resize(n);//Works for only vector of vectors. 
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void printAdjacencyList()
    {
        int i,j;
        for(i=0;i<adj.size();i++)
        {
            cout<<"Node "<<i<<":=>";
            for(j=0;j<adj[i].size();j++)
            cout<<adj[i][j]<<"-->";
            cout<<endl;
        }
    }
};

class DisjointSet
{
    public:
    int n;
    vector<int>parent,rank;
    DisjointSet(int n)
    {
        this->n=n;
        parent.resize(n);
        rank.resize(n);
        
        //This is Make Set functionality
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    int find(int x)
    {
        if(parent[x]!=x)
        parent[x]=find(parent[x]);
        return parent[x];
    }
    void union_set(int a, int b)
    {
        int rootA=find(a);
        int rootB=find(b);
        if(rootA!=rootB)
        {
            if(rank[rootA]<rank[rootB])
            parent[rootA]=rootB;
            else if(rank[rootB]<rank[rootA])
            parent[rootB]=rootA;
            else 
            parent[rootB]=rootA, rank[rootA]++;
        }
    }
    bool isConnected(int a, int b)
    {
        return (find(a)==find(b));
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    // g.addEdge(3,4); Connected
    g.addEdge(4,5);//Disconnected
    g.printAdjacencyList();
    DisjointSet ds(adj.size());
    int i;
    for(i=0;i<adj.size();i++)
    {
        for(auto x: adj[i])
        ds.union_set(i,x);
    }
    cout<<"Is 0-1 Connected:\t";
    cout<<ds.isConnected(0,1); //return true 
    cout<<endl;
     cout<<"Is 0-4 Connected:\t";
    cout<<ds.isConnected(0,4); //return false if we comment connected else returns true
    cout<<endl;
    return 0;
}
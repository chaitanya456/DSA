#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int n;
    vector<vector<int>>adj;
    vector<bool>vis;
    stack<int>st;
    Graph(int n)
    {
        this->n=n;
        adj.resize(n);
        vis.resize(n,false);
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
    }
    void print()
    {
        int i,j;
        for(i=0;i<adj.size();i++)
        {
            cout<<i<<":=>";
            for(j=0;j<adj[i].size();j++)
            cout<<adj[i][j]<<"->";
            cout<<endl;
        }
    }
    void topologicalSort()
    {
        int i;
        for(i=0;i<n;i++)
        if(!vis[i])
        dfs(i,st);
        cout<<"Topological Order:\t";
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
    void dfs(int start,stack<int>&st)
    {
        vis[start]=true;
        for(auto x: adj[start])
        {
            if(!vis[x])
            dfs(x,st);
        }
        st.push(start);
    }
};
int main()
{
    Graph g(6);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge( 5, 0);
    g.addEdge(5, 2);
    cout<<"Adjacency List:\n";
    g.print();
    g.topologicalSort();
    return 0;
}
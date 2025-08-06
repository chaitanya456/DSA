#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int n;
    vector<vector<int>> adj;
    Graph(int n)
    {
        this->n=n;
        adj.resize(n);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isBipartite()
    {
        vector<int> color(n,-1);
        int i;
        for(i=0;i<n;i++)
        {
            queue<int> q;
            if(color[i]==-1)
            q.push(i);
            while(!q.empty())
            {
                int k=q.front();
                q.pop();
                for(auto x: adj[k])
                {
                    if(color[x]==-1)
                    {
                        color[x]=1-color[k];
                        q.push(x);
                    }
                    else if(color[x]==color[k])
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    int n=4;
    Graph g(n);
    g.addEdge(0,1);
    // g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(2,3);
    if(g.isBipartite())
    cout<<"Yes, it is a Bipartite graph!";
    else cout<<"No, it is not a Bipartite graph!";
    return 0;
}
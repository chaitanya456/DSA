#include<bits/stdc++.h>
using namespace std;
class Graph
{   
    public:
    int n;
    vector<vector<int>>adj;
    vector<int>indegree;
    queue<int>q;
    Graph(int n)
    {
        this->n=n;
        adj.resize(n);
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
    }
    void kahns()
    {
        int i;
        for(i=0;i<n;i++)
        for(auto x: adj[i])
        indegree[x]++;
        for(i=0;i<n;i++)
        if(indegree[i]==0)
        q.push(i);
        while(!q.empty())
        {
            int k=q.front();
            cout<<k<<" ";
            q.pop();
            for(auto x:adj[k])
            {
                indegree[x]--;
                if(indegree[x]==0)
                q.push(x);
            }
        }
    }
    void print()
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            cout<<i<<":==>";
            for(j=0;j<adj[i].size();j++)
            cout<<adj[i][j]<<"->";
            cout<<endl;
        }
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(5,1);
    g.addEdge(5,2); 
    cout<<"Topological Sorted Order:\t";
    g.kahns();
    return 0;
}
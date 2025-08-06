#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int n;
    vector<vector<int>>adj;
    vector<vector<int>>reverseAdj;
    vector<bool> vis;
    vector<int>res;
    stack<int>st;
    Graph(int n)
    {
        this->n=n;
        adj.resize(n);
        vis.resize(n,0);
        res.resize(n);
        reverseAdj.resize(n);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void dfs(int start)
    {
        vis[start]=true;
        // cout<<start<<" ";
        res.push_back(start);
        for(auto x: adj[start])
        {
            if(!vis[x])
            dfs(x);
        }
        st.push(start);
    }
    void dfsSecondPass(int start,vector<int>& temp)
    {
        vis[start]=true;
        temp.push_back(start);
        for(auto x: reverseAdj[start])
        if(!vis[x])
        dfsSecondPass(x,temp);
    }
    void reverse()
    {
        
        int i=0;
        for(i=0;i<n;i++)
        {
            for(auto x: adj[i])
            reverseAdj[x].push_back(i);
        }
    }
    void kosaraju()
    {
        int i=0,j;
        vector<int> temp;
        vector<vector<int>>sccs;
        //First DFS Pass
        for(;i<n;i++)
        if(!vis[i])
        dfs(i);

        //reset
        for(i=0;i<n;i++)
        vis[i]=false;
        
        //reverse
        reverse();
        //Pop each element from stack
       while(!st.empty())
       {
            int k=st.top();
            st.pop();
            if(!vis[k])
            dfsSecondPass(k,temp);
            sccs.push_back(temp);
            temp.clear();
       }
       cout<<"SCCS:\t";
       for(i=0;i<sccs.size();i++)
       {
            for(j=0;j<sccs[i].size();j++)
            cout<<sccs[i][j]<<" ";
            cout<<endl;
       }
    //    makeMetaGraph(adj);
    }
};
int main()
{
    Graph g(5);
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);
    // cout<<"DFS:\t";
    // g.dfs(0);
    g.kosaraju();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    map<int,list<int>> m;
    stack<int>st;
    void addEdge(int u, int v)
    {   
        m[u].push_back(v);
        m[v].push_back(u);
    }
    void printGraph()
    {
        for(auto x: m)
        {
            cout<<x.first<<":=>";
            for(auto y:x.second)
            cout<<y<<"-->";
            cout<<endl;
        }
    }
    void DFS(int x, vector<bool>&vis)
    {
        vis[x]=1;
        cout<<x<<" ";
        for(auto y: m[x])
        {
            if(!vis[y])
            DFS(y,vis);
        }
        st.push(x);
    }
    void topoSort(int s)
    {
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
    g.printGraph();
    vector<bool>vis(5,0);
    cout<<"DFS:\t";
    g.DFS(0,vis);
    cout<<"\nTopological Sort:\t";
    g.topoSort(0);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    map<int,list<int>>m;
    int n;
    Graph(int n)
    {
        this->n=n;
    }
    void printAdjacencyList()
    {
        for(auto x: m)
        {
            cout<<x.first<<":=>";
            x.second.sort();
            for(auto y:x.second)
            {
                cout<<y<<"->";
            }
            cout<<endl;
        }
    }
    void add(int u, int v)
    {
        m[u].push_back(v);
        m[v].push_back(u);
    }
    void DFS(int x)
    {
        vector<bool> vis(n,0);
        DFSUtil(x,vis);
    }
    void DFSUtil(int start, vector<bool>&vis)
    {
        vis[start]=1;
        cout<<start<<" ";
        for(auto x: m[start])
        {
            if(!vis[x])
            DFSUtil(x,vis);
        }
    }
};
int main()
{
    Graph g(5);
    g.add(0,1);
    g.add(2,1);
    g.add(3,1);
    g.add(4,3);
    g.add(2,3);
    cout<<"Adjacency List:\n";
    g.printAdjacencyList();
    cout<<"DFS Starting from 3:\t";
    g.DFS(3);
    return 0;
}
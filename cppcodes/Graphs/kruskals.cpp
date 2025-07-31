#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    public:
    vector<int>parent;
    int n;
    DisjointSet(int n)
    {
        this->n=n;
        parent.resize(n,-1);
    }
    int find(int x)
    {
        if(parent[x]<0)
        return x;
        else return parent[x]=find(parent[x]);
    }
    void setUnion(int x, int y)
    {
        int xRoot=find(x);
        int yRoot=find(y);
        if(xRoot==yRoot)
        return;
        if(parent[xRoot]<parent[yRoot])
        {
            parent[xRoot]+=parent[yRoot];
            parent[yRoot]=xRoot;
        }
        else
        {
            parent[yRoot]+=parent[xRoot];
            parent[xRoot]=yRoot;
        }
    }
    static bool comp(vector<int>&a , vector<int>&b)
    {
        return a[2]<=b[2];
    }
    int kruskals(vector<vector<int>> &edges)
    {
        sort(edges.begin(),edges.end(),comp);
        int totalcost=0,c=0;
        for(auto x: edges)
        {
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            if(find(u)!=find(v))
            {
                setUnion(u,v);
                totalcost+=wt;
                if(++c==n-1)
                break;
            }
        }
        return totalcost;
    }
};
int main()
{
    vector<vector<int>> edges = 
    {
        {0, 1, 10}, {1, 3, 15}, {2, 3, 4}, {2, 0, 6}, {0, 3, 5}
    };
    DisjointSet ds(4);
    cout<<"MST COST:\t"<<ds.kruskals(edges);
    return 0;
}
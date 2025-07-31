#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    public:
    int n;
    vector<int>parent;
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
    void unions(int x, int y)
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
};
int main()
{
    DisjointSet ds(3);
    ds.unions(0,1);
    ds.unions(0,2);
    if(ds.find(1)==ds.find(2))
    cout<<"Path found";
    else cout<<"Path not found";
    return 0;
}
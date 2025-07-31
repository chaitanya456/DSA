#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    public:
    int n;
    vector<int>parent,rank;
    DisjointSet(int n)
    {
        this->n=n;
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    int find(int i)
    {
        int root=parent[i];
        if(parent[root]!=root)
        return parent[i]=find(root);
        return root;
    }
    void unions(int x, int y)
    {
        int xRoot=find(x);
        int yRoot=find(y);
        if(xRoot==yRoot)
        return;
        if(rank[xRoot]<rank[yRoot])
        parent[xRoot]=yRoot;
        else if(rank[yRoot]<rank[xRoot])
        parent[yRoot]=xRoot;
        else
        parent[yRoot]=xRoot, rank[xRoot]++;
    }
};
int main()
{
    DisjointSet ds(5);
    ds.unions(0, 2);
    ds.unions(4, 2);
    ds.unions(3, 1);
    if(ds.find(0)==ds.find(3))
    cout<<"Cycle Found";
    else cout<<"Cycle Not found";
    return 0;
}
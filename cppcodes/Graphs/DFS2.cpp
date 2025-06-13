#include<bits/stdc++.h>
using namespace std;
void printDFS(int start, map<int, list<int>> m, vector<bool> &vis);
int main()
{
    map<int, list<int>> m;
    list<int> * adj=new list<int>[3];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    int i;
    for(i=0;i<3;i++)
    {
        m[i]=adj[i];
    }
    for(auto x: m)
    {
        cout<<x.first<<"---";
        for(auto z: m[x.first])
        cout<<z<<"->";
        cout<<endl;
    }
    vector<bool>vis(3,0);
    cout<<"\nDFS:\t";
    printDFS(0,m,vis);
    return 0;
}
void printDFS(int start, map<int, list<int>> m,vector<bool> &vis)
{
    vis[start]=1;
    cout<<start<<" ";
    for(auto x: m[start])
    {
        if(!vis[x])
        printDFS(x,m,vis);
    }
}
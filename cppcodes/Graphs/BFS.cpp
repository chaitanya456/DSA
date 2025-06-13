#include<bits/stdc++.h>
using namespace std;
void printBFS(int start, map<int, list<int>> m, vector<bool> &vis);
int main()
{
    map<int, list<int>> m;
    list<int> * adj=new list<int>[4];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(2);
    int i;
    for(i=0;i<4;i++)
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
    vector<bool>vis(4,0);
    cout<<"\nBFS:\t";
    printBFS(0,m,vis);
    return 0;
}
void printBFS(int start, map<int, list<int>> m,vector<bool> &vis)
{
    queue<int> q;
    q.push(start);
    cout<<start<<" ";
    vis[start]=1;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(auto x: m[k])
        if(!vis[x])
        {
            cout<<x<<" ";
            q.push(x);
            vis[x]=1;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
void func(string s, int n);
int main()
{
    string x="chandu";
    func(x,x.length());
    return 0;
}
void func(string s, int n)
{
    vector<int> vis(26,-1);
    int i;
    for(i=0;i<n;i++)
    {
        int x=s[i]-'a';
        if(vis[x]==-1)
        vis[x]=i;
        else
        vis[x]=-2;
    }
    cout<<"First Non Repeating Character is:\t";
    int index=-1;
    for(i=0;i<26;i++)
    {
        if(vis[i]>=0 && (vis[i]==-1 || vis[i]<vis[index]))
        index=i;
    }
    if(index==-1)
    cout<<"No Element found:\t";
    else cout<<s[vis[index]]<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int func(vector<int>&a, int n);
int main()
{
    vector<int>a={10,19,6,3,5};
    int n=a.size();
    cout<<"Minimum No. Of Swaps Required:\t"<<func(a,n);
    return 0;
}
int func(vector<int>&a, int n)
{
    unordered_map<int,int> m;
    int i;
    int swaps=0;
    vector<bool> vis(n,0);
    for(i=0;i<n;i++)
    m[a[i]]=i;
    sort(a.begin(),a.end());
    for(i=0;i<n;i++)
    {
        if(vis[i] && m[a[i]]==i)
        continue;
        int j=i, c=0;
        while(!vis[j])
        {
            vis[j]=1;
            j=m[a[i]];
            c++;
        }
        if(c)
        swaps+=c-1;
    }
    return swaps;
}
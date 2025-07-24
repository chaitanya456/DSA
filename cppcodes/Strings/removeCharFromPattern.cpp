#include<bits/stdc++.h>
using namespace std;
void func(string a, int n1, string b, int n2);
int main()
{
    string a="geeksforgeeks";
    string b="mask";
    func(a,a.length(),b,b.length());
    return 0;
}
void func(string a, int n1, string b, int n2)
{
    vector<bool>vis(26,0);
    for(int i=0;i<n2;i++)
    vis[b[i]-'a']=1;
    string res="";
    for(int x=0;x<n1;x++)
    {
        if(!vis[a[x]-'a'])
        res+=a[x];
    }
    cout<<"After removing all chars from one string to other:\t";
    cout<<res<<endl;
}
#include<bits/stdc++.h>
using namespace std;
void func(string &s, int n);
int main()
{
    string s="agbdba";
    int n=s.length();
    func(s,n);
    return 0;
}
void func(string &s, int n)
{
    int len,i,j;
    vector<vector<int>>T(n,vector<int>(n,0));
    for(i=0;i<n;i++)
    T[i][i]=1;
    for(len=2;len<=n;len++)
    {
        for(i=0;i<=n-len;i++)
        {
            j=i+len-1;
            if(s[i]==s[j])
            T[i][j]=2+T[i+1][j-1];
            else T[i][j]=max(T[i+1][j],T[i][j-1]);
        }
    }
    for(auto x: T)
    {
        for(auto y:x)
        cout<<y<<" ";
        cout<<endl;
    }
    cout<<"Longest Palindromic subsequence:\t"<<T[0][n-1]<<endl;
}
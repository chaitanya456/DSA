#include<bits/stdc++.h>
using namespace std;
bool func(string &s1, string &s2, string &s3, int m, int n);
int main()
{
    string s1="aab",s2="axy",s3="aaxaby";
    int m=s1.size(),n=s2.size();
    if(func(s1,s2,s3,m,n))
    cout<<"Yes, Interleaving";
    else cout<<"No";
    return 0;
}
bool func(string &s1, string &s2, string &s3, int m, int n)
{
    vector<vector<bool>>T(m+1, vector<bool>(n+1,false));
    int i,j;
    T[0][0]=1;
    for(i=1;i<=m;i++)
    T[0][i]=T[0][i-1] && s1[i-1]==s3[i-1];
    for(i=1;i<=n;i++)
    T[i][0]=T[i-1][0] && s2[i-1]==s3[i-1];
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            int k=i+j;
            T[i][j]=((s3[k-1]==s1[i-1] && T[i-1][j]) || (s3[k-1]==s2[j-1] && T[i][j-1]));
        }
    }
    return T[m][n];
}
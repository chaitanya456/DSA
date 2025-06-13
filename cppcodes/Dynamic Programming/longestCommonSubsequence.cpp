#include<bits/stdc++.h>
using namespace std;
int lcsDP(string a,string b,int x,int y);
int main()
{
    string b="abcdaf";
    string a="acbcf";
    int x=a.length(),y=b.length();
    cout<<"Longest Common Subsequence:\t"<<lcsDP(a,b,x,y);
    return 0;
}
int lcsDP(string a,string b,int x,int y)
{
    int T[x+1][y+1];
    memset(T,0,sizeof(T));
    int i,j;
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++)
        {
            if(a[i]==b[j])
            T[i][j]=T[i-1][j-1]+1;
            else 
            T[i][j]=max(T[i-1][j],T[i][j-1]);
        }
    }
    // for(i=0;i<=x;i++)
    // {
    //     cout<<endl;
    //     for(j=0;j<=y;j++)
    //     cout<<T[i][j]<<" ";
    // }
    return T[x][y];
}
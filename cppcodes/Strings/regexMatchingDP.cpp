#include<bits/stdc++.h>
using namespace std;
void func(string pattern, string s, int n1, int n2);
int main()
{
    string pattern="x?y*z";
    int plen=pattern.length();
    string s="xaylmz";
    int slen=s.length();
    func(pattern,s,plen,slen);
    return 0;
}
void func(string pattern, string s, int n1, int n2)
{
    vector<vector<int>>T(n2+1,vector<int>(n1+1,false));
    T[0][0]=true;
    int i,j;
    for(i=1;i<=n2;i++)
    {
        for(j=1;j<=n1;j++)
        {
            if(s[i-1]==pattern[j-1] || pattern[j-1]=='?')
            T[i][j]=T[i-1][j-1];
            else if(pattern[j-1]=='*')
            T[i][j]=T[i-1][j] || T[i][j-1];
        }
    }
    // for(auto x: T)
    // {
    //     for(auto y:x)
    //     cout<<y<<" ";
    //     cout<<endl;
    // }
    if(T[n2][n1])
    cout<<"Matching:Yes"<<endl;
    else cout<<"Matching:No"<<endl;
}
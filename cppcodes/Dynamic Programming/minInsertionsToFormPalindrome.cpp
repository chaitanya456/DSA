#include<bits/stdc++.h>
using namespace std;
void func(string &s, int n);
int main()
{
    string a="geeks";
    int n=a.size();
    func(a,n);
    return 0;
}
void func(string &s, int n)
{
    vector<vector<int>>T(n,vector<int>(n,0));
    int len,i,j;
    for(len=2;len<=n;len++)
    {
        for(i=0;i<=n-len;i++)
        {
            j=i+len-1;
            if(s[i]==s[j])
            T[i][j]=T[i+1][j-1];
            else T[i][j]=min(T[i+1][j], T[i][j-1])+1;
        }
    }
    // for(auto x: T)
    // {
    //     for(auto y: x)
    //     cout<<y<<" ";
    //     cout<<endl;
    // }
    cout<<"Minimum Insertions to make this string palindrome:\t"<<T[0][n-1]<<endl;
}
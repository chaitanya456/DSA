#include<bits/stdc++.h>
using namespace std;
void func(vector<vector<int> >&a, int m,int n);
int main()
{
    vector<vector<int> > a=
                        {{0,1,1,0,1},
                        {1,1,0,1,0},
                        {0,1,1,1,0},
                        {1,1,1,1,0},
                        {1,1,1,1,1},
                        {0,0,0,0,0}};
    int m=a.size();
    int n=a[0].size();
    func(a,m,n);
}
void func(vector<vector<int> >&a, int m,int n)
{
    int i,j;
    int T[m+1][n+1];
    for(i=0;i<=m;i++)
    T[i][0]=0;
    for(i=0;i<=n;i++)
    T[0][i]=0;
    int ans=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i-1][j-1]!=0)
            T[i][j]=1+min(T[i-1][j-1], min(T[i-1][j], T[i][j-1]));
            else T[i][j]=0;
            ans=max(T[i][j],ans);
        }
    }
    // for(i=0;i<=m;i++)
    // {
    //     for(j=0;j<=n;j++)
    //     cout<<T[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<"Square Matrix Size:\t"<<ans<<endl;
    cout<<"Total Elements:\t"<<pow(ans,2)<<endl;
}
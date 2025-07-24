#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&coins, int sum, int n);
int main()
{
    vector<int> coins={1,2,3};
    int sum=4;
    func(coins,sum,coins.size());
    return 0;
}
void func(vector<int>&coins, int sum, int n)
{
    vector<vector<int>>T(n+1,vector<int>(sum+1,0));
    int i,j;
    for(i=0;i<=n;i++)
    T[i][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(j>=coins[i-1])
            T[i][j]=T[i-1][j]+T[i][j-coins[i-1]];
            else T[i][j]=T[i-1][j];
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        cout<<T[i][j]<<" ";
        cout<<endl;
    }
    cout<<"\nNumber of ways for coin change:\t"<<T[n][sum];
}
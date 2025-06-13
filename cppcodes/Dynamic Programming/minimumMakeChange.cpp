#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n,int sum);
int main()
{
    vector<int>a={1,2,3};
    int sum=5;
    func(a,a.size(),sum);
    return 0;
}
void func(vector<int>&a, int n,int sum)
{
    int T[n+1][sum+1];
    memset(T,0,sizeof(T));
    int i,j;
    for(i=0;i<=n;i++)
    T[i][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        {
            if(j>=a[i-1])
            T[i][j]=T[i-1][j]+T[i][j-a[i-1]];
            else T[i][j]=T[i-1][j];
        }
    }
    for(i=0;i<=n;i++)
    {
        cout<<endl;
        for(j=0;j<=sum;j++)
        cout<<T[i][j]<<" ";
    }
    cout<<endl;
    cout<<"Minimum number of ways to make Change:\t"<<T[n][sum]<<endl;
}
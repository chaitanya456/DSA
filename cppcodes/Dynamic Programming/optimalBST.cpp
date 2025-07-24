#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&freq, int n);
int calculateSum(vector<int>&a, int i,int j);
int main()
{
    vector<int> keys = {10, 12, 20};
    vector<int> freq = {34, 8, 50};
    func(freq,freq.size());
    return 0;
}
void func(vector<int>&freq, int n)
{
    int len,i,j;
    vector<vector<int>>T(n,vector<int>(n,0));
    for(i=0;i<n;i++)
    T[i][i]=freq[i];
    for(len=2;len<=n;len++)
    {
        for(i=0;i<=n-len;i++)
        {
            j=i+len-1;
            int sum=calculateSum(freq,i,j);
            T[i][j]=INT_MAX;
            for(int k=i;k<=j;k++)
            {
                int val=sum+(k-1<i?0:T[i][k-1])+(k+1>j?0:T[k+1][j]);
                if(val<T[i][j])
                T[i][j]=val;
            }
        }
    }
    cout<<"Minimum cost of BST:\t"<<T[0][n-1]<<endl;
}
int calculateSum(vector<int>&a, int i,int j)
{
    int c=0;
    int x;
    for(x=i;x<=j;x++)
    c+=a[x];
    return c;
}
#include<bits/stdc++.h>
using namespace std;
void matrixMult(vector<int> &a, int n);
int main()
{
    vector<int> a={1,2,3,4,3};
    int n=a.size();
    matrixMult(a,n);
    return 0;
}
void matrixMult(vector<int> &a, int n)
{
    int len,i,j,k;
    vector<vector<int> > T(n,vector<int>(n,0));
    for(len=2;len<n;len++)
    {
        for(i=0;i<n-len;i++)
        {
            j=i+len;
            // cout<<"Accessing Values at:\t"<<i<<" "<<j<<endl;
            T[i][j]=INT_MAX;
            for(k=i+1;k<j;k++)
            {
                int cost=T[i][k]+T[k][j]+a[i]*a[j]*a[k];
                T[i][j]=min(cost,T[i][j]);
            }
        }
    }
    cout<<"Min Cost:\t"<<T[0][n-1];
}
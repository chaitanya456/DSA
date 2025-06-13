#include<bits/stdc++.h>
using namespace std;
void rotateClockWise(vector<vector<int>>a, int m, int n);
int main()
{
    vector<vector<int>>a={
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
    };
    int m=a.size();
    int n=a[0].size();
    rotateClockWise(a,m,n);
    return 0;
}
void rotateClockWise(vector<vector<int>>a, int m, int n)
{
    vector<vector<int>> mat(n,vector<int>(m,0));
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        mat[i][j]=a[j][i];
    }
    for(auto &x: mat)
    reverse(x.begin(),x.end());
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
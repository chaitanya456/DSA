#include<bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>>& a);
void floydWarshall(vector<vector<int>>& a)
{
    int n=a.size();
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][k]!=INT_MAX && a[k][j]!=INT_MAX)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}
int main()
{
    int INF = INT_MAX;
    vector<vector<int>> a = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };
    floydWarshall(a);
    int i,j;
    for(i=0;i<a.size();i++)
    {
        for(j=0;j<a.size();j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
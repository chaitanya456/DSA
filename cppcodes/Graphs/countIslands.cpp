#include<bits/stdc++.h>
using namespace std;
int countIslands(vector<vector<int>>& a, int n, vector<vector<bool>>& vis);
void dfs(vector<vector<bool>>& vis,vector<vector<int>>& a, int r, int c,int n);
bool isSafe(int x, int y, int n,vector<vector<bool>>& vis,vector<vector<int>>& a );
int main()
{
    vector<vector<int>>a={{1,0,0,0,0},
                          {0,1,0,0,1},
                          {1,0,0,1,1},
                          {0,0,0,0,0},
                          {1,0,1,1,0}};
    int n=a.size();
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    cout<<"Number of Islands:\t"<<countIslands(a,n,vis);
    return 0;
}
int countIslands(vector<vector<int>>& a, int n, vector<vector<bool>>& vis)
{
    int islands=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        if(!vis[i][j] && a[i][j])
        {
            dfs(vis,a,i,j,n);
            islands++;
        }
    }
    return islands;
}
bool isSafe(int x, int y, int n,vector<vector<bool>>& vis,vector<vector<int>>& a )
{
    return (x>=0 && x<n && y>=0 && y<n && a[x][y] && !vis[x][y]);
}
void dfs(vector<vector<bool>>& vis,vector<vector<int>>& a, int r, int c,int n)
{
    vis[r][c]=true;
    static int x[]={-1,-1,-1,0,0,1,1,1};
    static int y[]={-1,0,1,-1,1,-1,0,1};
    int i;
    for(i=0;i<8;i++)
    {
        int nx=r+x[i];
        int ny=c+y[i];
        if(isSafe(nx,ny,n,vis,a))
        dfs(vis,a,nx,ny,n);
    }
}

#include<bits/stdc++.h>
using namespace std;
static int xArray[]={-2,-2,-1,-1,1,1,2,2};
static int yArray[]={-1,1,-2,2,-2,2,-1,1};
bool isSafe(int x, int y, int m, vector<vector<int>>&board);
vector<vector<int>> knightTour(int n);
bool backTrack(vector<vector<int>>&board, int x, int y, int step, int n);
int main()
{
    int n=5;
    vector<vector<int>> res=knightTour(n);
    cout<<"Knight's Tour:\n";
    for(auto x: res)
    {
        for(auto y: x)
        cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}
vector<vector<int>> knightTour(int n)
{
    vector<vector<int>> board(n, vector<int>(n,-1));
    board[0][0]=0;
    if(backTrack(board,0,0,1,n))
    return board;
    else return {{-1}};
}
bool backTrack(vector<vector<int>>&board, int x, int y, int step, int n)
{
    if(step==n*n)
    return 1;
    for(int k=0;k<8;k++)
    {
        int nx=x+xArray[k];
        int ny=y+yArray[k];
        if(isSafe(nx,ny,n,board))
        {
            board[nx][ny]=step;
            if(backTrack(board,nx,ny,step+1,n))
            return 1;
            board[nx][ny]=-1;
        }
    }
    return 0;
}
bool isSafe(int x, int y, int m, vector<vector<int>>&board)
{
    return (x>=0 && y>=0 && x<m && y<m && board[x][y]==-1 );
}
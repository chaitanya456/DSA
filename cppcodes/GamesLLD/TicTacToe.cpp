#include<bits/stdc++.h>
using namespace std;
class TicTacToe
{
    public:
    vector<vector<char>>board;
    int currentPlayer=1;
    TicTacToe()
    {
        board.resize(3,vector<char>(3,' '));
    }
    void print()
    {
        cout<<endl<<"-------"<<endl;
        for(int i=0;i<3;i++)
        {
            cout<<"|";
            for(int j=0;j<3;j++)
            {
                cout<<board[i][j]<<"|";   
            }
            cout<<endl<<"-------"<<endl;
        }
    }
    void gamePlay(int i, int j)
    {
        if(i<3 && i>=0 && j<3 && j>=0)
        board[i][j]=currentPlayer==1?'X':'O';
        currentPlayer=3-currentPlayer;
    }
    bool checkWinCondition()
    {
        for(int i=0;i<3;i++)
        {
            if(board[i][0]!=' ' && board[i][1]==board[i][0] && board[i][1]==board[i][2])
            return true;
            if(board[0][i]!=' ' && board[1][i]==board[0][i] && board[1][i]==board[2][i])
            return true;
        }
        if(board[0][0]!=' ' && board[0][0]==board[1][1] && board[1][1]==board[2][2]) return true;
        if(board[0][2]!=' ' &&board[0][2]==board[1][1] && board[1][1]==board[2][0]) return true;
        return false;
    }
    bool boardFull()
    {
        for(auto x: board)
        for(auto y:x)
        if(y==' ')
        return false;
        return true;
    }
};
int main()
{
    TicTacToe t;
    vector<vector<int>>moves={{0,0},{0,1},{1,1},{1,0},{2,2}};
    for(auto move: moves)
    {
        t.gamePlay(move[0], move[1]);
        t.print();
        if(t.checkWinCondition())
        break;
    }
    if(t.boardFull()) cout<<"Its a draw"<<endl;
    else if(t.checkWinCondition())
    cout<<endl<<"Player "<<3-t.currentPlayer<<" wins!";
    else cout<<endl<<"Player "<<t.currentPlayer<<" wins!";
    return 0;
}
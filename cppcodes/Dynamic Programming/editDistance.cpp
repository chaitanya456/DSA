#include<bits/stdc++.h>
using namespace std;
void editDistance(string a,string b,int x, int y);
int main()
{
    string a="CHALI";
    int x=a.length();
    string b="NELLI";
    int y=b.length();
    editDistance(a,b,x,y);
    return 0;
}
void editDistance(string a,string b,int x, int y)
{
    int T[x+1][y+1];
    int i,j;
    for(i=0;i<=x;i++)
    T[i][0]=i;
    for(i=0;i<=y;i++)
    T[0][i]=i;
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++)
        {
            if(a[i-1]==b[j-1])
            T[i][j]=T[i-1][j-1];
            else 
            T[i][j]=1+min(T[i-1][j-1],min(T[i-1][j],T[i][j-1]));
        }
    }
     for(i=0;i<=x;i++)
    {
        cout<<endl;
        for(j=0;j<=y;j++)
        {
            cout<<T[i][j]<<" ";
        }
    }
    cout<<endl<<"Edit Distance between 2 strings are:\t"<<T[x][y];
}
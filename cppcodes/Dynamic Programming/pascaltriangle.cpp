#include<bits/stdc++.h>
using namespace std;
void printPascal(int n);
int main()
{
    int n;
    cout<<"Enter # of rows to print Pascal Triangle:\t";
    cin>>n;
    cout<<endl;
    printPascal(n);
    return 0;
}
void printPascal(int n)
{
    int i,j;
    int T[n+1][n+1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(j==1 || i==j)
            T[i][j]=1;
            else
            T[i][j]=T[i-1][j]+T[i-1][j-1];
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<endl;
        for(j=1;j<=i;j++)
        cout<<T[i][j]<<" ";
    }
}
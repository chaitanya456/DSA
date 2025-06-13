//This is to implement Fibonacci in O(logN)
#include<bits/stdc++.h>
using namespace std;
void calculatePower(vector<vector<int>>&m,int n);
void multiply(vector<vector<int>> &a,vector<vector<int>> &b);
int main()
{
    int n=5;
    vector<vector<int>>m={{1,1},{1,0}};
    calculatePower(m,n-1);
    cout<<"Nth Fibonacci:\t"<<m[0][0];
    return 0;
}
void calculatePower(vector<vector<int>>&m,int n)
{
    if(n==0 || n==1 )
    return ;
    vector<vector<int>> help={{1,1},{1,0}};
    calculatePower(m,n/2);
    multiply(m,m);
    if(n%2)
    multiply(m,help);
}
void multiply(vector<vector<int>> &a,vector<vector<int>> &b)
{
    
    int x=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    int y=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    int i=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    int j=a[1][0]*b[0][1]+a[1][1]*b[1][1];

    a[0][0]=x;
    a[0][1]=y;
    a[1][0]=i;
    a[1][1]=j;
}
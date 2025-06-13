#include<bits/stdc++.h>
using namespace std;
void printDiagonal(vector<vector<int>>a, int m , int n);
int main()
{
    vector<vector<int>>a={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };
    int m=a.size();
    int n=a[0].size();
    printDiagonal(a,m,n);
    return 0;
}
void printDiagonal(vector<vector<int>>a, int m , int n)
{
    vector<int>res;
    int i,j;
    for(i=0;i<m;i++)
    {
        j=i;
        int k=0;
        while(k<n && j>=0)
        res.push_back(a[j][k]),j--,k++;
    }
    for(j=1;j<n;j++)
    {
        i=m-1;
        int k=j;
        while(i>=0 && k<n)
        res.push_back(a[i][k]),i--,k++;
    }
    cout<<"Matrix in Diagonal Form:\t";
    for(auto x: res)
    cout<<x<<" ";
}
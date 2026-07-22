#include<bits/stdc++.h>
using namespace std;
void printDiagonal(vector<vector<int>>&a, int m, int n)
{
    int i,j,k;
    cout<<"Diagonal:";
    for(i=0;i<m;i++)
    {
        j=i,k=0;
        cout<<endl;
        while(k<n && j>=0)
        {
            cout<<a[j][k]<<" ";
            j--,k++;
        }
    }
    for(i=1;i<n;i++)
    {
        k=i;
        j=m-1;
        cout<<endl;
        while(j>=0 && k<n)
        {
            cout<<a[j][k]<<" ";
            j--,k++;
        }
    }
}
int main()
{
    vector<vector<int>>a={{1,2,3,4},
        {5,6,7,8},{9,10,11,12},
        {13,14,15,16},{17,18,19,20}
    };
    int m=a.size();
    int n=a[0].size();
    printDiagonal(a,m,n);
    return 0;
}
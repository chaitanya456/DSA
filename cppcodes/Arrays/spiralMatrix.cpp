#include<bits/stdc++.h>
using namespace std;
void printSpiral(vector<vector<int>>& a, int m, int n);
int main()
{
    vector<vector<int>>a={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int m=a.size();
    int n=a[0].size();
    printSpiral(a,m,n);
    return 0;
}
void printSpiral(vector<vector<int>>& a, int m, int n)
{
    int top=0,left=0;
    int right=n-1, bottom=m-1;
    int i;
    cout<<"Spiral Print:\t";
    while(left<right && top<bottom)
    {
        for(i=left;i<=right;i++)
        cout<<a[top][i]<<" ";
        top++;
        for(i=top;i<=bottom;i++)
        cout<<a[i][right]<<" ";
        right--;
        if(left<=right)
        {
            for(i=right;i>=left;i--)
            cout<<a[bottom][i]<<" ";
            bottom--;
        }
        if(top<=bottom)
        {
            for(i=bottom;i>=top;i--)
            cout<<a[i][left]<<" ";
            left++;
        }
    }
}
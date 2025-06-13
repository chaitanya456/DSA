#include<bits/stdc++.h>
using namespace std;
void func(int m, int n, vector<vector<int>>& a);
int main()
{
    vector<vector<int>>a={
        { 0, 0, 0, 1 },
        { 0, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 0, 0, 0, 0 }
    };
    int m=a.size();
    int n=a[0].size();
    func(m,n,a);
    return 0;
}
void func(int m, int n, vector<vector<int>>& a)
{
    //Start with top right
    int r=0,c=n-1;
    int maxRow=INT_MIN;
    while(r<m && c>=0)
    {
        if(!a[r][c])
        r++;
        else
        {
            maxRow=max(r,maxRow);
            c--;
        }
    }
    cout<<"The Row with Max number of 1s is:\t"<<maxRow<<endl;
}

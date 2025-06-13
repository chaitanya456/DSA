#include<bits/stdc++.h>
using namespace std;
int minJumps(vector<int>a,int n);
int main()
{
    vector<int>a={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n=a.size();
    cout<<"Minumum Jumps to reach end:\t"<<minJumps(a,n)<<endl;
    return 0;
}
int minJumps(vector<int>a,int n)
{
    if(a[0]==0)
    return -1;
    vector<int>T(n,INT_MAX);
    int i,j;
    T[0]=0;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(i<=j+a[j])
            {
                T[i]=min(T[i],T[j]+1);
                break;
            }
        }
    }
    // cout<<"Array:\t";
    // for(auto x:T)
    // cout<<x<<" ";
    return T[n-1];
}
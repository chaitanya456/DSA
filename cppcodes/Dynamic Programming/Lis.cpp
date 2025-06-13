#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int>a={1,-1,2,4,7,0};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>&a, int n)
{
    int i,j;
    int T[n];
    for(i=0;i<n;i++)
    {
        T[i]=1;
        for(j=0;j<i;j++)
        {
            if(a[i]>=a[j] && T[i]<T[j]+1)
            T[i]=T[j]+1;
        }
    }
    // for(auto x: T)
    // cout<<x<<" ";
    cout<<"Longest Increasing Subsequence\t"<<*max_element(T,T+n);
}
#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int> a={1, 101, 2, 3, 100};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>&a, int n)
{
    vector<int>T(n);
    int ans=INT_MIN;
    int i,j;
    for(i=0;i<n;i++)
    {
        T[i]=a[i];
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i])
            T[i]=max(T[i],a[i]+T[j]);
        }
        ans=max(ans,T[i]);
    }
    cout<<"Maximum Increasing Sum Subsequence:"<<ans<<endl;
}
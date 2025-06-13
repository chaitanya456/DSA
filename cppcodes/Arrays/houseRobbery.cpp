#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
void iterativeWay(vector<int>&a, int n);
int main()
{
    vector<int> arr = {6, 5, 5, 7, 4};
    int n=arr.size();
    func(arr,n);//My favourite DP approach
    iterativeWay(arr,n);//Space complexity: O(1)
    return 0;
}
void func(vector<int>&a, int n)
{
    vector<int>T(n+1,0);
    T[0]=0;
    T[1]=a[0];
    for(int i=2;i<=n;i++)
    T[i]=max(T[i-1],T[i-2]+a[i-1]);
    cout<<"Maximum Profit:\t"<<T[n]<<endl;
}
void iterativeWay(vector<int>&a, int n)
{
    int pickOld=0;
    int old=a[0];
    int res=INT_MIN;
    for(int i=1;i<n;i++)
    {
        res=max(pickOld+a[i],old);
        pickOld=old;
        old=res;
    }
    cout<<"Iterative Answer:\t"<<res<<endl;
}
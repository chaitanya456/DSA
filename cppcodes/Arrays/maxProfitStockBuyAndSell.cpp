#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>&a, int n);
int main()
{
    vector<int>a={100, 180, 260, 310, 40, 535, 695};
    int n=a.size();
    cout<<"Maximum Profit:\t"<<maxProfit(a,n);
    return 0;
}
int maxProfit(vector<int>&a, int n)
{
    int profit=0;
    int i;
    for(i=1;i<n;i++)
    if(a[i-1]<a[i])
    profit+=a[i]-a[i-1];
    return profit;
}
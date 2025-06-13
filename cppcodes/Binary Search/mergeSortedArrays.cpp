#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>a,vector<int>b,vector<int> res);
int main()
{
    vector<int> a={1,3,5,7,7};
    vector<int> b={2,4,4,6,8,9,9,20};
    vector<int> res;
    cout<<"After merging the arrays, we get:\t";
    merge(a,b,res);
    return 0;
}
void merge(vector<int>a,vector<int>b,vector<int> res)
{
    int i=0,j=0;
    int m=a.size(),n=b.size();
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        res.push_back(a[i]),i++;
        else
        res.push_back(b[j]),j++;
    }
    while(i<m)
    {
        res.push_back(a[i]),i++;
    }
    while(j<n)
    {
        res.push_back(b[j]),j++;
    }
    for(auto x:res)
    cout<<x<<" ";
}
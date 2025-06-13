#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int> a= {2,5, 2, 8, 5, 6, 8, 8};
    int n=a.size();
    func(a,n);
    return 0;
}
bool comp(pair<int,int>&a, pair<int,int>&b)
{
    if(a.second==b.second)
    return a.first<b.first;
    return a.second>b.second;
}
void func(vector<int>&a, int n)
{
    unordered_map<int, int> m;
    for(auto x: a)
    m[x]++;
    vector<pair<int,int>> res(m.begin(),m.end());
    sort(res.begin(),res.end(),comp);
    cout<<"Sorting elements by frequency:\t";
    for(auto x: res)
    {
        while(x.second--)
        cout<<x.first<<" ";
    }
}
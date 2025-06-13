#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &a, int n);
int nextGreater(int x, vector<int>&a, int i,vector<int>&rh);
int main()
{
    // vector<int> a={1,2,3,4,5,6,7,8,4,9,8,7,6,5,4,3,2,1};
    vector<int>a={1,9,3,2,6};
    // next_permutation(a.begin(),a.end());
    // for(auto x:a)
    // cout<<x<<" ";
    nextPermutation(a,a.size());
    return 0;
}
void nextPermutation(vector<int> &a, int n)
{
    int i,index;
    for(i=n-2;i>=0;i--)
    {
        if(a[i+1]>a[i])
        {
            index=i;
            break;
        }
    }
    vector<int>lh(a.begin(),a.begin()+index);
    vector<int>rh(a.begin()+index+1, a.end());
    int ng=nextGreater(a[index],a,index,rh);
    lh.push_back(ng);
    rh.push_back(a[index]);
    sort(rh.begin(),rh.end());
    for(auto x:rh)
    lh.push_back(x);
    cout<<"Next Permutation:\t";
    for(auto x: lh)
    cout<<x<<" ";
}
int nextGreater(int x, vector<int>&a, int i,vector<int>&rh)
{
    int mini=INT_MAX;
    i++;
    while(i<a.size())
    {
        if(a[i]>x)
        mini=min(mini,a[i]);
        i++;
    }
    auto it=find(rh.begin(),rh.end(),mini);
    if(it!=rh.end())
    rh.erase(it);
   return mini;
}
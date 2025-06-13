#include<bits/stdc++.h>
using namespace std;
vector<int>subsets;
void func(vector<int> a, int i,int n);
int main()
{
    vector<int>a={1,2,3};
    int n=a.size();
    func(a,0,n-1);
    return 0;
}
void func(vector<int> a, int i,int n)
{
    if(i==a.size())
    {
        for(auto x: subsets)
        cout<<x<<" ";
        cout<<endl;
        return;
    }
    subsets.push_back(a[i]);
    func(a,i+1,n);
    subsets.pop_back();
    func(a,i+1,n);
}
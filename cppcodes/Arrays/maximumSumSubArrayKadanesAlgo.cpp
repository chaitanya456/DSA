#include<bits/stdc++.h>
using namespace std;
void func(vector<int>a, int n);
int main()
{
    vector<int>a={2,3,-8,7,-1,2,3};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>a, int n)
{
    int i;
    int res,max_ending;
    res=a[0];
    max_ending=a[0];
    for(i=1;i<n;i++)
    {
        max_ending=max(max_ending+a[i],a[i]);
        res=max(max_ending,res);
    }
    cout<<"Maximum Sum Subarray:\t"<<res<<endl;
}
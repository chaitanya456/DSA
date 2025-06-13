#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int> a={1,2,3,2,1,4};
    func(a,a.size());
    return 0;
}
void func(vector<int>&a, int n)
{
    int xor_value=0;
    for(auto x: a)
    xor_value^=x;
    int right_set_bit=(xor_value)&(-xor_value);
    vector<int>res(2,0);
    for(int i=0;i<n;i++)
    {
        if(right_set_bit & a[i])
        res[0]^=a[i];
        else 
        res[1]^=a[i];
    }
    sort(res.begin(),res.end());
    cout<<"Two Unique numbers are:\t";
    cout<<res[0]<<" "<<res[1]<<endl;
}
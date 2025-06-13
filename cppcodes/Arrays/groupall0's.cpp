#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a={0,1,1,1,0,0,0};
    int i;
    int n=a.size();
    int l=0,r=n-1;
    while(l<r)
    {
        if(a[l]==0)
        l++;
        else
        {
            if(a[r]==0)
            {
                swap(a[l],a[r]);
                l++;
                r--;
            }
            else
            {
                r--;
            }
        }
    }
    for(auto x: a)
    cout<<x<<" ";
    return 0;
}
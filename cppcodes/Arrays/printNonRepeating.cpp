#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a={1,1,2,2,3,3,4,4,5};
    int n=a.size(),i,xor_value=0;
    for(i=0;i<n;i++)
    xor_value=a[i]^xor_value;
    cout<<"Single Value:\t"<<xor_value;
    return 0;
}
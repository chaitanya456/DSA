// Not finished.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    bitset<32> num(11);
    bitset<32>r;
    int i;
    for(i=0;i<32;i++)
    r[i]=num[31-i];
    // for(auto x:r)
    // cout<<x;
    cout<<r.to_ulong()<<endl;
    return 0;
}
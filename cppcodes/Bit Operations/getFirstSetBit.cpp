#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number:\t";
    cin>>n;
    cout<<"Its First set bit is in position:\t"<<__builtin_ffs(n);
    return 0;
}

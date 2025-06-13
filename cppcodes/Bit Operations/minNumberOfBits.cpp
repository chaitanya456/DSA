#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter 1st Number:\t";
    cin>>a;
    cout<<"Enter 2nd Number:\t";
    cin>>b;
    cout<<"Minimum Number of Bits to convert from "<<a<<" to "<<b<<" is "<<__builtin_popcount(a^b)<<endl;
    return 0;
}
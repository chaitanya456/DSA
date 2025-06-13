#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=3,b=2;
    while(b!=0)
    {
        int carry=(a&b)<<1;
        a=a^b;
        b=carry;
    }
    cout<<"Addition of two numbers is:\t"<<a<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=4, b=3;
    int sum;
    while(b!=0)
    {
        int carry=(a&b)<<1;
        sum=a^b;
        b=carry;
    }
    cout<<"Sum of the numbers is :\t"<<sum<<endl;
    return 0;
}
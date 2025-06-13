#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned short int n=23;//unsigned short int takes 2 bytes hence mask size is also 2B
    unsigned short int  even_bits=n & 0xAAAA;//Even Mask which has 1 in even positions
    unsigned short int  odd_bits=n & 0x5555;//Odd Mask which has 1 in odd positions
    even_bits>>=1;
    odd_bits<<=1;
    unsigned short int res=even_bits | odd_bits;
    cout<<"After Swapping even and Odd Bits we get:\t"<<res;
    return 0;
}
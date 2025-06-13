#include<bits/stdc++.h>
using namespace std;
void reverse(int num);
const int num_bits=4;
int main()
{
    int num=7;
    reverse(num);
    return 0;
}
void reverse(int num)
{
    int reverse_num=0;
    int i;
    for(i=0;i<num_bits;i++)
    if(num & (1<<i)) //Check if ith bit is set or not.
    reverse_num|=(1<<(num_bits-i-1)); //Shift it to reverse number in (num_bits-i) position.
    cout<<"Reverse of Number "<<num<<" is:\t"<<reverse_num;
}
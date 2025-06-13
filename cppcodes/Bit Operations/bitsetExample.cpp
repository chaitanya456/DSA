#include<bits/stdc++.h>
using namespace std;
void reverse(bitset<8> b);
int main()
{
    bitset<8> a(5);
    cout<<"Binary:\t"<<a<<endl;
    bitset<8> b=a;
    reverse(b);
    return 0;
}
void reverse(bitset<8> b)
{
    int i;
    for(i=0;i<4;i++)
    {
        bool x=b[i];
        b[i]=b[8-i-1];
        b[8-i-1]=x;
    }
    cout<<"Reverse Binary:\t"<<b<<endl;
}
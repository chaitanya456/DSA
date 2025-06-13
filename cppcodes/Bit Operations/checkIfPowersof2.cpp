//powers of 2 contain the value where the most significant bit is 1 and rest 0's 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number:\t";
    cin>>n;
    if(n&&!(n &(n-1)))//to handle 0 we are using n && (n-1)
    cout<<"Powers of 2";
    else 
    cout<<"Not powers of 2";
    return 0;
}
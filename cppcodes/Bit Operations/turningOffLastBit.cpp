#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number:\t";
    cin>>n;
    n=n&(n-1);
    cout<<"After turning it off, we get:\t"<<n<<endl;
    return 0;
}
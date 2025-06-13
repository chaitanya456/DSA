#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a={1,0,9,9,9,9,10,10,10,11,11};
    int n=a.size(),x;
    cout<<"Enter element(x):\t";
    cin>>x;
    cout<<"Freq/Count(x):\t"<<count(a.begin(),a.end(),x);
    return 0;
}
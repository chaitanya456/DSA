#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a={1,3,4,3,2,1,4};
    int i;
    int xor_value=a[0];
    for(i=1;i<a.size();i++)
    xor_value^=a[i];
    cout<<"Only One Odd Occurence is:\t"<<xor_value<<endl;
    return 0;
}
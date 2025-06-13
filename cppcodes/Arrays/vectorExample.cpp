#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a={1,3,5,4,2,2};
    vector<int>::iterator it;
    for(it=a.begin();it!=a.end();it++)
    cout<<*it<<" ";
    auto x=binary_search(a.begin(),a.end(),2);
    cout<<endl<<x<<endl;
    return 0;
}
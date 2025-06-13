#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a={2,6,7,9,10,15};
    int n=a.size();
    bool x=binary_search(a.begin(),a.end(),10);
    auto ptr=lower_bound(a.begin(),a.end(),10)-a.begin();
    if(x)
    cout<<"Element found at index:\t"<<ptr;
    else cout<<"Element does not exist!";
    return 0;
}
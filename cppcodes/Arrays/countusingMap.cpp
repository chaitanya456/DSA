#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,int> m;
    vector<int> a={3,3,3,4,4,5,5,5,5,5,5,6};
    int n=a.size();
    for(auto x:a)
    m[x]++;
    cout<<"Count of each element in map:\n";
    for(auto x:m)
    {
        cout<<x.first<<"->"<<x.second<<endl;
    }
    return 0;
}
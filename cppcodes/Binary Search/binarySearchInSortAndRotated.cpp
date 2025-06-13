#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a={5,6,7,8,9,1,2,3};
    int n=a.size();
    int key=2;
    auto it=is_sorted_until(a.begin(),a.end())-a.begin();
    cout<<"Pivot element present at:\t";
    cout<<it-1<<endl;
    if(key>a[0])
    cout<<"searching in left half of rotated array:"<< *lower_bound(a.begin(),a.begin()+it-1,key);
    else 
        cout<<"searching in the right half of rotated array:"<<*lower_bound(a.begin()+it-1,a.end(),key);
    return 0;
}
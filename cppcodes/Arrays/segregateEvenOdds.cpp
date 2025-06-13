#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int>a={ 12, 10, 9, 45, 2, 10, 10, 45 };
    stable_partition(a.begin(),a.end(),[](auto a){
        return (a%2)==0;
    }); //This is Lambda Expression usage in cpp
    for(auto x: a)
    cout<<x<<" ";
    cout<<"\n Using Function 2 pointers:\t";
    func(a,a.size());
    return 0;
}
void func(vector<int>&a, int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while(!(a[i]%2) && i<j)//Find point where first point is odd
        i++;
        while((a[i]%2) && i<j)//Find point where first point is even
        j--;
        if(i<j)
        swap(a[i],a[j]),i++,j--;
    }
    for(auto x: a)
    cout<<x<<" ";
}
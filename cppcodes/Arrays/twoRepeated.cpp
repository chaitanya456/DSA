#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int> a={1,3,5,4,3,2,5};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>&a, int n)
{
    int i;
    int x=-1,y=-1;
    for(i=0;i<n;i++)
    {
        if(a[abs(a[i])]>0)
        a[abs(a[i])]=-a[abs(a[i])];
        else
        if(x==-1) x=abs(a[i]);
        else y=abs(a[i]);
    }
    cout<<"The Two Repeating Elements are:\t"<<x<<" "<<y<<endl;
}
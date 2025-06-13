#include<bits/stdc++.h>
using namespace std;
void getFloor(vector<int> a,int x);
void getCeiling(vector<int> a,int x);
int main()
{
    vector<int> a={2,4,6,8,10};
    int x;
    cout<<"Enter element which you need to floor and ceiling:\t";
    cin>>x;
    if(binary_search(a.begin(),a.end(),x))
    cout<<"Floor and Ceiling:\t"<<x<<endl;
    else
    {
        getFloor(a,x);
        cout<<endl;
        getCeiling(a,x);
    }
    return 0;
}
void getFloor(vector<int> a,int x)
{
    cout<<"\nFloor(x):\t";
        if(x<a[0])
        cout<<"Floor doesn't exist\n";
        else
        {
            auto it=lower_bound(a.begin(),a.end(),x)-a.begin();
            cout<<a[it-1];
        }
}
void getCeiling(vector<int> a,int x)
{
    cout<<"Ceiling(x):\t";
        if(x>a[a.size()-1])
        cout<<"Ceil doesn't exist\n";
        else
        {
            auto it=lower_bound(a.begin(),a.end(),x)-a.begin();
            cout<<a[it];
        }
}

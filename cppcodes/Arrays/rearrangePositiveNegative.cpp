#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int>a={ -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>&a, int n)
{
    vector<int>pos,neg;
    for(auto x: a)
    if(x>=0) pos.push_back(x);
    else neg.push_back(x);
    bool flag=1;
    int k=0;
    int i=0,j=0;
    int index=0;
    while(i<pos.size() && j< neg.size())
    {
        if(flag)
        {
            a[index++]=pos[i];
            i++;
        }
        else
        {
            a[index++]=neg[j];
            j++;
        }
        flag=!flag;
    }
    while(i<pos.size())
    a[index++]=pos[i++];
    while(j<neg.size())
    a[index++]=neg[j++];
    cout<<"After Rearranging positive and negative, we get:\t";
    for(auto x: a)
    cout<<x<<" ";
}
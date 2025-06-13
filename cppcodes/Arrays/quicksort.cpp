#include<bits/stdc++.h>
using namespace std;
void quickSort(vector<int>&a, int l, int n);
int partition(vector<int>&a, int l, int r);
int main()
{
    vector<int>a={12,4,5,6,9,0};
    int n=a.size();
    quickSort(a,0,n-1);
    cout<<"After Sorting:\t";
    for(auto x:a)
    cout<<x<<" ";
    return 0;
}
void quickSort(vector<int>&a, int l, int r)
{
    if(l<r)
    {
        int q=partition(a,l,r);
        quickSort(a,l,q-1);
        quickSort(a,q+1,r);
    }
}
int partition(vector<int>&a, int l, int r)
{
    int pivot=a[r];
    int i=l;
    int j=l-1;
    for(;i<=r;i++)
    {
        if(a[i]<pivot)
        {
            j++;
            swap(a[i],a[j]);
        }
    }
    swap(a[j+1],a[r]);
    return j+1;
}
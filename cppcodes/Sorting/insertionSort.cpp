#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>a,int n);
int main()
{
    vector<int>a={3,6,1,4,2};
    int n=a.size();
    insertionSort(a,n);
    return 0;
}
void insertionSort(vector<int>a,int n)
{
    int i,key,j;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && key<a[j])
        {
           swap(a[j],a[j+1]);
           j--;
        }
        a[j+1]=key;
    }
    cout<<"After sorting:\t";
    for(auto x: a)
    {
        cout<<x<<" ";
    }
}
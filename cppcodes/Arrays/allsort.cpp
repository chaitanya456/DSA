#include<bits/stdc++.h>
using namespace std;
void sorting(vector<int>&a, int n);
int main()
{
    vector<int>a={5,1,3,2,4};
    int n=a.size();
    sorting(a,n);
    cout<<"After Sorting:\t";
    for(auto x: a)
    cout<<x<<" ";
    return 0;
}
void merge(vector<int>&a, int l, int m, int r)
{
    vector<int>L(a.begin()+l,a.begin()+m+1);
    vector<int>R(a.begin()+m+1, a.begin()+r+1);
    int k=l,j,i;
    for(i=0, j=0;i<L.size() && j< R.size();)
    {
        if(L[i]<=R[j])
        a[k++]=L[i],i++;
        else if(R[j]<L[i])
        a[k++]=R[j],j++;
    }
    while(i<L.size())
    a[k++]=L[i],i++;
    while(j<R.size())
    a[k++]=R[j],j++;
}
void mergeSort(vector<int>&a, int l, int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
void sorting(vector<int>&a, int n)
{
    //selection sort
    // int i,j;
    // for(i=0;i<n;i++)
    // {
    //     for(j=i+1;j<n;j++)
    //     if(a[j]<a[i])
    //     swap(a[i],a[j]);
    // }
    
    //Bubble sort
    // int i;
    // for(i=0;i<n;i++)
    // {
    //     for(int j=0;j<n-1;j++)
    //     if(a[j]>a[j+1])
    //     swap(a[j],a[j+1]);
    // }
    
    //inserion sort
    // for(int i=0;i<n;i++)
    // {
    //     int key=a[i];
    //     int j=i-1;
    //     while(j>=0 && a[j]>key)
    //     a[j+1]=a[j],j--;
    //     a[j+1]=key;
    // }
    mergeSort(a,0,n-1);
}
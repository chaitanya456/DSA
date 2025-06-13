#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&a, int n);
int main()
{
    vector<int> a={5,4,2,1,3};
    int n=a.size();
    selectionSort(a,n);
    return 0;
}
void selectionSort(vector<int>&a, int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            swap(a[i],a[j]);
        }
    }
    cout<<"After Sorting:\t";
    for(auto x: a)
    cout<<x<<" ";
}
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>&a, int n);
int main()
{
    vector<int> a={5,4,2,1,3};
    int n=a.size();
    bubbleSort(a,n);
    return 0;
}
void bubbleSort(vector<int>&a, int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        if(a[j]>a[j+1])
        swap(a[j],a[j+1]);
    }
    cout<<"After Sorting:\t";
    for(auto x: a)
    cout<<x<<" ";
}
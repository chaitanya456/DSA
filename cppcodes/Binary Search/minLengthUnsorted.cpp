#include<bits/stdc++.h>
using namespace std;
void minimumLengthUnsorted(vector<int>a,int n);
int main()
{
    // vector<int> a={10,12,20,30,25,40,32,31,35,50,60};
    vector<int>a={0, 1, 15, 25, 6, 7, 30, 40, 50};
    int n=a.size();
    minimumLengthUnsorted(a,n);
    return 0;
}
void minimumLengthUnsorted(vector<int>a,int n)
{
    int i,e;
    int s=is_sorted_until(a.begin(),a.end())-a.begin();
    for(i=n-1;i>=0;i--)
    {
        if(a[i-1]>a[i])
        {
            e=i-1;
            break;
        }
    }
    int mn=*min_element(a.begin()+s,a.begin()+s+e);
    int mx=*max_element(a.begin()+s,a.begin()+s+e);
    for(i=0;i<s;i++)
    if(a[i]>mn)
    {
        s=i;
        break;
    }
    for(i=n-1;i>e;i--)
    if(a[i]<mx)
    {
        e=i;
        break;
    }
    cout<<"In order to sort the whole array, Please check indices:\t"<<s<<"&"<<e<<endl;
}
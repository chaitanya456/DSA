#include<bits/stdc++.h>
using namespace std;
void func(vector<int>a, int n);
int main()
{
    vector<int>a={-2,6,-3,-10,0,2};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>a, int n)
{
    int pp=1,sp=1;//prefix_prod=1, suffix_prod=1;
    int res=INT_MIN;
    for(int i=0;i<n;i++)
    {
       if(pp==0)
       pp=1;
       if(sp==0)
       sp=1;
       pp*=a[i];
       sp*=a[n-i-1];
       res=max(pp,max(sp,res));
    }
    cout<<"Maximum Product:\t"<<res<<endl;
}

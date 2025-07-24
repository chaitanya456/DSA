#include<bits/stdc++.h>
using namespace std;
void func(vector<int>& a, int n, int len);
int main()
{ 
    vector<int>a={1,2,3,4};
    int length=5;
    func(a,a.size(),length);
    return 0;
}
void func(vector<int>& a, int n, int len)
{
    vector<vector<int>>T(n+1,vector<int>(len+1,0));
    int i,j;
    for(i=0;i<=n;i++)
    T[i][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=len;j++)
        {
            if(j<a[i-1])
            T[i][j]=T[i-1][j];
            else
            T[i][j]=max(T[i-1][j], a[i-1]+T[i][j-i]);
        }
    }
    cout<<"Maximum Profit:\t"<<T[n][len]<<endl;
}   

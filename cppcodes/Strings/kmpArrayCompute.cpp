#include<bits/stdc++.h>
using namespace std;
void compute(string s, int n);
int main()
{
    // string s="abcabcy";
    string s="acacabacacabacacac";
    int n=s.size();
    compute(s,n);
    return 0;
}
void compute(string s, int n)
{
    int i,j=0;
    i=1;
    vector<int>T(n,0);
    while(i<n)
    {
        if(s[i]==s[j])
        T[i]=j+1,i++,j++;
        else
        {
            if(j!=0)
            j=T[j-1];
            else T[i]=0,i++;
        }
    }
   for(auto x: T)
   cout<<x<<" ";
}
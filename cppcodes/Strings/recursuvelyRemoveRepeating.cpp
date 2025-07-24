#include<bits/stdc++.h>
using namespace std;
void func(string &s, int n);
int  main()
{
    // string s="abccbccba";
    string s="geeksforgeeks";
    func(s,s.size());
    cout<<"After removing consecutive duplicates recursively:\t"<<s<<endl;
    return 0;
}
void func(string &s, int n)
{
    int k=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(i+1<n && s[i]==s[i+1])
        {
            while(i+1<n && s[i]==s[i+1])
            i++;
        }
        else
        s[k++]=s[i];
    }
    s.erase(k);
    if(k!=n)
    func(s,k);
}
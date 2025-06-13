#include<bits/stdc++.h>
using namespace std;
string func(string s, int n);
int main()
{
    string s="aaaabbccccccdeeeeee";
    int n=s.length();
    string res=func(s,n);
    cout<<"RLE:\t"<<res<<endl;
    return 0;
}
string func(string s, int n)
{
    int i;
    string res;
    for(i=0;i<n;)
    {
        int c=1;
        while(i+1<n && s[i]==s[i+1])
        c++,i++;
        res.push_back(s[i]);
        res.push_back(c+'0');
        i++;
    }
    return res;
}
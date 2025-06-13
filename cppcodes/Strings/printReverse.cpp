#include<bits/stdc++.h>
using namespace std;
void func(string s,int index);
int main()
{
    string s;
    cout<<"Enter String:\t";
    cin>>s;
    func(s,0);
    return 0;
}
void func(string s,int index)
{
    if(index==s.length())
    return;
    func(s,index+1);
    cout<<s[index]<<"";
}
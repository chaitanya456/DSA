#include<bits/stdc++.h>
using namespace std;
void func(string s, int n);
int main()
{
    string x="  -0012g4";
    int n=x.length();
    func(x,n);
    return 0;
}
void func(string s, int n)
{
    int i=0;
    while(s[i]==' ')
    i++;
    int sign=1;
    int res=0;
    if(s[i]=='-')
    sign=-1,i++;
    while(s[i]>='0' && s[i]<='9')
    {
        res=res*10+(s[i]-'0');
        i++;
    }
    cout<<"Value:\t"<<res*sign;

}
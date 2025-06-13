#include<bits/stdc++.h>
using namespace std;
bool func(string &a, int n);
int main()
{
    // string a="[{(])}]";
    string a="[{()}]";
    int n=a.size();
    if(func(a,n))
    cout<<"Balanced";
    else cout<<"Not Balanced";
    return 0;
}
bool func(string &a, int n)
{
    int i;
    stack<char>st;
    for(i=0;i<n;i++)
    {
        char x=a[i];
        if(x=='(' || x=='{' || x=='[')
        st.push(x);
        else if(!st.empty() && st.top()=='[' && x==']')
            st.pop();
        else if(!st.empty() && st.top()=='{' && x=='}')
            st.pop();
        else if(!st.empty() && st.top()=='(' && x==')')
            st.pop();
        else return 0;
    }
    return st.empty();
}
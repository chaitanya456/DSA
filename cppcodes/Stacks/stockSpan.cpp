#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int>a={10, 4, 5, 90, 120, 80};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>&a, int n)
{
    stack<int>st;
    st.push(0);
    int i;
    vector<int>res;
    res.push_back(1);
    for(i=1;i<n;i++)
    {
        while(!st.empty() && a[st.top()]<=a[i])
        st.pop();
        if(st.empty())
        res.push_back(i+1);
        else res.push_back(i-st.top());
        st.push(i);
    }
    cout<<"After Stock Span:\t";
    for(auto x: res)
    cout<<x<<" ";
}
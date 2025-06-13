#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n);
int main()
{
    vector<int>a={60, 20, 50, 40, 10, 50, 60};
    int n=a.size();
    func(a,n);
    return 0;
}
void func(vector<int>&a, int n)
{
    stack<int> st;
    int i;
    int maxArea=INT_MIN;
    st.push(0);
    for(i=1;i<n;i++)
    {
        while(!st.empty() && a[st.top()]>=a[i])
        {
            int t=st.top();
            st.pop();
            int width=(st.empty())?i:(i-st.top()-1);
            maxArea=max(a[t]*width,maxArea);
        }    
        st.push(i);
    }
    while(!st.empty())
    {
        int t=st.top();
        st.pop();
        int width=(st.empty())?i:(i-st.top()-1);
        maxArea=max(a[t]*width,maxArea);
    }
    cout<<"Area of Largest histogram:\t"<<maxArea<<endl;
}
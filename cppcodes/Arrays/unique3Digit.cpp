#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a={1,2,3,4};
    int n=a.size();
    int i;
    bool flag=0;
    unordered_set<int> even;
    int remaining_digits=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            if(!a[i])
            flag=1;
            even.insert(a[i]);
        }
        if(even.find(a[i])==even.end())
        remaining_digits++;
    }
    if(!flag)
    {
        int last=even.size();
        if(!remaining_digits)
        cout<<"Answer:\t"<<!flag<<endl;
        else
        {
            int h=n-1;
            int t=n-2;
            cout<<"Answer:\t"<<last*h*t<<endl;
        }
    }
    else
    {
        int last=even.size()-1;
        int h=n-1;
        int t=n-2;
        cout<<"Answer:\t"<<last*h*t<<endl;
    }

    return 0;
}
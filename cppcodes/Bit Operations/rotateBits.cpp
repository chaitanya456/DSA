#include<bits/stdc++.h>
using namespace std;
int leftRotate(int a ,int k,int y);
int rightRotate(int a ,int k,int y);
int main()
{
    int sizee=16;
    int a=28;
    int k=2;
    int m=leftRotate(a,k,sizee);
    int l=rightRotate(a,k,sizee);
    cout<<"After left rotation:\t"<<m<<endl;
    cout<<"After right rotation:\t"<<l<<endl;
    return 0;
}
int leftRotate(int a ,int k,int y)
{
    return (a<<k)| (a>>(y-k));
}
int rightRotate(int a ,int k,int y)
{
    return (a>>k)| (a<<(y-k));
}
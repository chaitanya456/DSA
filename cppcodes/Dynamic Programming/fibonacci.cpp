#include<bits/stdc++.h>
using namespace std;
int fib(int n);
int main()
{
    int n;
    cout<<"Enter number:\t";
    cin>>n;
    cout<<"Fibonacci is:"<<fib(n);
    return 0;
}
int fib(int n)
{
    int T[n+1];
    T[0]=0,T[1]=1;
    int i;
    for(i=2;i<=n;i++)
    T[i]=T[i-1]+T[i-2];
    return T[n];
}
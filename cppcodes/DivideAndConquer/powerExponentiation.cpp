#include<bits/stdc++.h>
using namespace std;
int calculatePower(int x,int y);
int main()
{
    int x=2,y=7;
    cout<<"Power:\t"<<calculatePower(x,y);
    return 0;
}
int calculatePower(int x,int y)
{
    if(y==1)
    return x;
    int temp=calculatePower(x,y/2);
    if(y%2!=0)
    return x*temp*temp;
    else 
    return temp*temp;
}
#include<bits/stdc++.h>
using namespace std;
void func(int n);
int main()
{
    int n;
    cout<<"Enter:\t";
    cin>>n;
    func(n);
    return 0;
}
void func(int n)
{
    int i,j,sp;
    for(i=1;i<=n;i++)
    {
        for(sp=n-i;sp>=1;sp--)
        cout<<" ";
        for(j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    for(i=1;i<=n;i++)
    {
        for(sp=1;sp<=i;sp++)
        cout<<" ";
        for(j=n-i;j>=1;j--)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
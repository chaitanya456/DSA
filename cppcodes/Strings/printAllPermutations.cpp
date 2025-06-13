#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="abc";
    string x=s;
    cout<<"Permuations:\n";
    do
    {
        next_permutation(x.begin(),x.end());
        cout<<x<<endl;
    } while (x!=s);
    
    return 0;
}
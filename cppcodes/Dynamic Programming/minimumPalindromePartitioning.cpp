#include<bits/stdc++.h>
using namespace std;
void func(string &s, int n);
int main()
{
    string s="abcbd";
    int n=s.length();
    func(s,n);
    return 0;
}
void func(string &s, int n)
{
    vector<vector<bool>> isPalindrome(n,vector<bool>(n,0));
    vector<vector<int>> T(n,vector<int>(n,0));
    int i,len,j;
    for(i=0;i<n;i++)
    T[i][i]=0, isPalindrome[i][i]=true;
    for(len=2;len<=n;len++)
    {
        for(i=0;i<=n-len;i++)
        {
            j=i+len-1;
            if(len==2) isPalindrome[i][j]=(s[i]==s[j]); 
            if(s[i]==s[j] && isPalindrome[i+1][j-1])
            isPalindrome[i][j]=true;
            if(isPalindrome[i][j])
            T[i][j]=0;
            else
            {
                T[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                T[i][j]=min(T[i][j],1+T[i][k]+T[k+1][j]);
            }
        }
    }
    // cout<<"Printing isPalindromeArray:\n";
    // for(auto x: isPalindrome)
    // {
    //     for(auto y: x)
    //     cout<<y<<" ";
    //     cout<<endl;
    // }
    cout<<"Minimum Palindromic partitions:\t"<<T[0][n-1];
}

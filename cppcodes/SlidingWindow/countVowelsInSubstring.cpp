#include<bits/stdc++.h>
using namespace std;
int func(string a, int n, int k);
bool isVowel(char x);
int main()
{
    string a="chaitaieouanya";
    int k=5;
    cout<<"Maximum Number of Vowels in a Substring of Length K:\t"<<func(a,a.size(),k);
    return 0;
}
int func(string a, int n, int k)
{
    int i;
    int c=0;
    for(i=0;i<k;i++)
    {
        if(isVowel(a[i]))
        c++;
    }
    int total=c;
    for(i=1;i<n-k;i++)
    {
        if(isVowel(a[i-1]))
        c--;
        if(isVowel(a[i+k-1]))
        c++;
        total=max(c,total);
    }
    return total;
}
bool isVowel(char x)
{
    if(x=='a' || x=='e'|| x=='i' || x=='o' || x=='u')
    return 1;
    return 0;
}
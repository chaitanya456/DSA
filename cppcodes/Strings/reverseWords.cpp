#include<bits/stdc++.h>
using namespace std;
void func(string s, int n);
int main()
{
    string x="I love C++ Programming";
    int n=x.length();
    func(x,n);
    return 0;
}
void func(string s, int n)
{
    vector<string>words;
    stringstream ss(s);
    string word;
    while(getline(ss,word,' '))
    words.push_back(word);
    reverse(words.begin(),words.end());
    string res="";
    for(auto x: words)
    res+=x+' ';
    cout<<"Reversing words:\t"<<res;
}
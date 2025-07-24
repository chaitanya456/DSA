#include<boost/algorithm/string/replace.hpp>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a="This is Chaithanya. How are you Chaithanya?";
    int n=a.size();
    cout<<"Normal String:\t"<<a<<endl;
    string sub="Krishna";
    // replace(a.begin(),a.end(),'C','b');
    boost::replace_all(a,"Chaithanya",sub);
    cout<<"Transformed String:\t"<<a<<endl;
    return 0;
}
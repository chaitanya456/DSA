#include<bits/stdc++.h>
using namespace std;
class SortedStream
{
    private:
    multiset<int>stream;
    public:
    void insert(int x)
    {
        stream.insert(x);
    }
    void peekStream()
    {
        cout<<endl;
        for(auto x: stream)
        cout<<x<<" ";
    }
};

int main()
{
    SortedStream ss;
    ss.insert(3);
    ss.insert(1);
    ss.insert(2);
    ss.peekStream();
    ss.insert(-2);
    ss.peekStream();
    return 0;
}
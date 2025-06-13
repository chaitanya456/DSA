#include<bits/stdc++.h>
using namespace std;
class base
{
    public:
    virtual void print() // virtual function used for function overrriding
    {
        cout<<"This is base Class";
    }
    void disp()
    {
        cout<<"Hi this is Display";
    }
};
class derived:public base
{
   void print()
   {
        cout<<"This is derived Class";
   }
};
int main()
{
    base *b;
    derived d;
    b=&d;
    b->print(); 
    return 0;
}
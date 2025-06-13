#include<bits/stdc++.h>
using namespace std;
class base1
{
    public:
    virtual void print() // virtual function used for function overrriding
    {
        cout<<"This is base Class 1";
    }
    void disp()
    {
        cout<<"Hi this is Display 1";
    }
};

class base2
{
    virtual void print()
    {
        cout<<"This is base Class 2";
    }
    virtual void disp()
    {
        cout<<"Hi this is Display 2";
    }
}; 

class derived:public base1, public base2
{
   void print()
   {
        cout<<"This is derived Class";
   }
};

int main()
{
    base1 *b1;
    base2 *b2;
    derived d;
    b1=&d;
    b2=&d;
    b1->print(); 
    b2->print();
    return 0;
}
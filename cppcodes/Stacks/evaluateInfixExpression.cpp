#include<bits/stdc++.h>
using namespace std;
void evaluate(string a, int n);
int applyOp(char x, int b, int a);
int main()
{
    // string a="10+2*3";
    string a="(10+2)*3";
    evaluate(a,a.size());
    return 0;
}
void evaluate(string a, int n)
{
    stack<int> val;
    stack<int> ops;
    int i;
    for(i=0;i<n;i++)
    {
        char token=a[i];
        if(token=='(')
        ops.push(token);
        else if(token==')')
        {
            while(!ops.empty() && ops.top()!='(')
            {
                char x=ops.top();
                ops.pop();
                int v1=val.top();
                val.pop();
                int v2=val.top();
                val.pop();
                val.push(applyOp(x,v1,v2));
            }
            ops.pop();
        }
        else if(isdigit(a[i]))
        {
            int v=0;
            while(i<n && isdigit(a[i]))
            {
                v=v*10+a[i]-'0';
                i++;
            }
            val.push(v);
            i--;
        }
        else
        ops.push(a[i]);
    }
    while(!ops.empty())
    {
        char x=ops.top();
        ops.pop();
        int v1=val.top();
        val.pop();
        int v2=val.top();
        val.pop();
        val.push(applyOp(x,v1,v2));
    }
    cout<<"After Evaluating "<<a<<" we get:\t"<<val.top()<<endl;
}
int applyOp(char x, int b, int a)
{
    if(x=='+')
    return a+b;
    else if(x=='-')
    return a-b;
    else if(x=='*')
    return a*b;
    else if(x=='/')
    return a/b;
    return 0;
}
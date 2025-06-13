#include<bits/stdc++.h>
using namespace std;
void knapsack(vector<int>wt, vector<int>val, int cap);
int main()
{
    int capacity=10;
    vector<int>wt={6,3,4,2};
    vector<int>val={30,14,16,9};
    knapsack(wt,val,capacity);
    return 0;
}
void knapsack(vector<int>wt, vector<int>val, int cap)
{
    int n=wt.size();
    int T[n+1][cap+1];
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cap;j++)
        {
            T[i][j]=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=cap;j++)
        {
            if(j<wt[i-1])
            T[i][j]=T[i-1][j];
            else
            {
                T[i][j]=max(T[i-1][j],val[i-1]+T[i-1][j-wt[i-1]]);
            }
        }
    }
    cout<<"\nKnapsack Matrix:\n";
    cout<<"---------------------\n";
    for(i=0;i<=n;i++)
    {
        cout<<endl;
        for(j=0;j<=cap;j++)
        {
            cout<<T[i][j]<<" ";
        }
    }
    cout<<"\n\n";
    cout<<"Maximum value from 0/1 knapsack:\t"<<T[n][cap];
}

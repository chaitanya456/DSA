#include<bits/stdc++.h>
using namespace std;
int eggDropping(int eggs,int floors);
int main()
{
    int eggs=2,floors=6;
    cout<<"Maximum Number of Attempts:\t"<<eggDropping(eggs,floors);
    return 0;
}
int eggDropping(int eggs,int floors)
{
    vector<vector<int>> T(eggs+1,vector<int>(floors+1));
    int i,j;
    for(i=0;i<=floors;i++)
    T[1][i]=i;
    for(i=2;i<=eggs;i++)
    {
        for(j=1;j<=floors;j++)
        {
            if(i>j)
            T[i][j]=T[i-1][j];
            else
            {
                T[i][j]=INT_MAX;
                int temp;
                for(int k=1;k<=j;k++)
                {
                    temp=1+max(T[i-1][k-1],T[i][j-k]);
                    if(temp<T[i][j])
                    T[i][j]=temp;
                }
            }
        }
    }
    // for(auto x: T)
    // {
    //     for(auto y: x)
    //     cout<<y<<" ";
    //     cout<<endl;
    // }
    return T[eggs][floors];
}
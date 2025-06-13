#include<bits/stdc++.h>
using namespace std;
void func(int k, int r, int c);
int main()
{
    int k=2,r=2,c=1;
    func(k,r,c);
    return 0;
}
void func(int k, int r, int c)
{
    int i,j;
    vector<vector<double>> T(r, vector<double>(r,0.0));
    T[0][0]=k;
    for(i=0;i<r-1;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(T[i][j]>1.0)
            {
                double spare=(k-1.0);
                T[i][j]=1.0;
                T[i][j+1]+=spare/2.0;
                T[i+1][j]+=spare/2.0;
            }
        }
    }
    cout<<"Amount of Water at "<<r<<","<<c<<" Position is:\t"<<T[r-1][c-1]<<endl;
}
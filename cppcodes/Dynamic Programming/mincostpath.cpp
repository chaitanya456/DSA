#include<bits/stdc++.h>
using namespace std;
void minCostPath(int T[][3]);
int main()
{
    int T[3][3]={{1,2,3},{4,8,2},{1,5,3}};
    minCostPath(T);
    return 0;
}
void minCostPath(int T[][3])
{
    int K[3][3];
    int i,j;
    K[0][0]=T[0][0];
    for(i=1;i<3;i++)//replace 3 with Row number
    K[0][i]=T[0][i]+K[0][i-1];
    for(i=1;i<3;i++)//replace 3 with Column number
    K[i][0]=T[i][0]+K[i-1][0];
    for(i=1;i<3;i++)
    {
       for(j=1;j<3;j++)
       {
            K[i][j]=T[i][j]+min(K[i-1][j],min(K[i][j-1],K[i-1][j-1]));
       }
    }
    for(i=0;i<3;i++)
    {
        cout<<endl;
        for(j=0;j<3;j++)
        cout<<K[i][j]<<" ";
    }
    cout<<endl<<"Minimum Cost:\t"<<K[2][2];
}
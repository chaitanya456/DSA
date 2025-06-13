#include<bits/stdc++.h>
using namespace std;
class Graph
{
    vector<vector<int> >adjMatrix;
public:
    Graph(int n)
    {
        adjMatrix=vector<vector<int>>(n,vector<int>(n,0));
    }
    void add(int u,int v)
    {
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
    }
    void printMatrix()
    {
        int i,j;
        int n=adjMatrix.size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            cout<<adjMatrix[i][j]<<" ";
            cout<<endl;
        }
    }

};
int main()
{
    Graph g(3);
    g.add(0,1);
    g.add(0,2);
    g.add(1,2);
    g.printMatrix();
    return 0;
}
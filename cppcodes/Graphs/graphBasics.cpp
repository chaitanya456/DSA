#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
	int n;
	unordered_map<int,list<int> >m;
	Graph(int n)
	{
		this->n=n;
		list<int> *adj=new list<int>[n];
	}
	void addEdge(int u,int v)
	{
		m[u].push_back(v);
		m[v].push_back(u);
	}
	void print()
	{
		for (auto x: m)
		{
			cout<<x.first<<"->";
			x.second.sort();
			for(auto y: x.second)
				cout<<y<<"->";
			cout<<endl;
		}
	}
	void DFS(int start, vector<bool>& vis)
	{
	    vis[start]=1;
	    cout<<start<<' ';
	    for(auto x: m[start])
	    {
	        if(!vis[x])
	        DFS(x,vis);
	    }
	}
	void topologicalSort()
	{
	    
	}
};

int main()
{
	Graph g(5);
	g.addEdge(4,0);
	g.addEdge(5,0);
	g.addEdge(5,2);
	g.addEdge(4,1);
	g.addEdge(2,3);
	g.addEdge(3,1);
	cout<<"Adjacency List:\n";
	g.print();
	vector<bool> vis(5);
	g.DFS(5,vis);
	g.topologicalSort();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Graph{
	
	int V;
	list<int> *adj;
	bool *visited;
	dfsUtil(int s, bool visited[])
	{
		cout<<s<<" ";
		visited[s] = true;
		for(auto it : adj[s])
		{
			if(!visited[it])
			{
				dfsUtil(it,visited);
			}
		}
	}
	
	public:
		Graph(int V)
		{
			this->V = V;
			adj = new list<int>[V];
			visited = new bool[V];
		}
		void addEdge(int u, int v)
		{
			adj[u].push_back(v);
		}
		void dfs()
		{
			for(int i=0;i<V;i++)
				visited[i] = false;
			for(int i=0;i<V;i++)
			{
				if(visited[i] == false)
				{
					dfsUtil(i,visited);
				}
			}
		}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int v,e;
		cin>>v>>e;
		Graph graph(v);
		for(int i=0;i<e;i++)
		{
			int u,v;
			cin>>u>>v;
			graph.addEdge(u,v);
		}
		graph.dfs();
	}
	return 0;
}

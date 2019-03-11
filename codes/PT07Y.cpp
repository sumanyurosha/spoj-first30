#include<iostream>
#include<list>
using namespace std;
class Graph{
	
	int V;
	list<int> *adj;
	bool isCyclic(int s, bool visited[], int parent)
	{
		visited[s] = true;
		
		for(auto i : adj[s])
		{
			if(!visited[i])
			{
				if(isCyclic(i,visited,s))
					return true;
			}
			else if(i != parent)
				return true;
		}
		return false;
	}
	public:
		Graph(int V)
		{
			this->V = V;
			adj = new list<int>[V];
		}
		void addEdge(int u, int v)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bool dfs()
		{
			bool *visited = new bool[V];
			for(int i=0;i<V;i++)
				visited[i] = false;
			
			//checking for a cycle in graph	
			for(int i=0;i<V;i++)
			{
				if(!visited[i])
				{
					if(isCyclic(i,visited,-1))
					{
						return true;
					}
				}
			}
			
			//checking for a disconnected node in graph
			for(int i=0;i<V;i++)
			{
				if(!visited[i])
					return true;
			}
			
			return false;
		}	
};
int main()
{
	int m,n;
	cin>>n>>m;
	Graph graph(n);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph.addEdge(--u,--v);
	}
	graph.dfs()?cout<<"NO":cout<<"YES";
	return 0;
}

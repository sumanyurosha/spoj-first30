#include<iostream>
#include<list>
using namespace std;
class Graph{
	
	int V;
	list<int> *adj;
	int countEdges(int s, bool visited[], int parent)
	{
		visited[s] = true;
		int maxLength = 0;
		for(auto x : adj[s])
		{
			
			if(!visited[x] && x!=parent)
			{
				//cout<<x+1<<" ";
				maxLength = max(countEdges(x,visited,s) + 1, maxLength);
			}
		}
		return maxLength;
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
		int bfs(int s, int parent)
		{
			bool *visited = new bool[V];
			for(int i=0;i<V;i++)
				visited[i] = false;
			int maxLength = 0;
			for(auto x : adj[s])
			{
				if(!visited[x])
				{
					//cout<<x+1<<" ";
					maxLength = max(countEdges(x,visited,s) + 1, maxLength);
				}
			}
			return maxLength;
		}
};
int main()
{
	int n;
	cin>>n;
	Graph graph(n);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		graph.addEdge(--u,--v);
	}
	int maxLength = 0;
	for(int i=0;i<n;i++)
	{
		//cout<<"for i = "<<i+1<<"\n"<<"nodes visited : "<<i+1<<" ";
		int x = graph.bfs(i,-1);
		//cout<<"\nlength = "<<x;
		maxLength = max(x,maxLength);
		//cout<<"\n";
	}
	cout<<maxLength;
}
/*
9
1 2
1 3
1 4
2 5
5 8
4 6
4 7
7 9
*/

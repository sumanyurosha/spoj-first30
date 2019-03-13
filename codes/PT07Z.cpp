#include<iostream>
#include<list>
#include<algorithm>
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
		int dfs()
		{
			bool *visited = new bool[V];
			for(int i=0;i<V;i++)
				visited[i] = false;
			int s = 0;
			for(int i=0;i<V;i++)
			{
			    if(adj[i].size()>1)
			    {
			        s = i;
			        break;
			    }
			}
			
			int *length = new int[adj[s].size()];
			int maxLength = 0;
			int index = 0;
			for(auto x : adj[s])
			{
				if(!visited[x])
				{
					//cout<<x+1<<" ";
					//maxLength = max(countEdges(x,visited,s) + 1, maxLength);
					length[index++] = countEdges(x,visited,s) + 1;
				}
			}
			sort(length,length+index);
			cout<< length[index-1]+length[index-2];
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
	graph.dfs();
	return 0;
}

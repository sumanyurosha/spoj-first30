#include<bits/stdc++.h>
using namespace std;
class Graph{
	
	int V;
	list<int> *adj;
	
	public:
		Graph(int V)
		{
			this->V = V;
			adj = new list<int>[V];
		}
		void addEdge(int u, int v)
		{
			adj[u].push_back(v);
		}
		void BFS(int start)
		{
			//initialise the visited array
			bool *visited = new bool[V];
			for(int i=0;i<V;i++)
				visited[i] = false;
			
			//using a queue for traversal	
			list<int> queue;
			queue.push_back(start);
			visited[start] = true;
			
			while(!queue.empty())
			{
				//poping out the front element
				start = queue.front();
				cout<<start<<" ";
				queue.pop_front();
				
				//traversing the adjacent nodes of a node
				for(auto it = adj[start].begin(); it != adj[start].end();it++)
				{
					//pushing the unvisited nodes
					if(!visited[*it])
					{
						queue.push_back(*it);
						visited[*it] = true;
					}
				}
			}
		}
	
};
int main()
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
	graph.BFS(1);
	return 0;
}

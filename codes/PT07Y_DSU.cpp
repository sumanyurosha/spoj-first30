#include<iostream>
using namespace std;
struct Edge{
	int src;
	int dest;
};
class Graph{
	
	int V;
	int E;
	struct Edge *edges;
	
	public:
		Graph(int V, int E)
		{
			this->V = V;
			this->E = E;
			edges = (struct Edge*) malloc( this->E * sizeof( struct Edge ));
		}
		void addEdge(int i,int u,int v)
		{
			edges[i].src = u;
			edges[i].dest = v;
		}
		int find(int parent[], int i)
		{
			if(parent[i] == -1)
				return i;
			find(parent, parent[i]);
		}
		void unionSet(int parent[], int x, int y)
		{
			int xset = find(parent, x);
			int yset = find(parent, y);
			if(xset != yset)
				parent[xset] = yset;
		}
		bool isCyclic()
		{
			int *parent = new int[V];
			for(int i=0;i<V;i++)
				parent[i] = -1;
			
			for(int i=0;i<E;i++)
			{
				int x = find(parent,edges[i].src);
				int y = find(parent,edges[i].dest); 
				if(x != y)
					unionSet(parent,x,y);
				else
					return true;
			}
			return false;
		}
};
int main()
{
	int n,m;
	cin>>n>>m;
	Graph graph(n,m);
	if(m==n-1)
	{
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			graph.addEdge(i,--u,--v);
		}
		graph.isCyclic()?cout<<"NO":cout<<"YES";
	}
	else
		cout<<"NO";
	
	return 0;
}


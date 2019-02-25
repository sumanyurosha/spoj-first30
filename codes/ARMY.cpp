#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int maxG = 0, maxM = 0,x;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			maxG = max(maxG,x);
		}
		for(int i=0;i<m;i++)
		{
			cin>>x;
			maxM = max(maxM,x);
		}
		if(maxG>=maxM)
			cout<<"Godzilla\n";
		else
			cout<<"MechaGodzilla\n";
	}
	return 0;
}

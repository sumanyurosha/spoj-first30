#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=n;;i++)
		{
			long long x = i*i*i;
			if((x)%1000 == 888)
			{
				cout<<i<<"\n";
				break;
			}
		}
	}
}

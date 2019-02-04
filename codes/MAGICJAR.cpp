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
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			ans = max(ans,x);
		}
		cout<<ans<<endl;
	}
	return 0;
}

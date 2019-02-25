#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int n = 1;
	while(t--)
	{
		int borrow, friends;
		cin>>borrow>>friends;
		int stamps[friends];
		for(int i=0;i<friends;i++)
		{
			cin>>stamps[i];
		}
		sort(stamps,stamps+friends, greater<int>());
		int sum = 0;
		bool flag = false;
		int ans;
		for(int i=0;i<friends;i++)
		{
			sum += stamps[i];
			if(sum>=borrow)
			{
				flag = true;
				ans = i+1;
				break;
			}
		}
		cout<<"Scenario #"<<n++<<":\n";
		if(flag)
			cout<<ans<<"\n\n";
		else
			cout<<"impossible\n";
	}
	return 0;
}

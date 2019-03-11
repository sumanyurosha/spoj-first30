#include<iostream>
#include<set>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	set<int> myset;
	int res = 0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		res = res ^ x;
		cout<<res<<"\n";
	}
	cout<<res;
	return 0;
}

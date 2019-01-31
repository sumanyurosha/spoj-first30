#include <bits/stdc++.h>
using namespace std;
long long max(long long a,long long b)
{
	if(a>b)
		return a;
	return b;
}
int main() {
	int n;
	vector<long long> dp;
	dp.push_back(0);
	for(int i=1;i<=1e9;i++)
	{
		dp.push_back(max(i,dp[i/2]+dp[i/3]+dp[i/4]));
	}
	while(scanf("%d",&n))
	{
		cout<<max(n,dp[n/2]+dp[n/3]+dp[n/4])<<"\n";
	}
	return 0;
}

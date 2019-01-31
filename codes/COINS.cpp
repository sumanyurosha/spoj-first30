#include <bits/stdc++.h>
using namespace std;
vector<long long> dp;
long long max(long long a,long long b)
{
	if(a>b)
		return a;
	return b;
}
void start()
{
	dp.push_back(0);
	for(int i=1;i<=1e8;i++)
	{
		dp.push_back(max(i,dp[i/2]+dp[i/3]+dp[i/4]));
	}
}
long long function(long long n)
{
	if(n<100000000)
		return max(n,dp[n/2] + dp[n/3] + dp[n/4]);
	else
		return max(n,function(n/2) + function(n/3) + function(n/4));
}
int main() {
	int n;
	start();
	while(scanf("%d",&n)!= EOF)
	{
		
		cout<<function(n)<<"\n";
	}
	return 0;
}

#include<iostream>
#define MOD 1000007
using namespace std;
int dp[1000001]={0};
void compute()
{
	for(int i=1;i<1000001;i++)
	{
		dp[i] = (2*i)%MOD + dp[i-1] + (i-1)%MOD;
		dp[i] %= MOD;
	}
}
int main()
{
	int t;
	cin>>t;
	compute();
	while(t--)
	{
		int n;
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	while(true)
	{
		string s;
		cin>>s;
		int n = s.size();
		if(n==1 && s[0]=='0')
			break;
		long long dp[n+1];
		dp[0] = 1;
		dp[1] = 1;
		int prev = s[0] - '0';
		for(int i=1;i<n;i++)
		{
			if(s[i] == '0')
				dp[i+1] = dp[i-1];
			else if(prev*10 + s[i]-'0'>26 || prev == 0)
				dp[i+1] = dp[i];
			else
				dp[i+1] = dp[i] + dp[i-1];
			prev = s[i] - '0';
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}

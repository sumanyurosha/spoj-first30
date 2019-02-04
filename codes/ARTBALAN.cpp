#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int charValues[27] = {0};
		for(int i=0;i<s.size();i++)
		{
			charValues[s[i] - 'A']++;
		}
		sort(charValues,charValues+27,greater<int>());
		int uniqueEnteries = 0;
		for(int i=0;i<27;i++)
		{
			if(charValues[i]>0)
				uniqueEnteries++;
		}
		set<int> factors;
		int n = s.size();
		for(int i=1;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				factors.insert(i);
				factors.insert(n/i);
			}
			if(i==26)
				break;
		}
		int moves = INT_MAX;
//		cout<<n<<endl;
//		for(auto it = factors.begin();it!=factors.end();it++)
//			cout<<*it<<" ";
//		cout<<"\n";
//		cout<<uniqueEnteries<<endl;
//		if(factors.size() == 2)
//		{
//			moves = n-charValues[0];
//		}
//		else
		{
			for(auto it = factors.begin();it!=factors.end();it++)
			{
				int x = *it;
				int sum = 0;
				if(x>uniqueEnteries)
				{
					sum = n - uniqueEnteries;
				}
				else
				{
					for(int i=0;i<x;i++)
					{
						sum += abs(n/x - charValues[i]);
					}
				}
//				cout<<sum<<" ";
				moves = min(moves,sum);
			}
		}
//		cout<<endl;
		cout<<moves<<"\n";
	}
	return 0;
}

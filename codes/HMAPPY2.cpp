#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		long long n,a,b,k;
		cin>>n>>a>>b>>k;
		long long ans = n/a + n/b - 2*(n/((a*b)/__gcd(a,b)));
		if(ans>=k)
			cout<<"Win\n";
		else
			cout<<"Lose\n";
	}
	return 0;
}

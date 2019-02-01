#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int x = 0;
	int ans = 0;
	for(int i=1;i<=sqrt(n);i++)
	{
		ans += n/i - x;
		x++;
	}
	cout<<ans;
}

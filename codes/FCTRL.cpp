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
		int zeros = 0;
		int power = 5;
		int div = n/power;
		while(div)
		{
			zeros += div;
			power *= 5;
			div = n/power;
		}
		cout<<zeros<<endl;
	}
	return 0;
}

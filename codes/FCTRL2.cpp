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
		int factorial[100000];
		for(int i=0;i<100000;i++)
			factorial[i] = -1;
		factorial[0] = 1;
		int index = 0;
		for(int number = 1;number <= n; number++)
		{
			int temp = number,carry = 0;
			for(int i=0;factorial[i]>=0;i++)
			{
				factorial[i] = factorial[i]*temp + carry;
				carry = factorial[i]/10;
				factorial[i] = factorial[i]%10;
				index = i;
			}
			while(carry>0)
			{
				factorial[++index] = carry%10;
				carry = carry/10;
			}
		}
		for(int i = index;i>=0;i--)
			cout<<factorial[i];
		cout<<"\n";
	}
	return 0;
}

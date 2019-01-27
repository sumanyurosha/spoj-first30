#include<iostream>
using namespace std;
bool primes[1000005];
void sieve()
{
	for(int i=0;i<1000005;i++)
		primes[i] = true;
	primes[0] = false;
	primes[1] = false;
	for(int i=2;i*i<1000005;i++)
	{
		if(primes[i]==true)
		{
			for(int j=i*i;j<1000005;j+=i)
				primes[j] = false;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	sieve();
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		bool prime_array[m-n+1];
		for(int i=0;i<m-n+1;i++)
			prime_array[i] = true;
		if(n==1)
			prime_array[0] = false;
		for(int i=2;i*i<m;i++)
		{
			if(primes[i] == true)
			{
				int starting_point = (n/i)*i;
				if(starting_point < n)
					starting_point += i;
				for(int j = starting_point;j<=m;j+=i)
				{
					prime_array[j-n] = false;
				}
				if(starting_point == i)
					prime_array[starting_point-n] = true;
			}
		}
		for(int i=0;i<m-n+1;i++)
		{
			if(prime_array[i] == true)
				cout<<i+n<<endl;
		}
		cout<<endl;
	}
	return 0;
}

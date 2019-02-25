#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ios::sync_with_stdio(false);
		long long p,q,r;
		cin>>p>>q>>r;
		long long a,d,n;
		if(p+q==0)
		{
			n = 7;
			a = 0;
			d = 0;
		}
		else
		{
			n = 2*r/(p+q);
			d = (q-p)/(n-5);
			a = p - 2*d;
		}
		cout<<n<<"\n";
		for(int i=0;i<n;i++)
		{
			cout<<(long long)a+(long long)i*d<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

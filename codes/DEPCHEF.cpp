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
		int a[n],d[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>d[i];
		int value = -1;
		if(d[0]>a[1]+a[n-1])
			value = max(value,d[0]);
		for(int i=1;i<n-1;i++)
		{
			if(d[i]>a[i-1]+a[i+1])
				value = max(value,d[i]);
		}
		if(d[n-1]>a[n-2]+a[0])
			value = max(value,d[n-1]);
		cout<<value<<"\n";
	}
	return 0;
}

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		a = a%10;
		if(b==0)
		{
			cout<<"1\n";
		}
		else
		{
			if(a==0 || a==1 || a==5 || a==6)
			cout<<a<<"\n";
		else if(a==2 || a==3 || a==7 || a==8)
		{
			b %= 4;
			if(b==0)
				b = 4;
			int x = pow(a,b);
			cout<<x%10<<"\n";
		}
		else if(a==4 || a==9)
		{
			b %= 2;
			if(b==0)
				b = 2;
			int x = pow(a,b);
			cout<<x%10<<"\n";
		}
		}
		
	}
	return 0;
}

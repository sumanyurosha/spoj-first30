#include<iostream>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	bool flag = false;
	while(n>1)
	{
		if(n%2==0)
			n= n/2;
		else
		{
			flag = true;
			break;
		}
	}
	if(flag)
		cout<<"NIE\n";
	else
		cout<<"TAK\n";
	return 0;
}

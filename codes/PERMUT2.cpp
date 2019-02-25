#include<iostream>
using namespace std;
int main()
{
	while(true)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		int permut[n],invpermut[n];
		for(int i=0;i<n;i++)
		{
			cin>>permut[i];
		}
		for(int i=0;i<n;i++)
		{
			invpermut[permut[i]-1] = i+1;
		}
		bool flag = true;
		for(int i=0;i<n;i++)
		{
			if(permut[i]!=invpermut[i])
			{
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<"ambiguous\n";
		else
			cout<<"not ambiguous\n";
	}
	return 0;
}

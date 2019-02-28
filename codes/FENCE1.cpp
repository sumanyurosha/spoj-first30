#include<bits/stdc++.h>
using namespace std;
int main()
{
	while(true)
	{
		int l;
		cin>>l;
		if(l==0)
			break;
		double pi = 3.14159;
		double area = ((l*l)/pi);
		area = area/2;
		printf("%.2f\n",area);
	}
	return 0;
}

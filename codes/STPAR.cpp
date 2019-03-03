#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	while(true)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		vector<int> trucks;
		stack<int> street;
		int x;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			trucks.push_back(x);
		}
		int c = 1;
		for(auto it=trucks.begin();it!=trucks.end();it++)
		{
			if(*it>c)
				street.push(*it);
			else if(*it==c)
			{
				c++;
			}
			while(!street.empty())
			{
				if(c==street.top())
				{
					street.pop();
					c++;
				}
				else
					break;
			}
		}
		
		if(c==n+1)
			cout<<"yes\n";
		else
			cout<<"no\n";	
	}
	return 0;
}

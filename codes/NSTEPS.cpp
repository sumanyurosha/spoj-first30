#include<iostream>
using namespace std;
bool odd(int x)
{
	if(x%2!=0)
		return true;
	return false;
}
bool even(int x)
{
	if(x%2==0)
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		if(odd(x) && odd(y) && x==y)
			cout<<2*x-1<<"\n";
		else if(even(x) && even(y) && x-y==2)
			cout<<x+y<<"\n";
		else if(odd(x) && odd(y) && x-y==2)
			cout<<x+y-1<<"\n";
		else if(even(x) && even(y) && x==y)
			cout<<x+y<<"\n";
		else
			cout<<"No Number\n";
	}
	return 0;
}

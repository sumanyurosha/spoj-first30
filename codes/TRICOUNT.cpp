#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long ans = n*(n+2);
		ans = ans*(2*n+1);
		ans /= 8;
		cout<<ans<<"\n";
	}
	return 0;
}

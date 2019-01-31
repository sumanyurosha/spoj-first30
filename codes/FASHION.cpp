#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	
	// your code here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int men[n],women[n];
		for(int i=0;i<n;i++)
			cin>>men[i];
		for(int i=0;i<n;i++)
			cin>>women[i];
		sort(men,men+n);
		sort(women,women+n);
		int hotness = 0;
		for(int i=0;i<n;i++)
			hotness+=men[i]*women[i];
		cout<<hotness<<"\n";
	}
	return 0;
}

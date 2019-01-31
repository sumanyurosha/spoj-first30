#include <iostream>
using namespace std;

int main() {
	
	// your code here
	int a,b,c;
	while(true)
	{
		cin>>a>>b>>c;
		if(a==0 && b==0 && c==0)
			break;
		if(b-a == c-b)
			cout<<"AP "<<b-a + c<<"\n";
		else
			cout<<"GP "<<c*(b/a)<<"\n";
	}
	

	return 0;
}

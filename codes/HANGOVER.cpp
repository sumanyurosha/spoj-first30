#include<iostream>
using namespace std;
int main()
{
	while(true)
	{
		float c;
		cin>>c;
		if(c==0.00)
			break;
		int n = 1;
		float sum = (float)1/(n+1);
		while(sum-c<0.00)
		{
			n++;
			sum += (float)1/(n+1);
		}
		cout<<n<<" card(s)"<<endl;
	}
	return 0;
}

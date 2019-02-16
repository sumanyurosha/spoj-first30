#include<iostream>
#define MAX 1000
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		getline (cin, str);
		while (str.length()==0 ) 
            getline(cin, str);
		int number[3] = {0};
		int plusPosition = 0, equalToPosition = 0, machulaPosition = 0;
		int index = 0;
		for(int i=0;i<str.size();i++)
		{
			if(str[i] == '+')
				plusPosition = i;
			if(str[i] == '=')
				equalToPosition = i;
			if(str[i] == 'm')
				machulaPosition = i;
			if(str[i]>= '0' && str[i]<='9')
			{
				number[index] = number[index]*10 + str[i] - '0';
			}
			if(str[i] == ' ' && str[i+2] == ' ' )
				index++;
		}
		if(machulaPosition < plusPosition)
		{
			number[0] = number[2] - number[1];
		}
		else if(machulaPosition < equalToPosition && machulaPosition > plusPosition)
		{
			number[1] = number[2] - number[0];
		}
		else if(machulaPosition > equalToPosition)
		{
			number[2] = number[0] + number[1];
		}
		cout<<number[0]<<" + "<<number[1]<<" = "<<number[2]<<"\n";
	}
	return 0;
}

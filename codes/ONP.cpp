#include<iostream>
#include<stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		stack<char> alpha, opr;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(')
			{
				opr.push(s[i]);
			}
			else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
			{
				opr.push(s[i]);
			}
			else if(s[i]==')')
			{
				while(true)
				{
					if(opr.top()!='(')
					{
						cout<<opr.top();
						opr.pop();
					}
					else if(opr.top()=='(')
					{
						opr.pop();
						break;
					}
				}
			}
			else
			{
				cout<<s[i];
			}
		}
		cout<<"\n";
	}
	return 0;
}

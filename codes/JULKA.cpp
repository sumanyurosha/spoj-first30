#include<iostream>
using namespace std;
string* add(string a, string b)
{
	int index = a.size();
	char answer[index+1];
	string modifiedB;
	for(int i=0;i<a.size()-b.size();i++)
		modifiedB.append((char)0);
	modifiedB.append(b);
	
	int carry = 0;
	for(int i=a.size()-1;i>=0;i--)
	{
		int sum = carry + a[i] + modifiedB[i] - 96;
		answer[index--] = sum%10;
		carry = sum/10;
	}
	if(carry>0)
		answer[index] = carry;
	else 
		answer = answer.substr(1,a.size());
	return string(answer);
}
string subtract(string a, string b)
{
	string answer;
	return answer;
}
string divideBy2(string a)
{
	string answer;
	return answer;
}
int main()
{
	ios::sync_with_stdio(false);
	int t = 10;
	while(t--)
	{
		string sumOfApples, diffOfApples;
		cin>>sumOfApples>>diffOfApples;
		cout<<add(sumOfApples,diffOfApples);
		//cout<<divideBy2(add(sumOfApples,diffOfApples))<<endl;
		//cout<<divideBy2(subtract(sumOfApples,diffOfApples))<<endl;
	}
	return 0;
}

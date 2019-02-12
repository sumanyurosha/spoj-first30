#include<bits/stdc++.h>
using namespace std;
bool carryFlag = false;
int* add(int* a, int* b,int n)
{
	//step 1
	int answer[n+1];
	//step 2
	int carry = 0;
	//step 3
	for(int i=n-1;i>=0;i--)
	{
		int sum = a[i] + b[i] + carry;
		answer[i+1] = sum%10;
		carry = sum/10;
	}
	//step 4
	if(carry>0)
	{
		answer[0] = carry;
		carryFlag = true;
	}
	else
	{
		for(int i=0;i<n;i++)
			answer[i]=answer[i+1];
	}
	
	return answer;
}
char* subtract(string a, string b)
{
	string answer;
	//return null;
}
char* divideBy2(string a)
{
	string answer;
	//return null;
}
int main()
{
	ios::sync_with_stdio(false);
	int t = 10;
	while(t--)
	{
		char sumOfApples[102], diffOfApples[102];
		cin>>sumOfApples>>diffOfApples;
		int n = strlen(sumOfApples), m = strlen(diffOfApples);
		int a[n],b[n];
		
		carryFlag = false;
		//conversion from char array to int array
		for(int i=0;i<n;i++)
			a[i] = sumOfApples[i] - '0';
		for(int i=0;i<n-m;i++)
			b[i] = 0;
		for(int i=n-m;i<n;i++)
			b[i] = diffOfApples[i-(n-m)] - '0';
		int* answer = add(a,b,n);
		if(carryFlag == true)
			n++;
		for(int i=0;i<n;i++)
			cout<<answer[i]<<endl;
		cout<<endl;
		//cout<<divideBy2(add(sumOfApples,diffOfApples))<<endl;
		//cout<<divideBy2(subtract(sumOfApples,diffOfApples))<<endl;
	}
	return 0;
}

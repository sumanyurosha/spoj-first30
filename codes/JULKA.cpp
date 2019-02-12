#include<bits/stdc++.h>
using namespace std;
bool carryFlag = false;
int sizeOfAdditionArray = 0;
int sizeOfSubtractionArray = 0;
int sizeOfDivisionArray = 0;
int* add(int* a, int* b,int n)
{
	//step 1
	static int answer[105];
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
	sizeOfAdditionArray = n;
	if(carry>0)
	{
		answer[0] = carry;
		carryFlag = true;
		sizeOfAdditionArray++;
	}
	else
	{
	
		for(int i=0;i<n;i++)
			answer[i]=answer[i+1];
	}
	
	return answer;
}
int* subtract(int* a, int* b,int n)
{
	static int answer[105];
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]<b[i])
		{
			answer[i] = 10 + a[i] - b[i];
			a[i-1]--;
		}
		else
			answer[i] = a[i] - b[i];
	}
	int index = 0;
	for(int i=0;i<n;i++)
	{
		if(answer[i]!=0)
		{
			index = i;
			break;
		}
		if(answer[i] == 0 && i == n-1)
			index = i;
	}
	sizeOfSubtractionArray = n - index;
	if(index>0)
	{
		for(int i=0;i<n-index;i++)
		{
			answer[i] = answer[i+index];
		}
	}
	return answer;
}
int* divideBy2(int* a, int sizeOfArray)
{
	static int answer[101];
	int carry = 0;
	for(int i=0;i<sizeOfArray;i++)
	{
		int temp = carry*10 + a[i];
		answer[i] = temp/2;
		carry = temp%2;
	}
	
	int index = 0;
	for(int i=0;i<sizeOfArray;i++)
	{
		if(answer[i]!=0)
		{
			index = i;
			break;
		}
		if(answer[i] == 0 && i == sizeOfArray-1)
			index = i;
	}
	sizeOfDivisionArray = sizeOfArray - index;
	if(index>0)
	{
		for(int i=0;i<sizeOfArray-index;i++)
		{
			answer[i] = answer[i+index];
		}
	}
	return answer;
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
		int* additionArray = add(a,b,n);
//		for(int i=0;i<sizeOfAdditionArray;i++)
//			cout<<additionArray[i];
//		cout<<endl;
		int* subtractionArray= subtract(a,b,n);
//		for(int i=0;i<sizeOfSubtractionArray;i++)
//			cout<<subtractionArray[i];
//		cout<<endl;
		int* divisionArray = divideBy2(additionArray,sizeOfAdditionArray);
		for(int i=0;i<sizeOfDivisionArray;i++)
			cout<<divisionArray[i];
		cout<<endl;
		divisionArray = divideBy2(subtractionArray,sizeOfSubtractionArray);
		for(int i=0;i<sizeOfDivisionArray;i++)
			cout<<divisionArray[i];
		cout<<endl;
	}
	return 0;
}

#include<iostream>
using namespace std;
bool isPalindrome(int a[],int size) 
{ 
	bool flag = false;
	int b[size];
	int index = size-1;
	for(int i=0;i<size;i++)
	{
		b[index--] = a[i];
	}
	for(int i=0;i<size;i++)
	{
		if(a[i]!=b[i])
			return false;
	}
    return true; 
} 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int n = str.size();
		int a[n+1];
		for(int i=0;i<n;i++)
			a[i] = str[i] - '0';
			
		bool incFlag = false;
		int mid = n/2;
		int start = -1;
		
		//checking if the number is already a palindrome
		if(isPalindrome(a,n))
		{
			//cout<<"Palindrome\n";
			for(int i=n-1;i>=0;i--)
			{
				if(a[i]<9)
				{
					a[i]++;
					break;
				}
				a[i] = 0;
			}
//			cout<<"after incrementing: ";
//			for(int i=0;i<n;i++)
//				cout<<a[i];
//			cout<<endl;
//			cout<<"checking for 9,99,999 typo\n";
			//converting n digit 9,99,999 type array into n+1 digit 10,100,1000 type array
			if(a[0]==0)
			{
				n++;
				a[0] = 1;
				for(int i=1;i<n;i++)
					a[i] = 0;
			}
//			cout<<"The new number is: ";
//			for(int i=0;i<n;i++)
//				cout<<a[i]<<" ";
//			cout<<"\n";
		}
		
		if(n%2==0)
		{
//			cout<<"comparison block for even\n";
			mid--;
			n--;
			for(int i=1;i<=n;i+=2)
			{
				if(a[(n-i)/2]>a[(n+i)/2])
				{
					a[(n+i)/2] = a[(n-i)/2];
					start = (n+i)/2;
					break;
				}
				else if(a[(n-i)/2] == a[(n+i)/2])
					a[(n+i)/2] = a[(n-i)/2];
				else
				{
					start = mid;
					break;
				}
			}
//			cout<<"comparison block::start :"<<start<<"value: "<<a[start]<<"\n";
			n++;
		}
		else
		{
//			cout<<"comparison block for odd\n";
			for(int i=1;i<=mid;i++)
			{
				if(a[mid-i]>a[mid+i])
				{
					a[mid+i] = a[mid-i];
					start = mid+i;
					break;
				}
				else if(a[mid-i] == a[mid+i])
				{
					a[mid+i] = a[mid-i];
				}
				else
				{
					start = mid;
					break;
				}
			}
//			cout<<"comparison block::start :"<<start<<"value: "<<a[start]<<"\n";
		}
		
		//incrementing it
		if(start<=mid)
		{
//			cout<<"increment block\n";
			for(int i=start;i>=0;i--)
			{
				if(a[i]<9)
				{
					a[i]++;
//					cout<<"increment block::a[i]: "<<a[i]<<"\n";
					break;
				}
				a[i] = 0;
			}
		}
		
		//after incrementing, converting all the digits after the mid element to 0
		for(int i=start+1;i<n && n>1;i++)
			a[i] = 0;
//		cout<<"after incrementing the number becomes like:\n";
//		for(int i=0;i<n;i++)
//			cout<<a[i];
//		cout<<endl;
//		cout<<"generating palin ";
		if(n%2==0)
		{
//			cout<<"for even\n";
			n--;
			for(int i=1;i<=n;i+=2)
			{
				if(a[(n-i)/2]!=a[(n+i)/2])
				{
					a[(n+i)/2] = a[(n-i)/2];
//					cout<<"index corrected: "<<(n+i)/2<<" new value: "<<a[(n+i)/2]<<"\n";
				}
			}
			n++;
		}
		else
		{
//			cout<<"for odd\n";
			for(int i=1;i<=mid;i++)
			{
				if(a[mid-i]!=a[mid+i])
				{
					a[mid+i] = a[mid-i];
//					cout<<"index corrected: "<<mid+i<<" new value: "<<a[mid+i]<<"\n";
				}				
			}
		}
//		cout<<"final results\n";
		for(int i=0;i<n;i++)
			cout<<a[i];
		cout<<endl;
	}
	return 0;
}

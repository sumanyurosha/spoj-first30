#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> array;
	int x = 1, z = 1;
	while(x<1e9)
	{
		array.push_back(x);
		x += 6*z;
		z++;
	}
	array.push_back(x);
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)
			break;
		int low = 0;
		int high = array.size()-1;
		bool flag = false;
		while(low<=high)
		{
			int mid = (high+low)/2;
			if(n > array[mid])
				low = mid + 1;
			else if(n<array[mid])
				high = mid - 1;
			else if(n == array[mid])
			{
				flag = true;
				break;
			} 
		}
		flag?cout<<"Y\n":cout<<"N\n";
	}
}

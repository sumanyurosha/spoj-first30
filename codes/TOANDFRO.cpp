#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	while(true)
	{
		int columns;
		cin>>columns;
		if(columns == 0)
			break;
		string crypted_msg;
		cin>>crypted_msg;
		int rows = crypted_msg.size()/columns;
		char decrypto[rows][columns];
		int index = 0;
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				decrypto[i][j] = crypted_msg[index++];
			}
		}
		for(int i=1;i<rows;i+=2)
		{
			for(int j=0;j<columns/2;j++)
			{
				int temp = decrypto[i][j];
				decrypto[i][j] = decrypto[i][columns-j-1];
				decrypto[i][columns-j-1] = temp;
			}
		}
		for(int i=0;i<columns;i++)
		{
			for(int j=0;j<rows;j++)
			{
				cout<<decrypto[j][i];
			}
		}
		cout<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int special[27]={0};
		for(int i=0;i<n;i++)
		{
			string dish;
			cin>>dish;
			set<char> ingredients;
			for(int j=0;j<dish.size();j++)
			{
				ingredients.insert(dish[j]);
			}
			for(auto it=ingredients.begin();it!=ingredients.end();it++)
			{
				special[*it - 'a']++;
			}
		}
		int specialIngredient = 0;
		for(int i=0;i<27;i++)
		{
			if(special[i] == n)
				specialIngredient++;
		}
		cout<<specialIngredient<<"\n";
	}
	return 0;
}

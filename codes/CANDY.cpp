#include <iostream>
using namespace std;

int main() {
	
	// your code here
	ios::sync_with_stdio(false);
	while(true)
    {
        int total_students;
        cin>>total_students;
        if(total_students == -1)
            break;
        int candy_box[total_students];
        int total_candies = 0;
        for(int i=0;i<total_students;i++)
        {
            cin>>candy_box[i];
            total_candies+=candy_box[i];
        }
        if(total_candies%total_students != 0)
            cout<<"-1\n";
        else
        {
            int average_candies = total_candies/total_students;
            int number_of_moves = 0;
            for(int i=0;i<total_students;i++)
            {
                if(average_candies>candy_box[i])
                    number_of_moves += average_candies - candy_box[i];
            }
            cout<<number_of_moves<<"\n";
        }
    }
	return 0;
}

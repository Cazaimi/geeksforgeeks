/*

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains an integer N followed by N numbers to be stored in array.

Output:
Print trap units of water in the middle gap.

Constraints:
1<=T<=100
3<=N<=100
0<=Arr[i]<10

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
 0
*/#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(vector <int> input){
	int n = input.size();
	int totalTrappedWater = 0;
	int left_max = 0;

	loop(i,1,n-1){
		int right_max = 0;
		loop(j,0,i){
		    left_max = max(left_max,input.at(j));
		}
		loop(j,i+1,n){
			right_max = max(right_max,input.at(j));
		}
		int trappedWaterInThisBox = 0;
		if (input.at(i) >= right_max or input.at(i) >= left_max)
		{
			trappedWaterInThisBox = 0;
		}
		else 
		{
			trappedWaterInThisBox = min(left_max,right_max) - input.at(i);
		}

		totalTrappedWater += trappedWaterInThisBox;
	}

	return totalTrappedWater;

}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <int> input(n);
	    loop(i,0,n){
	        int temp = 0;
	        cin >> temp;
	        input.at(i) = temp;
	    }
    	cout << random_function(input) << endl;

	}

	return 0;
}
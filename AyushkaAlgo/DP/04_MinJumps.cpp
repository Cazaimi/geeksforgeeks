/*Minimum number of jumps

Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input:
The first line contains an integer T, depicting total number of test cases.
Then following T lines contains a number n denoting the size of the array.
Next line contains the sequence of integers a1, a2, ..., an.

Output:
Each seperate line showing the minimum number of jumps. If answer is not possible print -1.

Constraints:
1 ≤ T ≤ 40
1 ≤ N ≤ 100
0<=a[N]<=100

Example:

Input:

1
11
1 3 5 8 9 2 6 7 6 8 9

Output:

3*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(vector <int> input){

	int n = input.size();
	int togo = input.at(0),i = 0,steps=1;
	bool exceded = false;
	while(i < n and togo > 0){
		int temp_max = 0, temp_max_index = 0;
		cout << "i:" << i << endl;
		for(int j = i+1;j < togo+i+1; j++){
			cout << "j:" << j << endl;
			if(j >= n) {
				exceded = true;break;
			}
			if(input.at(j) >= temp_max ){
				temp_max = input.at(j);
				temp_max_index = j;
			}
		}
		cout << "temp_max:" << temp_max << endl;
		steps++;
		if(exceded) break;
		togo = temp_max;
		i = temp_max_index;

	}
	cout << "i is" << i << endl;
	if(i == n) return steps;
	else return -1;
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
	        cin >> input.at(i);
	    }

	    cout << random_function(input) << endl;
	}
	return 0;
}

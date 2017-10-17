/* Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. The rightmost element is always a leader. 

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= A[i]<=100

Example:
Input:
2
6
16 17 4 3 5 2
5
1 2 3 4 0
Output:
17 5 2
4 0 */

#include <iostream>
#include <vector>

using namespace std;

void random_function(vector <int> input){
	
	int n = input.size(), sum = 0;
	
	//calulating the sum of the array.
	for(int i = 0;i < n;i++){
	
		sum += input.at(i);
	}
	
	
	//starting the main processing.
	for(int i = 0;i < n;i++){
	
		sum = sum - input.at(i);
		if(input.at(i) > sum or i == n-1){
			//cout << "Leader:" << input.at(i) << " " << "sum to the right:" << sum << endl;
		}
		cout << "Leader:" << input.at(i) << " " << "sum to the right:" << sum << endl;
		
	} 
	
	cout << endl;
	
}

int main(){

	int t = 0;
	cin >> t;
	while(t > 0){
	
		int n = 0;
		cin >> n;
		vector <int> input(n);
		for(int i = 0;i < n;i++){
			int temp = 0;
			cin >> temp;
			input.at(i) = temp;
		}
		
		random_function(input);
		t--;
	}
	return 0;
}
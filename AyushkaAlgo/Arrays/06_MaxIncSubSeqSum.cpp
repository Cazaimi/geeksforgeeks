/* Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[].

Output:

Print the sum of maximum sum sequence of the given array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ A[] ≤ 1000

Example:

Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
For input:
7
1 101 2 3 100 4 5
All the increasing subsequences : (1,101); (1,2,3,100); (1,2,3,4,5), out of this (1,2,3,100) has maximum sum,i.e., 106. Hence the output is stated as 106 */

#include <iostream>
#include <vector>

using namespace std;

int random_function(vector <int> input){

	vector <int> sss(input.size());  //sss -> Sub sequence sum
	int i = 0;
	while(i<input.size()){
		sss.at(i) = input.at(i);
		i++;
	}
	
	int max = 0;
	
	for(int i = 0;i < input.size();i++){
		for(int j = 0;j < i;j++){
			if( input.at(i) > input.at(j) and input.at(i) + sss.at(j) > sss.at(i)) {
				 sss.at(i) = input.at(i) + sss.at(j);
			}
		}
		
		if( sss.at(i) > max) max = sss.at(i);
	}
	
	return max;
}

int main() {
	//code
	
	int t = 0;
	cin >> t;
	while(t > 0){
	    int n = 0;
	    cin >> n;
		vector <int> input(n);
	    for(int i =0;i < n;i++){
			int temp = 0;
			cin >> temp;
			input.at(i) = temp;
		}
		
		cout << random_function(input) << endl;
	    t--;
	}
	
	
	return 0;
}
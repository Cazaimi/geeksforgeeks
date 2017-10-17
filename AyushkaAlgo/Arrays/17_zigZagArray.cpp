/* Convert array into Zig-Zag fashion
   
 
 
 

Given an array of distinct elements, rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f.The relative order of elements is same in the output i.e you have to iterate on the original array only.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the array in Zig-Zag fashion.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
0 ≤A[i]<=10000

Example:
Input:
2
7
4 3 7 8 6 2 1
4
1 4 3 2
Output:
3 7 4 8 2 6 1
1 4 2 3
*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void print(vector <int> &input){
	loop(i,0,input.size()){
		cout << input.at(i) << " ";
	}
	cout << endl;
}

int random_function(vector <int> &input){

	int n = input.size();
	loop(i,0,n-1){
		//Assume that the Left is fixed for you.
		//Fix the right        _
		if(i % 2 == 0){	//even
			if(input.at(i) > input.at(i+1)) swap(input.at(i),input.at(i+1));
		} 
		if(i % 2 != 0){	//odd  _
			if(input.at(i) < input.at(i+1)) swap(input.at(i),input.at(i+1));
		} 
	}

	print(input);
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

		random_function(input);
	}
	return 0;
}
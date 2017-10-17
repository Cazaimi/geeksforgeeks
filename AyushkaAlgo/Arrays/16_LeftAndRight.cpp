/* 	
Element with left side smaller and right side greater
   
 
 
 

Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element present in array then print -1.

Constraints:
1<=T<=100
3<=N<=106
1<=A[i]<=106

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7 */

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(vector <int> input){

	int n = input.size();

	vector <int> left(n);
	vector <int> right(n);

	int temp = input.at(0);
	loop(i,1,n-1){
        left.at(i) = temp;
		temp = max(input.at(i),temp);
	}

	temp = input.at(n-1);
	for(int i = n-2;i > 0;i--){
            
        right.at(i) = temp;
		temp = min(input.at(i),temp);
	}

	loop(i,1,n-1){
		if(left.at(i) <= input.at(i) and right.at(i) >= input.at(i)) return input.at(i);
	}

	return -1;
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
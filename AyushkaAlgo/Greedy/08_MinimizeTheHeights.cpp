/*
Minimize the heights
Given an array A[ ] denoting heights of N towers and a positive integer K, modify the heights of each tower either by increasing or decreasing them by K only once and then find out the minimum difference of the heights of shortest and longest towers.

Example

Input  : A[] = {1, 15, 10}, k = 6
Output : 5
Explanation : We change 1 to 6, 15 to
9 and 10 to 4. Maximum difference is 5
(between 4 and 9). We can't get a lower
difference.


Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains a positive integer K. The second line of each test case contains a positive integer N, denoting number of towers. The third line of the test cases contains N integers denoting the heights of N towers.

Output
For each test case in new line print out the minimum difference of heights possible.

Constraints
1 <= T <= 100
0 <   K <= 30
0 <   N <= 30
0 <= A[i] <= 500


Examples
Input
3
2
4
1 5 8 10
3
5
3 9 12 16 20
4
6
100 150 200 250 300 400

Output
5
11
292

 */
 
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define loop(i,a,n) for(int i = a; i < n; i++)

using namespace std;

int h(vector <int> &input, int n, int k){

/*	int minn = INT_MAX, maxx = INT_MIN;
	loop(i,0,n){
		if(input[i] >= maxx) maxx = input[i];
		if(input[i] <= minn) minn = input[i];
	}
	
	return min(maxx-minn,maxx-minn-2*k); */
	
	sort(input.begin(), input.end());
	int small = input[0], big = input[n-1];
	int def = big - small;
	big = big - k;
	small = small + k;
	
	if(small > big) swap(big,small);

	//cout << "i\t" <<  "small\t" << "big\t" << "subtract\t" << "add\t" << endl;	
	loop(i,1,n-1){
	
		int subtract = input[i] - k,
		    	 add = input[i] + k;
	
		//cout << i << "\t" << small << "\t" << big << "\t" << subtract << "\t\t" << add << endl;	
		if(subtract >= small or add <= big)
			continue;
			//cuz no point.
			
		if(big - subtract <= add - small	)
			small = subtract;
		else 
			big = add;
	}
	
	return min(def, big - small);
}

int main(){
	
	int t = 0;
	cin >> t;
	loop(i,0,t){
		
		int n,k;
		cin >> k >> n;
		vector <int> input(n);
		loop(i,0,n) cin >> input[i];
		cout << h(input,n,k) << endl;
	}
}

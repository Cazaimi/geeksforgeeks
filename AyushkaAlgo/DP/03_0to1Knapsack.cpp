/*0 - 1 Knapsack Problem
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item, In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).


Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of four lines. The first line consists of N the number of items. The second line consists of W, the maximum capacity of the knapsack. In the next  line are N space separated positive integers denoting the values of the N items and in the fourth line are N space separated positive integers denoting the weights of the corresponding items.


Output:

Print the maximum possible value you can get with the given conditions that you can obtain for each test case in a new line.


Constraints:

1≤T≤100

1≤N≤100

1≤W≤100

1≤wt[i]≤100

1≤v[i]≤100


Example:

Input:
1
3
4
1 2 3
4 5 1
Output:
3
*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int napsack(vector <int> weight, vector <int> values, int n, int currweight){
	//cout << "n:" << n << " " << cu endl;
	
	if(n < 0){
		return 0;
	}
	else {
		if(currweight-weight.at(n) <= 0){
			return napsack(weight,values,n-1,currweight);
		}
		return max(napsack(weight,values,n-1,currweight), values.at(n)+napsack(weight,values,n-1,currweight-weight.at(n)));
	}
}

int main(){

	int t = 0;
	cin >> t;
	loop(j,0,t){

		int n = 0,w = 0;
		cin >> n >> w;
		vector <int> values(n), weight(n);
		loop(i,0,n)
			cin >> values.at(i);
		loop(i,0,n)
			cin >> weight.at(i);
		cout << napsack(weight,values,n-1,w) << endl;
	}
}

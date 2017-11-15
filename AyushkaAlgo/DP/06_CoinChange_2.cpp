/*
Coin Change
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Input:

The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

Output:

Print number of possible ways to make change for N cents.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 1 ≤ A[i] ≤ 300

Example:

Input:

2
3
1 2 3
4
4
2 5 3 6
10

Output:

4
5*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;

void print(vector <vector <int> > a,int n, int m){
	loop(i,0,n){
		loop(j,0,m){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int DP(vector <int> coins, int S, int i, vector <vector <int> > &dp){
	
	
	//cout << "S:" << S << " i:" << i << endl;
	//base-cases.
	if(S < 0) return 0;
	if(S == 0 and i == coins.size()) return 1;
	else if(S != 0 and i == coins.size()) return 0;
	
	//dp[S][i]???
	
	if(dp[S][i] != -1) return dp[S][i];
	
	dp[S][i] = DP(coins,S-coins.at(i),i,dp) + DP(coins,S,i+1,dp);
	return dp[S][i];

}



int main(){

	int t = 0;
	cin >> t;
	loop(k,0,t){
		int m = 0,n = 0;
		cin >> m;
		vector <int> input(m);
		loop(i,0,m){
			cin >> input.at(i);
		}
		
		cin >> n;
		
		//initializing the look up table.
		vector <vector <int> > look_up;
		loop(i,0,n+1){
			vector <int> row;
			loop(j,0,m){
				row.push_back(-1);
			}
			look_up.push_back(row);
		}
		
		
		cout << DP(input,n,0,look_up) << endl;
		//print(look_up,n+1,m);
	}
}

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;

int cutting(int Sum, vector <int> xyz){
	
	int n = xyz.size();
	int dp[Sum+1][n+1];
	
	//initializing the base cases:
	//1. sum = 0;
	loop(j,1,n+1) dp[0][j] = 1;
	
	//2. Set is empty
	loop(i,0,Sum+1) dp[i][0] = 0;

	int maxx = 0;	
	loop(i,1,Sum+1){
		loop(j,1,n+1){
			if(xyz[j-1] > i){
				/*Yaani ki
				sum cannot be made 
				using this element*/
				dp[i][j] = 0;			
			}
			else {
				if(dp[i-xyz.at(j-1)][j] == 0 and dp[i][j-1] == 0) dp[i][j] = 0;			
				else dp[i][j] = max(1+dp[i-xyz.at(j-1)][j],dp[i][j-1]);
			}
			
			maxx = max(maxx,dp[i][j]);
		}
	} 
	
	//loop(i,0,Sum+1){loop(j,0,n+1){cout << dp[i][j] << " ";}cout << endl;}
	
	return dp[Sum][n]-1;
}

int main(){

	int t = 0;
	cin >> t;
	loop(i,0,t){
		
		int n = 0;
		vector <int> xyz(3);
		cin >> n >> xyz[0] >> xyz[1] >> xyz[2];
		
		cout << cutting(n,xyz) << endl;
	}
}

/*	cout << "n:" << n << "input.at(" << i >> "):" << xyz.at
	
	//base cases.
	
	int with = 1+cutting(n-xyz[i],xyz,i),
	without = cutting(n,xyz,i-1);
	
	return max(with,without);
*/

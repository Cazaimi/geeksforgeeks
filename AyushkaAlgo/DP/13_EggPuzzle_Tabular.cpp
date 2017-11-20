#include <iostream>
#include <vector>
#include <climits>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

/*int eg(int n, int k, vector <vector<int> > dp){
	
	//cout << n << " " << k << endl;
	/*n is the number of eggs left.
	k is the floor number. 
	if(k == 0) return 0;
	if(k == 1) return 1;
	if(n == 1) return k;
	
	if(dp[n][k] != -1) return dp[n][k];
	
	int minn = INT_MAX, res = 0;
	
	loop(i,1,k+1){
		res = max(eg(n-1,i-1,dp),eg(n,k-i,dp));
		minn = min(minn, res);
	}
	
	dp[n][k] = minn + 1;
	return dp[n][k];
} */

int eg(int n, int k){
	
	/*initializing look up table 
	dp*/
	int dp[n+1][k+1];
	
	
	loop(i,0,n+1){
	 	dp[i][0] = 0;
		dp[i][1] = 1;
	}
	
	loop(j,1,k+1) {
		//dp[0][j] = 0;	
		dp[1][j] = j;
	}
	
	
	loop(i,2,n+1){
		loop(j,2,k+1){
			dp[i][j] = INT_MAX;int res;
			loop(x,1,j+1){
				res = 1+max(dp[i-1][x-1], dp[i][j-x]);
				if(res < dp[i][j]) dp[i][j] = res;
			}			
		}
	}
	
	/*loop(i,0,n+1){
		loop(j,0,k+1){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	return dp[n][k];
}

int main(){

	int t = 0,n = 0,k = 0;
	cin >> t;
	loop(i,0,t){
		cin >> n >> k;
		cout << eg(n,k) << endl;
	}
	return 0;
}

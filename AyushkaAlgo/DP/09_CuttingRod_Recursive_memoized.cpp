#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;

int cutting(int n,int x, int y, int z, vector <int> dp){
	
	dp[0] = 0;
	loop(i,0,n+1){
		if(i >= x and dp[i-x] != -1){
			dp[i] = max(dp[i],1+dp[i-x]);
		}
		if(i >= y and dp[i-y] != -1){
			dp[i] = max(dp[i],1+dp[i-y]);
		}
		if(i >= z and dp[i-z] != -1){
			dp[i] = max(dp[i],1+dp[i-z]);
		}
		//if(i < x and i < y and i < z) dp[i] = 0;		
	}
	
	//loop(i,0,n) cout << dp[i] << " ";
	
	return dp[n];
}

int main(){

	int t = 0;
	cin >> t;
	loop(i,0,t){
		
		int n = 0,x = 0, y = 0,z = 0;
		cin >> n >> x >> y >> z;
		vector <int> dp(n+1,-1);
		cout << cutting(n,x,y,z,dp) << endl;
	}
}

/*	cout << "n:" << n << "input.at(" << i >> "):" << xyz.at
	
	//base cases.
	
	int with = 1+cutting(n-xyz[i],xyz,i),
	without = cutting(n,xyz,i-1);
	
	return max(with,without);
*/

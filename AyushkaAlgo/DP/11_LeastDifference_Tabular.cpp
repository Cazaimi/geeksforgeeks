#include <iostream>
#include <vector>
#include <utility>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int difference(int a, int b){
	return a>=b?a-b:b-a;
}

int rf(vector <int> input, int Sum, int i){
	
	int n = input.size();
	bool dp[Sum+1][n+1];
	
	loop(j,0,n+1){
		dp[0][j] = 1;
	}
	
	loop(i,1,Sum+1){
		dp[i][0] = 0;
	}
	
	int minn = 99999;
	loop(i,1,Sum+1){
		loop(j,1,n+1){
			if(input[j-1] > i) dp[i][j] = dp[i][j-1];
			else if(input[j-1] <= i){
				dp[i][j] = dp[i-input.at(j-1)][j-1] or dp[i][j-1];
			}
			if(dp[i][j] == true and j == n){
				//cout << "i:" << i << " Sum-i:" << Sum-i; 
				//cout << " difference:" << difference(i,Sum-i) << endl;
				minn = min(minn,difference(i,Sum-i));
			}
			
		}
	}
	
	/*loop(i,0,Sum+1){
		loop(j,0,n+1){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	return minn;
	
}

int main(){

	int t = 0;
	cin >> t;
	loop(i,0,t){
		int n = 0;
		cin >> n;
		vector <int> input(n);
		loop(i,0,n) cin >> input.at(i);
		
		int sum = 0;
		loop(i,0,n) sum+= input.at(i);
		
		cout << rf(input,sum,n-1) << endl;
	}
	return 0;
}

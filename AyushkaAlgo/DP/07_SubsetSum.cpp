#include <iostream>
#include <vector>
#include <string>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

string sSum(vector <int> input, int sum){
	
	int n = input.size();
	bool dp[n+1][sum+1];
	
	loop(iterator,0,sum+1) dp[0][iterator] = 0;
	loop(iterator,0,n+1) dp[iterator][0] = 1;
	
	loop(i,1,n+1){  //1 -> n
		loop(j,1,sum+1){  //1 -> sum
			if(input[i-1] > j){
				dp[i][j] = dp[i-1][j];   //simply don't include this element. 
			}
			else {
				//current sum = j.
				int sumaftersubtraction = j - input.at(i-1);
				dp[i][j] = dp[i-1][sumaftersubtraction] + dp[i-1][j]; 
				
				/*i.e., either include the element, and therefore find for 
				reduced sum i.e., sumaftersubtraction, or do not include the
				sum.*/
			}
		}
	}
	
	/*
	 loop(i,0,n+1){
		loop(j,0,sum+1) cout << dp[i][j] << " ";
		cout << endl;
	}
	//*/
	
	 if( dp[n][sum]) return "YES";
	 else return "NO";
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
	    int sum = 0;
	    loop(i,0,n) sum += input.at(i);
	    //cout << sum << endl;
		if(sum % 2 != 0) { 
			cout << 0 << endl;
			continue;
		}
			    
	    cout << sSum(input,sum/2) << endl	;
	}
	return 0;
}

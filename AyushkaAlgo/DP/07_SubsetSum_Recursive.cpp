#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int rf(vector <int> input, int n, int S, int totalS, vector < vector <int> > &dp){
	
	cout << "n:" << n << " S:" << S << " totalSum:" << totalS << endl; 
	
	//base cases.
	if(S == 0.5 * totalS ) return 1;
	else if(S < 0.5 * totalS or n < 0) return 0;
	
	if(dp[n][S] != -1) {
	
		cout << " Called\n";   
		return dp[n][S];
	}	
	
	dp[n][S] = max(rf(input, n-1, S-input.at(n), totalS, dp) , rf(input, n-1, S, totalS, dp));
	return dp[n][S];
	
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
	    
	    //Getting the sum of elements.
	    int totalS = 0;
	    loop(i,0,n) totalS+= input.at(i);
	    
	    //dp[i][S]
	    vector <vector <int> > dp;
	    loop(i,0,n){
	    		vector <int> row;
	    		loop(j,0,totalS+1){
	    			row.push_back(-1);
	    		}
	    		dp.push_back(row);
	    }
	    
	    //Calling the function.
	    int whether =  rf(input, n-1, totalS, totalS, dp);

	    //Printing Output.
	    if(whether) cout << "YES\n";
	    else cout << "NO\n";
	}
	
	//returning 0 :P
	return 0;
}

/* Shortest Common Supersequence
Given two strings str1 and str2, find the shortest common shortest common subsequence of the two strings.

Input:
The first line of input contains an integer T denoting the number of test cases.Each test case contains two space separated strings.

Output:
Output the length of the shortest common supersequence.

Constraints:
1<=T<=100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
*/

#include <iostream>
#include <string>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;


int lcs(string a, string b){
	
	int n = a.length(), m = b.length(), maxx = 0;
	int dp[n+1][m+1];
	
	
	for(int i = 0;i <= n; i++){
		for(int j = 0;j <= m; j++){
			//cout << i << " " << j << endl;
			if(i == 0 or j == 0){
				dp[i][j] = 0;
			}
			else if(a.at(i-1) == b.at(j-1)){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
			
			maxx = max(maxx,dp[i][j]);
		}
	}
	
	
	/*loop(i,0,n+1){
		loop(j,0,m+1){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	//cout << maxx << endl; */
	
	return maxx;
}

int rf(string a, string b){
	
	int same = lcs(a,b);
	//cout << same << endl;
	int different = (a.length() - same) + b.length();
	return different; 
}

int main(){
	
	int t =0;
	cin >> t;
	loop(i,0,t){
		string a,b;
		cin >> a >> b;
		cout << rf(a,b) << endl;
	}

}

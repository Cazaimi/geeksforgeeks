/* 	Count number of hops
Frog steps either 1, 2 or 3 steps to go to top. In how many ways it reaches the top?

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N. Where is the number of steps it has to hop.

Output:

Print the number of ways.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 50

Example:

Input:
2
1
5

Output:
1
13

*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;



int random_function(int n){
    
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    loop(i,4,n+1){
        
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    return dp[n];
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    cout << random_function(n) << endl;
	}
	return 0;
}

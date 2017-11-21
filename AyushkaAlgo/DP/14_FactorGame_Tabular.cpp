#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

/*int game(int n, int turn){
    
    //cout << "(" << n << "," << turn%2 << ")" << endl;
	//base cases.
	if(n <= 0){
		//cout << "being called!\n" ;
		if(turn % 2 == 0)
		return 0;
		else return 1;  
	}
	
	int winner = (turn + 1) % 2;
	for(int i = 1;i < n; i++){
		if(n % i == 0){
			//cout << "n:" << n << " i:" << i << endl;
			winner = game(n - i,turn+1);
			if(winner != turn % 2) continue;
			else break;
		}
	}

	return winner;

} */

int game(int n){
	
	int turn = 1;
	int dp[n+1][2];
	
	for(int i = 0;i <= 1; i++){
		dp[i][0] = 1;
		dp[i][1] = 0;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= 1;j++){
			dp[i][j] = (j+1) % 2; int res;
			for(int x = 1; x < i;i++){
				if(i % x == 0){
					res = dp[i-x][(turn+1)%2];
					if(res != j % 2) continue;
					else dp[i][j] = res;
				}
			}
		}
	}
	
	return dp[n][1];
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    cout << game(n) << endl;
	}
	return 0;
}

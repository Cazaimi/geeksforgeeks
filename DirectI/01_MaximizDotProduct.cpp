#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

unsigned long long int func(vector <int> a, vector <int> b, int n, int m){
    
    unsigned long long int dp[n+1][m+1];
    loop(i,0,n+1){
        loop(j,0,m+1){
            dp[i][j] = 0;
        }
    }
    
    for(int j = 1; j < m+1; j++){
        for(int i = j;i < n+1; i++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + a[i-1]*b[j-1]);
        }
    }
    
    /*loop(i,0,n+1){
        loop(j,0,m+1){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    
    return dp[n][m];
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0,m = 0;
	    cin >> n >> m;
	    vector <int> a(n);
	    vector <int> b(m);
	    loop(i,0,n)
	        cin >> a.at(i);
        loop(i,0,m)
	        cin >> b.at(i);
        cout << func(a,b,n,m) << endl;
	}
	return 0;
}
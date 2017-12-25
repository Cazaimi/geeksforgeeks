#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int func(int x,int s,int m,int l,int cs,int cm,int cl,vector <int> &dp){
    //cout << x << "\n";
    if(x <= 0) return 0;

    if(dp[x] == -1){
            dp[x] = min(cs+func(x-s,s,m,l,cs,cm,cl,dp),min(cm+func(x-m,s,m,l,cs,cm,cl,dp),cl+func(x-l,s,m,l,cs,cm,cl,dp)));
            return dp[x];
    } 
    else return dp[x];
    }


int main()
 {
	//code      
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int x ,s,m,l,cm,cs,cl;
	    cin >> x >> s >> m >> l;
	    cin >> cs >> cm >> cl;
	    
	    vector <int> dp(x+1,-1);
	    
	    cout << func(x,s,m,l,cs,cm,cl,dp) << endl;
	}
	return 0;
}
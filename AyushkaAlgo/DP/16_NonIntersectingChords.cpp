long long find(int n, vector <long> &dp){
   
   long long po = 7 + pow(10,9); 
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    
    dp[n] = 0;
    for(int i = 0;i <= n-1; i++){
        dp[n] =( dp[n]%po + ( (find(i,dp)%po) * (find(n-i-1,dp)%po) % po)) % po;
    }
    
    return dp[n];
    
}

int Solution::chordCnt(int n) {
    
    vector <long> dp(n+1,-1);
    dp[0] = 1;
    return (int)find(n, dp);
}

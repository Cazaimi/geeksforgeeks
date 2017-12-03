#include <iostream>
#include <vector>
#include <climits>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int eg(int n, int k, vector <vector<int> > dp){
		
		//cout << n << " " << k << endl;
		//	/*n is the number of eggs left.
		//		k is the floor number. */
		//			if(k == 0) return 0;
		//				if(k == 1) return 1;
		//					if(n == 1) return k;
		//						
		//							if(dp[n][k] != -1) return dp[n][k];
		//								
		//									int minn = INT_MAX, res = 0;
		//										
		//											loop(i,1,k+1){
		//													res = max(eg(n-1,i-1,dp),eg(n,k-i,dp));
		//															minn = min(minn, res);
		//																}
		//																	
		//																		dp[n][k] = minn + 1;
		//																			return dp[n][k];
		//																			}
		//
		//																			int main(){
		//
		//																				int t = 0,n = 0,k = 0;
		//																					cin >> t;
		//																						loop(i,0,t){
		//																								cin >> n >> k;
		//																										vector <vector <int> > dp;
		//																												loop(i,0,n+1){
		//																															vector <int> row;
		//																																		loop(i,0,k+1){
		//																																						row.push_back(-1);
		//																																									}
		//																																												dp.push_back(row);
		//																																														}
		//																																																cout << eg(n,k,dp) << endl;
		//																																																	}
		//																																																		return 0;
		//																																																		}

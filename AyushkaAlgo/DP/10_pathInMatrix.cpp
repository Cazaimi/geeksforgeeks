#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;


int pathFromHere(vector <vector <int> > matrix, vector <vector <int> > &dp, int i, int j){
	
	int n = matrix.size();
	
	if(i < 0 or i >= n or j < 0 or j >= n) return 0;
	
	//cout << "Matrix[i][j]:" << matrix[i][j] << endl;
	//cout << "Matrix[i][j]:" << matrix[i-1][j] << endl;
	if(dp[i][j] != -1) return dp[i][j];
	
	
	
	if( i > 0 and matrix[i][j] == matrix[i-1][j]+1 ){
		//cout << "FIRST i:" << i << " j:" << j << endl;
		dp[i][j] = max(dp[i][j],1+pathFromHere(matrix,dp,i-1,j));
		
	}
	if( i < n-1 and matrix[i][j] == matrix[i+1][j]+1){
		//cout << "SECOND i:" << i << " j:" << j << endl;
		dp[i][j] = max(dp[i][j],1+pathFromHere(matrix,dp,i+1,j));
	}
	if( j > 0 and matrix[i][j] == matrix[i][j-1]+1){
		//cout << "THIRD i:" << i << " j:" << j << endl;
		dp[i][j] = max(dp[i][j],1+pathFromHere(matrix,dp,i,j-1));
	}
	if( j < n-1 and matrix[i][j] == matrix[i][j+1]+1){
		//cout << "FOURTH i:" << i << " j:" << j << endl;
		dp[i][j] = max(dp[i][j],1+pathFromHere(matrix,dp,i,j+1));
	}
	dp[i][j] = max(dp[i][j],1) ;
	return dp[i][j];
	
}

int longestpath(vector <vector <int> > matrix ){
	
	int n = matrix.size();
	
	vector <vector <int> > dp;
	loop(i,0,n){
 		vector <int> row;
 		loop(j,0,n) row.push_back(-1);
 		dp.push_back(row);
	}
	
	int maxx = 0;
	loop(i,0,n){
		loop(j,0,n){
			//cout << "Calling i=" << i << " & j=" << j << endl; 
			maxx = max(maxx,pathFromHere(matrix,dp,i,j));
		}
	}
	
	loop(i,0,n){
		loop(j,0,n){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	return maxx;
}

int main(){

	int t = 0;
	cin >> t;
	loop(i,0,t){
		int n = 0;
		cin >> n;
		vector <vector <int> > matrix;
		loop(i,0,n){
			vector <int> row;
			loop(j,0,n){ 
				int temp = 0;
				cin >> temp;
				row.push_back(temp);			
			}
			matrix.push_back(row);
		}
		
		cout << longestpath(matrix) << endl;
	}
	return 0;
}

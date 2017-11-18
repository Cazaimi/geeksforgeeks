#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;

int chkSurr(vector <vector <int> > matrix){
	
}

int path(vector <vector <int> > matrix, vector <vector <int> > dp){
	
	
}

int main(){

	int t = 0;
	cin >> t;
	loop(i,0,t){
		int n = 0;
		cin >> n;
		vector <vector <int> > matrix,<vector <int> > dp;
		loop(i,0,n){
			vector <int> row, <int> auxrow;
			loop(j,0,n){ 
				int temp = 0;
				cin >> temp;
				row.push_back(temp);
				auxrow.push_back(1);
				
			}
			matrix.push_back(row);
			dp.push_back(auxrow);
		}
		
		int path(matrix,dp);
	}
	return 0;
}

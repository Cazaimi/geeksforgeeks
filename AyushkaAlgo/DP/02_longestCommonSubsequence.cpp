#include <iostream>
#include <vector>
#include <string>

#define loop(i,a,n) for (int i = a; i < n; i++)

using namespace std;

int random_function(string a, string b){

	int m = a.length(), n = b.length();
	vector <int> lcs[m+1];

	//initializing the lcs array.
	loop(i,0,m+1){
	  loop(j,0,n+1){
		   lcs[i].push_back(0);
	  }
	}

	int maxx = 0;
	loop(i,0,m+1){
		loop(j,0,n+1){
			if(i == 0 or j == 0){
				lcs[i].at(j) = 0;
			}
			else if(a.at(i-1) == b.at(j-1)){
				lcs[i].at(j) = lcs[i-1].at(j-1) + 1;				
			}
			else {
				lcs[i].at(j) = max( lcs[i-1].at(j),lcs[i].at(j-1) ); 
			}
			maxx = max(maxx,lcs[i].at(j));
		}
	}
	return maxx;
}

int main(){
     int t = 0;
     cin >> t;
     loop(j,0,t){
          int c;
          cin >> c >> c;
          string a,b;
          cin >> a >> b;
          cout << random_function(a,b) << endl;
     }
}

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;

int cutting(int n, vector <int> xyz, int i){
	
	//base cases.
	if(n == 0) {
		//cout<< "n=0;\n";
		return 0;
	}
	if(i < 0){ 
		//cout<< "i<0\n";
		return 0;
	}
	if(n < xyz.at(i)) {
		//cout<< "n < xyz[i]\n";
		return 0;
	}
	
	//cout << "n:" << n << " i:" << i << " input.at(i):" << xyz.at(i) << endl;

	return max( cutting(n,xyz,i-1),1+cutting(n-xyz.at(i),xyz,i));
}

int main(){

	int t = 0;
	cin >> t;
	loop(i,0,t){
		
		int n = 0;
		vector <int> xyz(3);
		cin >> n >> xyz[0] >> xyz[1] >> xyz[2];
		
		cout << cutting(n,xyz,2) << endl;
	}
}

/*	cout << "n:" << n << "input.at(" << i >> "):" << xyz.at
	
	//base cases.
	
	int with = 1+cutting(n-xyz[i],xyz,i),
	without = cutting(n,xyz,i-1);
	
	return max(with,without);
*/

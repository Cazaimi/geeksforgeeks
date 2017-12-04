#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;

int eg(int n, int k){
	
	/*I know it's confusing,
	but n = number of eggs, and k = 
	number of floors.*/
	
	//base cases.
	if(k == 0) return 0;
	if(k == 1) return 1;
	if(n == 1) {//only one egg is left.
		return k;
	}
	
	int minn = 99999;
	loop(i,1,k+1){
		
		int res = max(eg(n-1,i-1),eg(n,k-i));
		minn = min(res,minn); 
	}
	
	return minn + 1;
}

int main(){
	int t,n,k;
	cin >> t;
	loop(i,0,t){
		cin >> n >> k;
		cout << eg(n,k) << endl;
	}
}

#include <iostream>
#include <vector>
#include <utility>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int difference(int a, int b){
	return a>=b?a-b:b-a;
}

int rf(vector <int> input, int i, int aSum, int bSum){
	
	//base cases 
	if(i < 0) return difference(aSum,bSum);
	cout << aSum << " " << bSum << endl;
	
	return min( rf(input,i-1,aSum,bSum),rf(input,i-1,aSum-input.at(i),bSum+input.at(i)) );
	
}

int main(){

	int t = 0;
	cin >> t;
	loop(i,0,t){
		int n = 0;
		cin >> n;
		vector <int> input(n);
		loop(i,0,n) cin >> input.at(i);
		
		int sum = 0;
		loop(i,0,n) sum+= input.at(i);
		
		cout << rf(input,n-1,sum,0) << endl;
	}
	return 0;
}

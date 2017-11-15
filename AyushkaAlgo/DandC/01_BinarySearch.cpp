#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;

int random_function(int input[], int low, int high, int key){
	
	
	//cout << low << " " << high << endl;
	//cout << input.at(low) << endl;
	//base cases.
	if(input[low] == key) return low;
	if(input[high] == key) return high;
	if(low >= high) return -1;
	
	int middle = low + ((high-low)/2);
	if(key > input[middle] ) return random_function(input,middle,high,key);
	else return random_function(input,low,middle,key);
}

int main(){

	int t = 0;
	cin >> t;
	loop(i,0,t){
		int n = 0, key = 0;
		cin >> n;
		vector <int> input(n);
		loop(i,0,n) cin >> input.at(i);
		cin >> key;
		cout << random_function(input,0,n-1,key) << endl;
	}
}

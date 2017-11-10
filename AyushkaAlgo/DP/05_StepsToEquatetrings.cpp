#include <iostream>
#include <vector>

using namespace std;

int rf(string a, string b, int n, int m){
	if(m < 0 or n < 0 or a == b){
		return 0;
	}
	string zero = a.substr(n,1),one = b.at(m,1);
	int insert0 = rf(a+one,b,n-1,m), 
	insert1 = rf(a,b+zero,n,m-1);
	delete0 = rf(a.substr(0,n-1),b,n-1,m)
	delete1 = rf(a,b.substr(0,m-1),n,m-1);
	replace0 = rf(a,b,n,m),
	replace1 = rf(a,b,n,m);	
	
	
	return min(
		insert0+1,insert1+1,delete0+1,delete1+1,replace0+1,replace1+1
	);
}

int main(){
	int t = 0;
	cin >> t;
	for(int j = 0;j < t; j++){
		string a,b;
		cin >> a >> b;
		cout << rf(a,b,a.length()-1,b.length()-1);
	}
}

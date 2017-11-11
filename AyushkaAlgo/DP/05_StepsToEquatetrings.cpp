#include <iostream>
#include <vector>

using namespace std;

#define loop(i,a,n) for(int i = a;i < n; i++)

void initialize_lookup(vector <vector <int> > &a,int n, int m){
    loop(i,0,n){
            vector <int> row;
			loop(j,0,m){
			    row.push_back(-1);
			}
			a.push_back(row);
	}
}

int minimumof6(int a,int b,int c,int d,int e,int f){
	return (min (a,min(b,min(c,min(d,min(e,f))))));
}

int rf(string a, string b, int n, int m,vector <vector <int> > &look_up){
	if(m < 0 or n < 0 or a == b){
		return 0;
	}
	/*if(n == 0 or m == 0){
		string zero = a.substr(n,1),one = b.substr(m,1);
		int insert0 = rf(a+one,b,n-1,m,look_up), 
		insert1 = rf(a,b+zero,n,m-1,look_up),
		delete0 = rf(a.substr(0,n),b,n-1,m,look_up),
		delete1 = rf(a,b.substr(0,m),n,m-1,look_up),
		replace0 = rf(a.substr(0,n)+one,b,n-1,m,look_up),
		replace1 = rf(a,b.substr(0,m)+zero,n,m-1,look_up);	
	}*/
	//else {
		string zero = a.substr(n,1),one = b.substr(m,1);
		int insert0 = look_up.at(n).at(m)==-1?rf(a+one,b,n-1,m,look_up):look_up.at(n).at(m), 
		insert1 = look_up.at(n).at(m)==-1?rf(a,b+zero,n,m-1,look_up):look_up.at(n).at(m),
		delete0 = look_up.at(n).at(m)==-1?rf(a.substr(0,n),b,n-1,m,look_up):look_up.at(n).at(m),
		delete1 = look_up.at(n).at(m)==-1?rf(a,b.substr(0,m),n,m-1,look_up):look_up.at(n).at(m),
		replace0 = look_up.at(n).at(m)==-1?rf(a.substr(0,n)+one,b,n-1,m,look_up):look_up.at(n).at(m),
		replace1 = look_up.at(n).at(m)==-1?rf(a,b.substr(0,m)+zero,n,m-1,look_up):look_up.at(n).at(m);	
	//}

	look_up.at(n).at(m) = minimumof6(insert0,insert1,delete0,delete1,replace0,replace1);	
	
	return look_up.at(n).at(m) + 1;
}

int main(){
	int t = 0;
	cin >> t;
	for(int j = 0;j < t; j++){
		int n,m;
		cin >> n >> m;
		vector <vector <int> > look_up;
		initialize_lookup(look_up,n,m);
		string a,b;
		cin >> a >> b;
		cout << rf(a,b,a.length()-1,b.length()-1,look_up) << endl;
		//cout << look_up[0].at(0);
	}
}

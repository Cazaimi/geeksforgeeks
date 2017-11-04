#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

string random_function(string a,string b){

  int n = a.length(),sum = 0;
  if(a.length() != b.length()) return "NO";
  loop(i,0,n){
    sum += (a.at(i) - b.at(i));
  }
  if(sum == 0) return "YES";
  else return "NO";
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){

	    string a, b;
      cin >> a >> b;
      cout << random_function(a,b) << endl;
	}
	return 0;
}

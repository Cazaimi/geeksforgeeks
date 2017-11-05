#include <iostream>
#include <vector>
#include <climits>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int minn(int a, int b){
     return a > b?b:a;
}

int random_function(string input, int low, int high){

    //Base cases
    //L8r
    //Now
    if(low > high) return INT_MAX;
    if(low == high) return 0;
    if(low == high - 1) return (input.at(low) == input.at(high))? 0 : 1;

    char temp;
    cout << low << " " << high << endl;
    //cin >> temp;
    return (input.at(low) == input.at(high)) ?
        random_function(input,low+1,high-1):
            ( minn(random_function(input,low+1,high),random_function(input,low,high-1)) + 1);
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){

	    string input;
	    cin >> input;
	    cout << random_function(input,0,input.length()-1) << endl;
	}
	return 0;
}

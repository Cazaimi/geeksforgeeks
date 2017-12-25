#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(vector <int> &input, int n, int k){

    sort(input.begin(), input.end());
    int i = 0, count = 0;
    while(i < n and k > 0){

        k -= input[i];
        if(k > 0) count++;
        i++;
    }

    return count;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){

	    int n = 0, k = 0;
	    cin >> n >> k;
	    vector <int> input(n);
	    loop(i,0,n){
	        cin >> input.at(i);
	    }

	    cout << random_function(input,n,k) << endl;
	}
	return 0;
}

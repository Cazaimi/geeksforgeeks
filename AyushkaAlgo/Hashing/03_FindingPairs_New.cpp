#include <bits/stdc++.h>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

string random_function(vector <int> input, int n, int k){

	if(n % 2 != 0) return "False";
	map <int,int> freq;
	loop(i,0,n){
		freq[input[i]%k]++;
	}
	
	loop(i,0,n){
		
		int now = input[i] % k;
		if(2*now == k){
			if(freq[now] % 2 != 0) return "False";
		}
		else if(now == 0){
			
			if(freq[now] % 2 != 0) return "False";
		}
		else if(freq[now] != freq[k-now]){
			return "False";
		}
	}
	
	return "True";
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0,k = 0;
	    cin >> n;
	    vector <int> input(n);
	    loop(i,0,n){
	        cin >> input.at(i);
	    }
	    
	    cin >> k;
	    
	    cout << random_function(input,n,k) << endl; 
	}
	return 0;
}

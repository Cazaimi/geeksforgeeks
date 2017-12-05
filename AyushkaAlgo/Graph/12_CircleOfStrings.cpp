#include <bits/stdc++.h>
#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int compare ( pair<pair <char,char>,int> a, pair<pair <char,char>,int> b){
	
	return a.first.first < b.first.first? 1:0;
}

int cs(vector <pair<pair <char,char>,int> > input){
	
	sort(input.begin(),input.end(), compare);
	
	loop(i,0,input.size()){
		if(
	}
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <pair<pair <char,char>,int> > input(n);
	    loop(i,0,n){
	    	string temp;
	        cin >> temp;
	        input.first.first = temp[0];
	        input.first.second = temp[temp.size()-1];
	        input.second = 0;
	    }
	    
	    cout << cs(input) << endl;
	}
	return 0;
}

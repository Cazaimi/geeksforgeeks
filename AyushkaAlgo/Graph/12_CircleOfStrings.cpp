#include <bits/stdc++.h>
#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int compare ( pair<pair <char,char>,int> a, pair<pair <char,char>,int> b){
	
	return a.first.first < b.first.first? 1:0;
}

int cs(vector <pair <char,char> > input){
	
	//sort(input.begin(),input.end(), compare);
	vector <pair<int,int> > alphabet(26);
	
	loop(i,0,input.size()){
		alphabet[input[i].first-97].first++;
		alphabet[input[i].first-97].second = i;
	}
	
	loop(i,0,input.size()){
		if(alphabet[input[i].second-97].first > 0 and alphabet[input[i].second-97].second != i){
			alphabet[input[i].second-97]--;
		}
		else{
			return 0;
		}
	}
	
	return 1;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <pair <char,char> > input(n);
	    loop(i,0,n){
	    	   string temp;
	        cin >> temp;
	        input[i].first = temp[0];
	        input[i].second = temp[temp.size()-1];
	        //input.second = 0;
	    }
	    
	    cout << cs(input) << endl;
	}
	return 0;
}

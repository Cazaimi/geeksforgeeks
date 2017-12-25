#include <bits/stdc++.h>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

string random_function(vector <int> input, int n, int k){
    
    if(n%2 != 0) return "False";
    map <int,int> hash;
    loop(i,0,n){
        pair <map <int,int> ::iterator,bool> tjj = hash.insert(make_pair(input[i]%k,i));
        if(!tjj.second){
            //element already present
            hash.erase(tjj.first);
        }
    }
    
    map <int,int> hash2;
    //lesson learned: Don't iterate with hashes.
    while(!hash.empty()){
        map <int,int>::iterator it = hash.begin();
        pair <int,int> th = *it;
        map <int,int>::iterator it2 = hash.find(k-th.first);
        if(it2 != hash.end()){
            hash.erase(it);
            hash.erase(it2);
        }
        else return "False"; 
        
        //cout << th.first << " " << th.second << endl;
        //hash.erase(it);
    }
    
    //if(!hash.empty()) return "False";
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

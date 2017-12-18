#include <bits/stdc++.h>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int sub(vector <int> input, int n){
    
    sort(input.begin(),input.end());
    
    map <int,int> hash;
    int maxx = 1;
    loop(i,0,n) hash.insert(make_pair(input.at(i),1));
    map <int,int> ::iterator i;
    for( i=hash.begin();i != hash.end(); i++){
        map <int,int>::iterator it = hash.find((*i).first-1);
        if(it != hash.end()){
            
            (*i).second = (*it).second+1;
            maxx = max((*i).second,maxx);
        }
    }
    
    return maxx;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <int> input(n);
	    loop(i,0,n){
	        cin >> input.at(i);
	    }
	    
	    cout << sub(input,n) << endl;
	}
	return 0;
}

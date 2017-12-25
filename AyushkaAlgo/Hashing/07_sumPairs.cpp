#include <bits/stdc++.h>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void print(vector <pair <int,int> > a){
    
    int n = a.size();
    loop(i,0,n-1){
        cout << a[i].first << " " << a[i].second << ", ";
    }
    
    cout << a[n-1].first << " " << a[n-1].second << endl;
}

void sum(vector <int> a, vector <int> b, int x){
    
    map <int,int> hash;
    vector <pair <int,int> > output;
    int count = 0, n = a.size(), m = b.size();
    loop(i,0,n) hash.insert(make_pair(x-a[i],i));
    
    loop(i,0,m){
        map <int,int> :: iterator it = hash.find(b[i]);
        if(it != hash.end()){
            pair <int,int> now = *it;
            output.push_back(make_pair(now.first,(x-(now.first))));
        } 
    }
    
    print(output);
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0, m = 0,x = 0;
	    cin >> n >> m >> x;
	    vector <int> a(n);
	    vector <int> b(m);
	    loop(i,0,n){
	        cin >> a.at(i);
	    }
	    loop(i,0,m) cin >> b[i];
	    sum(a,b,x);
	}
	return 0;
}

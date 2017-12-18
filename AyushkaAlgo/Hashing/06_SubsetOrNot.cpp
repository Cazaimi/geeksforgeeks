#include <bits/stdc++.h>

#define loop(i,a,n) for(int i = a;i < n;i++)
using namespace std;

string common(vector <int> a, vector <int> b, int n, int m){
    
    map <int,int> hash;
    loop(i,0,n) hash.insert(make_pair(a[i],i));
    
    
    loop(i,0,m){
        map <int,int> :: iterator it = hash.find(b[i]);
        if(it == hash.end()) return "No";
    }
    
    return "Yes";
}

int main(){
    
    int t = 0;
    cin >> t;
    loop(k,0,t){
        
        int n,m;
        cin >> n >> m;
        vector <int> a(n); vector <int> b(m);
        loop(i,0,n) cin >> a.at(i);
        loop(i,0,m) cin >> b.at(i);
        
        cout << common(a,b,n,m) << endl; 
    }
}

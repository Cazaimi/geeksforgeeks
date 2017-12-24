#include <bits/stdc++.h>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(vector <int> a, vector <int> b, int k){

    int n = a.size(), m = b.size();
    int i = 0, j = 0, x = 1;
    while(i < n and j < m){
        if(x == k){
            return min(a[i],b[j]);
        }
        if(a[i] <= b[j]){
            i++;
            x++;
        }
        else {
            j++;
            x++;
        }
    }
    if(i == n) return b[j+k-x];
    if(j == m) return a[i+k-x];

}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0,m = 0,k = 0;
	    cin >> n >> m >> k;
	    vector <int> a(n);
	    vector <int> b(m);
	    loop(i,0,n) cin >> a.at(i);
	    loop(i,0,m) cin >> b.at(i);
	    cout << random_function(a,b,k) << endl;
	}
	return 0;
}

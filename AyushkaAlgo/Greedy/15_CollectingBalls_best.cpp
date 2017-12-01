#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int f(vector <int> a, vector <int> b, int n, int m){

	int i = 0, j = 0, cummI = 0, cummJ = 0, ps = 0, lcI = -1, lcJ = -1;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	while(i < n and j < m){
		//cout << i << " " << j << endl;
		if(a[i] < b[j]){
			cummI += a[i];
			i++;
		}
		else if(b[j] < a[i]){
			cummJ += b[j];
			j++;

		}
		else {
			cummI += a[i];
			cummJ += b[j];
			ps += max(cummI,cummJ);
			cummI = 0;
			cummJ = 0;
			lcI = i;
			lcJ = j;
			i++; j++;
		}

	}

	cummJ = cummI = 0;

	//cout << endl << lcI << " " << lcJ << endl;
	for(int i = lcI+1;i < n;i++)cummI += a[i];
	for(int j = lcJ+1;j < m;j++)cummJ += b[j];

	ps += max(cummI, cummJ);

	return ps;
}
int main()
 {
	//code
	int t = 0;
	cin >> t;
	for(int j=0;j < t; j++){

	    int n = 0,m = 0;
	    cin >> n >> m;
	    vector <int> a(n);
	    vector <int> b(m);
	    for(int i=0;i < n; i++) cin >> a.at(i);
	  	for(int i=0;i < m; i++) cin >> b.at(i);
	  	cout << f(a,b,n,m) << endl;
	}
	return 0;
}

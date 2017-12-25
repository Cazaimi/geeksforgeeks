/*	
Geek collects the balls
   
 

There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. The buckets n both roads are kept in such a way that they are sorted according to the number of balls in them. Geek starts from the end of the road which has the bucket with lower number of balls(i.e. if buckets are sorted in increasing order, then geek will start from the left side of road).
The geek can change the road only at the point of intersection(which means , buckets with the same number of balls on two roads). Now you need to help Geek to collect the maximum number of balls.

Input:
First line of input contains T denoting number of test cases. First line of each test case contains two integers N and M, denoting the number of buckets on road1 and road2 respectively. 2nd line of each test case contains N integers, number of balls in buckets on first road. 3rd line of each test case contains M integers, number of balls in buckets on second road.

Output:
For each test case output a single line containing the maximum possible balls that Geek can collect.

Constraints:
1<= T <= 1000
1<= N <= 103
1<= M <=103
0<= Ai,Bi <=109

Example:
Input:
1
5 5
1 4 5 6 8
2 3 4 6 9

Output:
29

Explanation:

The path with maximum sum is (2,3,4)[5,6](9). Integers in [] are the buckets of first road and in () are the buckets of second road. So, max balls geek can collect is 29.*/

#include <iostream>
#include <vector>

//#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;



int getFromPrev(vector <int> a, int start, int end){

	int sum = 0;
	for(int i= start+1;i <= end; i++){
		sum += a[i];
	}
	
	return sum;
}

int f(vector <int> a, vector <int> b, int n, int m){
	
	int ps = 0, cummI = 0, cummJ = 0, i = 0, j = 0, prevI = -1, prevJ = -1;
	//cout << "i" << "\t" << "j" << "\t" << "cummI" << "\t" << "cummJ" << "\t" << "ps" << endl;
	for(i = 0;i < n;i++){
		cummJ = 0;//cummI = 0;
		cummI += a[i];
		for(j = 0;j < m;j++) {
			if(j > prevJ) cummJ += b[j];
			//cout << i << "\t" << j << "\t" << cummI << "\t" << cummJ << "\t" << ps << endl;
			if(a[i] == b[j]){
				
				ps += max(cummI, cummJ);
				prevI = i;
				prevJ = j;
				cummI = 0;
			}
			//cout << i << "\t" << j << "\t" << cummI << "\t" << cummJ << "\t" << ps << endl;
		}
		//cout << endl;
	}
	
	if(prevI != n-1) ps += max(getFromPrev(a,prevI,n-1), getFromPrev(b,prevJ,m-1));
	
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

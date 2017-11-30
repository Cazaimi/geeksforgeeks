/*Minimize the sum of product
Given two arrays, A and B, of equal size n, the task is to find the minimum value  of A[0] * B[0] + A[1] * B[1] +…+ A[n-1] * B[n-1], where shuffling of elements of arrays A and B is allowed.


Examples:

Input : A[] = {3, 1, 1} and B[] = {6, 5, 4}.
Output : 23 Minimum value of S = 1*6 + 1*5 + 3*4 = 23.

Input : A[] = { 6, 1, 9, 5, 4 } and B[] = { 3, 4, 8, 2, 4 }
Output : 80. Minimum value of S = 1*8 + 4*4 + 5*4 + 6*3 + 9*2 = 80.


Input:
The first line of input contains an integer denoting the no of test cases. Then T test cases follow. Each test case contains three lines. The first line of input contains an integer N denoting the size of the arrays. In the second line are N space separated values of the array A[], and in the last line are N space separated values of the array B[].

Output:
For each test case in a new line print the required result.

Constraints:
1<=T<=100
1<=N<=50
1<=A[]<=20

Example:
Input:
2
3 
3 1 1
6 5 4
5
6 1 9 5 4
3 4 8 2 4
Output:
23 
80*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(vector <int> a,vector <int> b){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	int answer = 0;
	loop(i,0,n){
		answer += a[i]*b[n-1-i];
	}
	
	return answer;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <int> a(n), <int> b(n);
	    loop(i,0,n)
	        cin >> a.at(i);
	    loop(i,0,n)
	        cin >> b.at(i);
	    cout << random_function(a,b) << endl;
	}
	return 0;
}

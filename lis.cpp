/*
Longest Increasing Subsequence
Show Topic Tags         Amazon    BankBazaar    Paytm    Samsung
Given a sequence, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest
to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

For example:
 length of LIS for 
{ 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.


Output:

Print the Max length of the subsequence in a separate line.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 300

Example:

Input
1
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
Output
6 */


#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int t = 0;
	cin >> t;
	while(t>0){
	    
		int n = 0;
		int max_lis = 1;
		cin >> n;
		if(n > 0){
    		vector <int> arr(n);
    		vector <int> lis(n,1);
    
    		for(int i=0;i<n;i++){
    			int temp = 0;
    			cin >> temp;
    			arr.at(i) = temp;
    		}
    
    		for(int i=1;i<n;i++){
    			for(int j=0;j<i;j++){
    				if(arr.at(j) < arr.at(i) and lis.at(i) < lis.at(j) + 1 ) {
    					lis.at(i) = lis.at(j) + 1;
    					max_lis = max( lis.at(i) , max_lis );
    					//cout << "here\n";	
    				}
    			}
    		}
    		int it = 0;
    		/* For printing the lis array:
    		while(it < n){
    			cout << lis.at(it) << " "; 
    			it++;
    		} */
    		cout << max_lis << endl;
		}
		else if(n == 0) cout << "0" << endl;
	    t--;
	}
	return 0;
}


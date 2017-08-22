/* Question -->
Sum of non-Overlapping SubArrays
Given an array of N elements, you are required to find the maximum sum of lengths of all non-overlapping subarrays with K as the maximum element in the subarray.
.
Input:
First line of the input contains an integer T, denoting the number of the total test cases. Then T test case follows. First line of the test case contains an integer N, denoting the number of elements in the array. Then next line contains N space separated integers denoting the elements of the array. The last line of each test case contains an integer K.

Output:
For each test case ouptut a single line denoting the sum of the length of all such subarrays.

Constraints:
1<=T<=100
1<=N<=105
1<=A[]<=105

Example:
Input:
3
9 
2 1 4 9 2 3 8 3 4
4
7
1 2 3 2 3 4 1
4
10
4 5 7 1 2 9 8 4 3 1
4
Output:
5
7
4
Explanation:
Test Case 1:

Input : arr[] = {2, 1, 4, 9, 2, 3, 8, 3, 4} 
        k = 4
Output : 5
{2, 1, 4} => Length = 3
{3, 4} => Length = 2
So, 3 + 2 = 5 is the answer
Test Case 2:

Input : arr[] = {1, 2, 3, 2, 3, 4, 1} 
        k = 4
Output : 7
{1, 2, 3, 2, 3, 4, 1} => Length = 7
Test Case 3:

Input : arr = {4, 5, 7, 1, 2, 9, 8, 4, 3, 1}
        k = 4
Ans = 4
{4} => Length = 1
{4, 3, 1} => Length = 3
So, 1 + 3 = 4 is the answer
**For More Examples Use Expected Output**
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

	int sum = 0,t = 0;
	cin >> t;
	while(t > 0){
		
		t--;
		int n = 0;
		cin >> n;
		vector <int> array(n);

		//accepting array
		for(int i =0;i < n;i++){
			int temp = 0;
			cin >> temp;
			array.at(i) = temp;
		}

		int sum = 0 ,tempsum = 0, k =0, swtch = 0;
		cin >> k;
		for(int i = 0;i<n;i++){
			if(array.at(i) == k) swtch = 1;//Turn on the switch for consideration
			
			if(array.at(i) > k){
				if(swtch){ //swtch-on condition
					sum += tempsum;
				}
				tempsum = 0;
				swtch = 0;
			} else tempsum++;
			//cout << "tempsum:" << tempsum << " sum:" << sum << " switch:" << swtch << endl;
			
		}
		if(swtch) sum += tempsum;
		cout << sum << endl;
	}
	return 0;
}


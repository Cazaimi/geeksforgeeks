/*	
Chocolate Distribution Problem
 
Given an array A[] of N integers where each value represents number of chocolates in a packet. Each packet can have variable number of chocolates. There are m students, the task is to distribute chocolate packets such that :
1. Each student gets one packet.
2. The difference between the number of chocolates given to the students in packet with maximum chocolates and packet with minimum chocolates is minimum.

Examples

Input : A[] = {3, 4, 1, 9, 56, 7, 9, 12} 
        m = 5
Output: Minimum Difference is 6
We may pick 3,4,7,9,9 and the output 
is 9-3 = 6
Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case consists of three lines. The first line of each test case contains an integer N denoting the no of packets. Then in the next line are N space separated values of the array A[] denoting the values of each packet. The third line of each test case contains an integer m denoting the no of students.

Output:
For each test case in a new line print the required answer .

Constraints:
1 <=T<= 100
1 <=N<= 100
1 <=A[]<= 100
1 <=m <=N

Example:
Input:
2
8
3 4 1 9 56 7 9 12
5
7
7 3 2 4 9 12 56
3
Output:
6
2


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int random_function(vector <int> input,int k){
    
    int mini = 9999;
    int n = input.size();
    for(int i = 0;i <= n-k;i++){
        mini = min(mini, input.at(i+k-1) - input.at(i));
        //cout << input.at(i+k-1) << input.at(i) << endl;
    }
    return mini;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	for(int i =0;i < t;i++){
	
	    int n = 0,k = 0;
	    cin >> n;
	    vector <int> input(n);
	    for(int j = 0;j < n;j++){
	        int temp = 0;
	        cin >> temp;
	        input.at(j) = temp;
	    }
	    cin >> k; 
	    
	    std::sort(input.begin(),input.end());
	    
	    cout << random_function(input,k) << endl;
	}
	return 0;
}

/*Pythogorian Triplet

Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of testcases.
Each case begins with a single positive integer N denoting the size of array.
The second line contains the N space separated positive integers denoting the elements of array A.

Output:
For each testcase, print "Yes" or  "No" whtether it is Pythagorean Triplet or not.

Constraints:
1<=T<=50
 1<=N<=100
 1<=A[i]<=100

Example:
Input:
1
5
3 2 4 6 5
Output:
Yes

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int random_function(vector <int> input){
    
    int n = input.size();
    for(int i = n-1;i > -1;i--){
        int c = input.at(i);
        int low = 0; int high = i-1;
        while(low < high){
            int sum = input.at(low) + input.at(high);
            if(sum < c) low++;
            else if(sum > c) high--;
            else if(sum == c) {cout << "Yes"; return 1;}
        }
    }
    
    //If we reached here, it means that we did not find the Triplet.
    cout << "No";
    return 1;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	for(int i = 0;i < t;i++){
	
	    int n = 0;
	    cin >> n;
	    vector <int> input(n);
	    for(int j =0;j < n;j++){
	        int temp = 0;
	        cin >> temp;
	        input.at(j) = temp*temp;
	    }
	    
	    //Sort the array.
	    std::sort(input.begin(),input.end());
	    
	    int temp = random_function(input);cout << endl; 
	}
	return 0;
}

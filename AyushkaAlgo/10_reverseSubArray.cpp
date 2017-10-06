/* 	
Reverse array in groups
   
Given an array, reverse every sub-array formed by consecutive k elements.

Input:

The first line of input contains a s/* 	
Reverse array in groups
   
Given an array, reverse every sub-array formed by consecutive k elements.

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of array.The second line of each test case contains N space separated integers denoting array elements.The third line of each test case consists of an integer K.

Output:
Corresponding to each test case, in a new line, print the modified array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500
1 ≤ A[i] ≤ 500

Example:

Input
1
5
1 2 3 4 5
3

Output
3 2 1 5 4*/

#include <iostream>
#include <vector>
#include <stack>

#define loop(a,n,i,l) for(int i = a;i < n;i=i+l)

using namespace std;

void random_function(vector <int> input, int k){
   
    int n = input.size();
    for(int i = 0;i < n;i+=k){
        stack <int> s;
        for(int j = i;j < i+k and j<n;j++){
            s.push(input.at(j));
            //cout << input.at(j) << " ";
        } 
        //cout << endl;
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        } 
    }
}

int main() {
	//code
	int t = 0;
	cin >> t;
	loop(0,t,o,1){
	
	    int n = 0,k = 0;
	    cin >> n;
	    vector <int> input(n);
	    for(int i = 0;i < n;i++){
	        int temp = 0;
	        cin >> temp;
	        input.at(i) = temp;
	    }
	    cin >> k;
	    //cout << k << n;
	    random_function(input,k);
	    cout << endl;
	}
	return 0;
}ingle integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of array.The second line of each test case contains N space separated integers denoting array elements.The third line of each test case consists of an integer K.

Output:
Corresponding to each test case, in a new line, print the modified array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500
1 ≤ A[i] ≤ 500

Example:

Input
1
5
1 2 3 4 5
3

Output
3 2 1 5 4*/

#include <iostream>
#include <vector>
#include <stack>

#define loop(a,n,i,l) for(int i = a;i < n;i=i+l)

using namespace std;

void random_function(vector <int> input, int k){
   
    int n = input.size();
    for(int i = 0;i < n;i+=k){
        stack <int> s;
        for(int j = i;j < i+k;j<n;j++){
            s.push(input.at(j));
            //cout << input.at(j) << " ";
        } 
        //cout << endl;
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        } 
    }
}

int main() {
	//code
	int t = 0;
	cin >> ta;
	loop(0,t,o,1){
	
	    int n = 0,k = 0;
	    cin >> n;
	    vector <int> input(n);
	    for(int i = 0;i < n;i++){
	        int temp = 0;
	        cin >> temp;
	        input.at(i) = temp;
	    }
	    cin >> k;
	    //cout << k << n;
	    random_function(input,k);
	}
	return 0;
}
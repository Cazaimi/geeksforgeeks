/*
Largest Number formed from an Array

Given a list of non negative integers, arrange them in such a manner that they form the
largest number possible.The result is going to be very large, hence return the result in the form of a string.

Input:

The first line of input consists number of the test cases. The description of T test cases
is as follows:

The first line of each test case contains the size of the array, and the second line has
the elements of the array.


Output:

In each separate line print the largest number formed by arranging the elements
of the array in the form of a string.

Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 1000

Example:

Input:

2
5
3 30 34 5 9
4
54 546 548 60

Output:

9534330
6054854654
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

struct comp{
  bool operator()(string const& X,string const& Y){
      string first = X + Y;
      string second = Y + X;
      
      int firstInt = std::stoi (first,nullptr,10);
      int secondInt = std::stoi(second, nullptr,10);
      
      return firstInt > secondInt;
  }
}myobject ;

int random_function(vector <string> input){

    sort(input.begin(),input.end(),myobject);
    
    loop(i,0,input.size()){
        cout << input.at(i);
    }
    cout << endl;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <string> input(n);
	    loop(i,0,n){
	        cin >> input.at(i);
	    }
	    
	    random_function(input);
	}
	return 0;
}

/* Permutations of a given string

Given a string, print all permutations of a given string.

Input:

The first line of input contains an integer T denoting the number of test cases.
Each test case contains a single string in capital letter.

Output:

Print all permutations of a given string with single space and all permutations should be in lexicographically increasing order.

Constraints:

1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:

Input:
2
ABC

ABSG

Output:
ABC ACB BAC BCA CAB CBA

ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA
*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void print(vector <char> input){
     loop(i,0,input.size()) cout << input.at(i);
     cout << " ";
}

void random_function(vector <char> input){
     int count = 0;
     loop(i,0,input.size()){
          loop(j,i+1,input.size()){
               count++;
               //cout << count << " ";
               vector <char> temp = input;
               swap(temp.at(i),temp.at(j));
               print(temp);
          }
     }
     cout << endl;
}


int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){

	    string input;
	    cin >> input;
         vector <char> charArray(input.size());
         loop(i,0,input.size()){
              charArray.at(i) = input.at(i);
         }
         random_function(charArray);
	}
	return 0;
}

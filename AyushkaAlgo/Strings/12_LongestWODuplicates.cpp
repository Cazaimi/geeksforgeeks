/*Longest Distinct characters in string

Given a string, find length of the longest substring with all distinct characters.  For example, for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is String str.

Output:

Print length of smallest substring with maximum number of distinct characters.
Note: The output substring should have all distinct characters.

Constraints:

1 ≤ T ≤ 100
1 ≤ size of str ≤ 10000

Example:

Input
2
abababcdefababcdab
geeksforgeeks


Output:
6
7*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(string input, int n){
     int start = 0;
     int end = 1;
     int max_length = 1;
     vector <int> hash(26);
     hash.at(input.at(start)-97) = 1;

     while(end < n){

          if(hash.at(input.at(end) -97) == 0){
               hash.at(input.at(end)-97) = 1;
               max_length=max(end-start+1,max_length);
               end++;
          }
          else{
               char repeat = input.at(end);
               while(hash.at(repeat - 97) != 0 and start <= end){
                    hash.at(input.at(start) - 97) = 0;
                    start++;
               }
               max_length=max(end-start,max_length);
               //end++;
          }
     }
     return max_length;

}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
          string input;
          cin >> input;
          cout << random_function(input,input.length()) << endl;
	}
	return 0;
}

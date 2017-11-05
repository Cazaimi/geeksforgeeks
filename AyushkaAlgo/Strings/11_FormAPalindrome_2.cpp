/*Form a palindrome
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(string input, int n){
     vector <int> rptchars;
     int hotspot = 0, hotspot_length = 0;
     //for even palindrome
     loop(i,0,n-1){
          cout << "b";
          if(input.at(i) == input.at(i+1)){
               int end = i+2,start = i;
               start--;
               int where = i;
               while(input.at(start) == input.at(end) and start > -1 and end < n){
                    start--;
                    end++;
                    cout << "a";
               }
               int length = end-start+1-2;
               if(length > hotspot_length){
                    hotspot = where;
                    hotspot_length = length;
               }
          } //rptchars.push(i);
     }
     //for odd palindrome
/*     loop(i,1,n-1){
          if(input.at(i) == input.at(i+1) and input.at(i) == input.at(i-1)){
               int j = i+1;
               i--;
               int where = i;
               while(input.at(i) == input.at(j) and i > -1 and j < n){
                    i++;
                    j--;
               }
               int length = j-i+1;
               if(length > hotspot_length){
                    hotspot = where;
                    hotspot_length = length;
               }
          } //rptchars.push(i);
     }*/

return hotspot_length;

}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){

	    string n;
	    cin >> n;
         cout << random_function(n,n.length()) << endl;
	}
	return 0;
}

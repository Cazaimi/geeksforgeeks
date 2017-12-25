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

#define loop(i,start,end) for(int i = start;i < end;i++)
#define equals ==

using namespace std;

//inserts the string after given position.
string insert(string &a,string tBInserted,int pos){
     return a.substr(0,pos+1) + tBInserted + a.substr(pos+1,a.length()-pos+1);// + a.substr()
}

string inputat(string a, int pos){
     if(pos < a.length())
     return a.substr(pos,1);
     else return "";
}

int random_function(string input,int n){

     int i = 0, j = n-1;
     string OGinput = input;
     while(i < j){
          cout << input << endl;
          if(i equals j-1){
               if(input.at(i) == input.at(j)){
                    i++;
                    j--;
               }
               else {
                    input = insert(input, inputat(input,i) , j);
                    i+= 2;
               }
          }
          else {
               if(input.at(i) equals input.at(j)){
                    i++; j--;//do nothing
               }
               else {
                    input = insert(input, inputat(input,i) , j);
                    input = insert(input, inputat(input,j) , i);
                    i+=2;
               }
          }
     }
     cout << input << endl;
     return input.length() - OGinput.length();
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
     string a = "anmol";
	loop(j,0,t){
	        string input;
             cin >> input;
             cout << random_function(input,input.length()) << endl;
	}
	return 0;
}

/*Difficulty Level: Medium
Longest Common Substring
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

Examples :

Input : X = "GeeksforGeeks", y = "GeeksQuiz"
Output : 5
The longest common substring is "Geeks" and is of
length 5.

Input : X = "abcdxyz", y = "xyzabcd"
Output : 4
The longest common substring is "abcd" and is of
length 4.

Input : X = "zxabcdezy", y = "yzabcdezx"
Output : 6
The longest common substring is "abcdez" and is of
length 6.



Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string X and Y respectively
The next two lines contains the 2 string X and Y.


Output:
For each test case print the length of longest  common substring of the two strings .


Constraints:
1<=T<=200
1<=size(X),size(Y)<=100


Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1
*/
#include <iostream>
#include <vector>
#include <string>

#define loop(i,start,end) for (int i = start; i < end; i++)

using namespace std;

int random_function(string a,string b){
     int n = a.size();
     int m = b.size();

     vector <int> arr[n+1];
     for (int i = 0; i <= n; i++) {
          for (int j = 0; j <= m; j++) {
               arr[i].push_back(0);
          }
     }

     /*loop(i,0,n){
          loop(j,0,m){
               cout << arr[i].at(j) << " ";
          }
          cout << endl;
     }*//
     int maxx = 0;
     loop(i,0,n+1){
          loop(j,0,m+1){
               if(i == 0 or j == 0) arr[i].at(j) = 0;
               else if(a.at(i-1) == b.at(j-1)){
                    arr[i].at(j) = arr[i-1].at(j-1) + 1;
                    maxx = max(maxx,arr[i].at(j));
               }
               else arr[i].at(j) = 0;
          }
     }

     return maxx;

}

int main(){
     int t = 0;
     cin >> t;
     for (int i = 0; i < t; i++) {
          int k,l; cin >> k >> l;
          string a,b;
          cin >> a >> b;
          cout << random_function(a,b) << endl;
     }
}

/*Difficulty Level: Easy
Submissions: 7490 Accuracy:

22.56%
Remove Duplicates




Given a string, remove duplicates from it. Note that original order of characters must be kept same.  Expected time complexity O(n) where n is length of input string and extra space O(1) under the assumption that there are total 256 possible characters in a string.

Input: First line of the input is the number of test cases T. And first line of test case contains a string.

Output:  Modified string without duplicates and same order of characters.

Constraints:  Input String Length <= 1000

Example:
Input:
2
geeksforgeeks
geeks for geeks

Output:
geksfor
geks for*/


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>


#define loop(i,start,end) for (int i = start; i < end; i++)

using namespace std;

void random_function(string input){
     vector <int> hash(27);
     int n = input.length();
     loop(i,0,n){
          char hereAndNow = input.at(i);
          if(hereAndNow == ' '){
               if(hash.at(26) == 0){
                    cout << hereAndNow;
                    hash.at(26) = 1;
               }
               else ;//don't print.
          }
          else if(hash.at(hereAndNow - 97) == 0){
               cout << hereAndNow;
               hash.at(hereAndNow - 97) = 1;
          }
          else{
               ;//don't print.
          }
     }
     cout << endl;
}

int main(){
     int t = 0; string residue;
     cin >> t;
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     loop(i,0,t){
          string input;
          //cin >> input;
          getline(cin,input);
          //cout << input << endl;
          //cin >> input;
          random_function(input);
     }
}

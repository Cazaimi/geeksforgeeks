/*
Largest number possible
Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains two space separated integers N and S, where N is the number of digits and S is the sum.

Output
Print the largest number that is possible.
If their is no such number, then print -1

Constraints:
1 <= T <= 30
1 <= N <= 50
0 <= S <= 500

Example
Input
2
2 9
3 20
Output
90
992
Expected Time Complexity: O(n)*/

#include <iostream>
#include <vector>
#include <cmath>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;

string maxSum(int n, int s){
     if(s == 0) return "-1";
     int i = n-1;
     string sum = "";
     while(i > -1){

          if(s > 9) {
               string temp = "9";
               sum += temp;
               s -= 9;
          }
          else {
               string temp = " ";
               temp.at(0) = s + 48;
               sum += temp;
               s -= s;
          }
          i--;
     }

     if(s != 0) return "-1";
     else return sum;
}

int main(){

     int t = 0;
     cin >> t;
     loop(i,0,t){
          int n = 0, s = 0;
          cin >> n >> s;
          cout << maxSum(n,s) << endl;
     }
}
